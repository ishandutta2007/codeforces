#include<bits/stdc++.h>
using namespace std;
const int N=5+2e5;
vector<int> f[N];
int b[N],a[N];
void add_ring(vector<int> a){
	vector<int> s(a.size());
	for(int i=0;i<a.size();++i){
		s[i]=f[a[i]].back();
		f[a[i]].pop_back();
	}
	for(int i=0;i<a.size();++i)
		b[s[i]]=a[(i+1)%a.size()];
}
bool cmp(int x,int y){ return f[x].size()>f[y].size(); }
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		for(int i=1;i<=n;++i) f[i].clear();
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),f[a[i]].push_back(i);
		vector<int> q;
		for(int i=1;i<=n;++i) 
			if(f[i].size()>0) q.push_back(i);
		sort(q.begin(),q.end(),cmp);
		while(!q.empty()){
			if(f[q.back()].empty()){
				q.pop_back();
				continue;
			}
			add_ring(q);
		}
		for(int i=1;i<=n;++i) printf("%d ",b[i]); puts("");
	}
	return 0;
}