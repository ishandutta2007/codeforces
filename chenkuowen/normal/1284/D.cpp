#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+2e5;
vector<int> k1,k2;
struct Key{ int l1,r1,l2,r2; }a[MAX_N];
bool flag=0;
vector<int> g[MAX_N],f[MAX_N];
void solve(int n){
	vector<int> k; k.clear();
	for(int i=1;i<=n;++i){
		k.push_back(a[i].l1);
		k.push_back(a[i].r1);
	}
	sort(k.begin(),k.end());
	k.erase(unique(k.begin(),k.end()),k.end());
	for(int i=1;i<=k.size();++i) f[i].clear(),g[i].clear();
	for(int i=1;i<=n;++i){
		a[i].l1=lower_bound(k.begin(),k.end(),a[i].l1)-k.begin()+1;
		a[i].r1=lower_bound(k.begin(),k.end(),a[i].r1)-k.begin()+1;
		f[a[i].l1].push_back(i);
		g[a[i].r1].push_back(i);
	}
	multiset<int> s1,s2; s1.clear(); s2.clear();
	for(int i=1;i<=k.size();++i){
		for(auto x:f[i]){
			s1.insert(a[x].l2);
			s2.insert(a[x].r2);
		}
//		for(auto t:s1) printf("|%d|",t); puts("");
//		for(auto t:s2) printf("{%d}",t); puts("");
		if((*prev(s1.end()))>(*s2.begin())){
			flag=1;
			return;
		}
		for(auto x:g[i]){
			s1.erase(s1.find(a[x].l2));
			s2.erase(s2.find(a[x].r2));
		}
	}
}
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d%d%d",&a[i].l1,&a[i].r1,&a[i].l2,&a[i].r2);
	solve(n);
	for(int i=1;i<=n;++i){
		swap(a[i].l1,a[i].l2);
		swap(a[i].r1,a[i].r2);
	}
//	exit(0);
	solve(n);
	if(flag) puts("NO");
	else puts("YES");
	return 0;
}