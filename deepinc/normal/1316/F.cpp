#include<cstdio>
const int mod=1e9+7,S=1e7,i2=5e8+4,s=3e5+2;
int a[s],n,m,pw[s],ip[s],sz[S],v[S],lv[S],rv[S],rt,Lc[S],Rc[S],spw[s],sip[s],ssip[s],pc;
int mo(int x){return x>=mod?x-mod:x;}
#define lc Lc[p]
#define rc Rc[p]
#define md (L+R>>1)
void add(int x,int d,int&p=rt,int L=1,int R=1000000000){
	if(!p)p=++pc;
	if(L==R){
		sz[p]+=d;
		if(!sz[p])v[p]=lv[p]=rv[p]=0;
		else v[p]=1ll*L*L%mod*ssip[sz[p]-1]%mod*i2%mod,
			lv[p]=1ll*L*spw[sz[p]-1]%mod,
			rv[p]=1ll*L*sip[sz[p]]%mod;
		return;
	}
	if(x<=md)add(x,d,lc,L,md);else add(x,d,rc,md+1,R);
	sz[p]=sz[lc]+sz[rc];
	v[p]=(v[lc]+v[rc]+1ll*lv[lc]*rv[rc]%mod*ip[sz[lc]])%mod;
	lv[p]=(lv[lc]+lv[rc]*1ll*pw[sz[lc]])%mod;
	rv[p]=(rv[lc]+rv[rc]*1ll*ip[sz[lc]])%mod;
}
int main(){
	scanf("%d",&n);
	for(int i=pw[0]=ip[0]=spw[0]=1;i<=n;++i)
		pw[i]=mo(pw[i-1]<<1),
		ip[i]=ip[i-1]*1ll*i2%mod,
		spw[i]=mo(spw[i-1]+pw[i]),
		sip[i]=mo(sip[i-1]+ip[i]),
		ssip[i]=mo(ssip[i-1]+sip[i]);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),add(a[i],1);
	printf("%d\n",v[1]); scanf("%d",&m);
	for(int i=1,p,w;i<=m;++i)scanf("%d%d",&p,&w),add(a[p],-1),add(a[p]=w,1),printf("%d\n",v[1]);
}