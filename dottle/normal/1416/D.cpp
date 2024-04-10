#include<bits/stdc++.h>
const int N=1000005;
using namespace std;

set<int> s[N];
int x[N],y[N],v[N];
int a[N],b[N],ans[N],fa[N];
int n,m,q;
int d[N],t[N],ps[N],fl[N];
vector<int> del[N];

int gf(int k){return k==fa[k]?k:fa[k]=gf(fa[k]);}

void mrg(int x,int y,int i){
	int fx=gf(x),fy=gf(y);
	if(fx!=fy){
		if(s[fx].size()<s[fy].size())swap(fx,fy);
		while(s[fy].size())del[i].push_back(*s[fy].begin()),s[fx].insert(*s[fy].begin()),s[fy].erase(s[fy].begin());
		d[i]=fx,t[i]=fy;
		fa[fy]=fx;
	}
}

void solve(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>v[i],s[i].insert(-v[i]),fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<=q;i++){
		cin>>a[i]>>b[i];
		if(a[i]==2)fl[b[i]]=1;
	}
	for(int i=1;i<=m;i++)
		if(!fl[i])
			mrg(x[i],y[i],q+1);
	for(int i=q;i;i--){
		if(a[i]==2)mrg(x[b[i]],y[b[i]],i);
		else ps[i]=gf(b[i]);
	}
	for(int i=1;i<=q;i++){
		if(a[i]==2){
			for(auto x:del[i])
				if(s[d[i]].count(x))
					s[d[i]].erase(x),s[t[i]].insert(x);
		}
		else {
			if(s[ps[i]].empty()){
				cout<<0<<'\n';
				continue;
			}
			cout<<-*s[ps[i]].begin()<<'\n';
			s[ps[i]].erase(s[ps[i]].begin());
		}
	}
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}