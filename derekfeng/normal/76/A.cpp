#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
int f[203],n,m,G,S;
ll ans=3e18;
int u[50003],v[50003],g[50003],c[50003],ord[50003];
vector<pair<int,pii> >vec,curv;
bool cmp(int A,int B){
	if(g[A]!=g[B])return g[A]<g[B];
	return c[A]<c[B];
}
int F(int x){return f[x]==x?x:f[x]=F(f[x]);}
int main(){
	scanf("%d%d%d%d",&n,&m,&G,&S);
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&u[i],&v[i],&g[i],&c[i]);
		ord[i]=i;
	}
	sort(ord,ord+m,cmp);
	for(int i=0;i<m;i++){
		int j,x=ord[i];
		pair<int,pii>tmp=mkp(c[x],mkp(u[x],v[x]));
		vec.insert(lower_bound(vec.begin(),vec.end(),tmp),tmp);
		curv.clear(); 
		for(j=1;j<=n;j++)f[j]=j;
		int cur=n;
		for(j=0;j<vec.size();j++){
			int U=vec[j].se.fi,V=vec[j].se.se;
			U=F(U),V=F(V);
			if(U==V)continue;
			curv.push_back(vec[j]);
			f[U]=V,cur--;
			if(cur==1){
				ans=min(ans,1ll*g[x]*G+1ll*vec[j].fi*S);
				break;
			}
		}
		vec=curv;
	}
	if(ans<3e18)printf("%I64d",ans);
	else puts("-1");
}