#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define ll long long
const int N=1e5+4;
int n,m,k,fa[N],d[N],w[N];
map<int,ll>f[N]; 
int main(){
	n=read();m=read();k=read();
	for(int i=2;i<=n;i++)fa[i]=read();
	while(m--){int x=read();d[x]=read();w[x]=read();}
	for(int i=n,nw;i>1;i--){
		if(w[i]){
			f[i][d[i]]+=w[i];
			nw=w[i];
			auto t=f[i].upper_bound(d[i]);
			while(t!=f[i].end()){
				if(t->second<=nw)
					nw-=t->second;
				else{t->second-=nw;break;}
				t=f[i].erase(t);
			}
		}
		if(f[i].size()>f[fa[i]].size())swap(f[i],f[fa[i]]);
		for(auto v:f[i])
			f[fa[i]][v.first]+=v.second;
	}
	ll ans=0;
	for(auto t:f[1])
	ans+=t.second;
	cout<<ans;
	return (0-0);
}