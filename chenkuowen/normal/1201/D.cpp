#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=5+2e5;
set<pair<int,int> > a[MAX_N];
set<int> b;
ll f[MAX_N],ans=1e18;
void solve(int x,int pos,ll key){
	auto it=a[x].lower_bound(make_pair(pos,0));
	if(it!=a[x].end()){
		f[it->second]=min(f[it->second],abs(it->first-pos)+key);
	}
	if(it!=a[x].begin()){
		--it;
		f[it->second]=min(f[it->second],abs(it->first-pos)+key);
	}
}
void solve2(int i,int p,int pos,ll key){
	auto it=b.lower_bound(pos);
	if(it!=b.end())
		solve(p,*it,key+p-i+abs(*it-pos));
	if(it!=b.begin()){
		--it;
		solve(p,*it,key+p-i+abs(*it-pos));
	}
}
int main(){
	int n,m,k,q; scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=1;i<=k;++i){
		int x,y; scanf("%d%d",&x,&y);
		a[x].insert(make_pair(y,i));
	}
	for(int i=1;i<=q;++i){
		int x; scanf("%d",&x);
		b.insert(x);
	}
	for(int i=0;i<=k;++i) f[i]=1e18;
	a[1].insert(make_pair(1,0));
	f[0]=0;
	for(int i=1;i<=n;++i){
		for(auto t:a[i]){
			auto it=a[i].end(); --it;
			int x=a[i].begin()->first,y=it->first;
			if(f[t.second]!=1e18){
				int p=i+1;
				while(p<=n&&a[p].empty()) ++p;
				ll key1=f[t.second]+y-x+abs(t.first-x);
				ll key2=f[t.second]+y-x+abs(t.first-y);
				if(p>n) ans=min(ans,min(key1,key2));
				else{
					solve2(i,p,y,key1);
					solve2(i,p,x,key2);
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}