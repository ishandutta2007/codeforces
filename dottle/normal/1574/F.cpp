#include<bits/stdc++.h>
#define int long long
const int N=5000050,mod=998244353;
using namespace std;

map<int,int> a[N];
int fa[N],x,y,ln[N],sz[N],pr,nw,fl[N],l[N],r[N],w[N],f[N];  
int n,m,k;
vector<int> tr; 

int gf(int k){
	return k==fa[k]?k:fa[k]=gf(fa[k]);
}
 
main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)fa[i]=i,sz[i]=fl[i]=1;
	for(int i=1;i<=n;i++){
		cin>>ln[i]>>pr;
		for(int j=2;j<=ln[i];j++,pr=nw) {
			cin>>nw;
			if(a[pr][nw])continue;
			a[pr][nw]=1;
			l[pr]++,r[nw]++;
			int fx=gf(pr),fy=gf(nw);
			if(fx==fy||l[pr]>1||r[pr]>1||l[nw]>1||r[nw]>1)fl[fy]=0;
			fl[fx]&=fl[fy];
			if(fx!=fy)sz[fx]+=sz[fy],fa[fy]=fx;		
		}
	}
	for(int i=1;i<=k;i++)
		if(gf(i)==i&&fl[i])
			w[sz[i]]++;
	for(int i=1;i<=k;i++)
		if(w[i])
			tr.push_back(i);
	f[0]=1;
	for(int i=0;i<=m;i++){
		for(auto k:tr)
			(f[i+k]+=f[i]*w[k])%=mod;
	}
	cout<<f[m];
}