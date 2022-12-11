#include<cstdio>
#define ll long long
const int S=3333333,mod=998244353;
ll max(ll a,ll b){return a>b?a:b;}
int n,pc,rt,nt[S],lc[S],rc[S],ca,cb,ans;ll la[S],ra[S],lb[S],rb[S];
int fir[S],l[S],ec;ll X[S],L[S];
#define md (L+R>>1)
void ins(int&p,ll l,ll r,ll L=0,ll R=(1ll<<60)-1){
	if(!p)p=++pc,nt[p]=0; if(nt[p])return;
	if(l<=L&&R<=r){nt[p]=1;;return;}
	if(l<=md)ins(lc[p],l,r,L,md);
	if(r>md)ins(rc[p],l,r,md+1,R);
	nt[p]=nt[lc[p]]&nt[rc[p]];
}
void dfs(ll*l,ll*r,int&c,int p,ll L=0,ll R=(1ll<<60)-1){
	if(nt[p]){l[++c]=L;r[c]=R;L%=mod;R%=mod;ans=(ans+(R-L+1ll)*(L+R)/2)%mod;return;}
	if(lc[p])dfs(l,r,c,lc[p],L,md);
	if(rc[p])dfs(l,r,c,rc[p],md+1,R);
}
bool find(ll x,ll p){
	ll r=((x*1333+p)%S+S)%S;
	for(int i=fir[r];i;i=l[i])if(X[i]==x&&L[i]==p)return 1;
	l[++ec]=fir[r];fir[r]=ec;X[ec]=x;L[ec]=p;return 0;
}
int main(){
	scanf("%d",&n); for(ll i=1,l,r;i<=n;++i)scanf("%lld%lld",&l,&r),ins(rt,l,r);
	dfs(la,ra,ca,rt); for(int i=1;i<=pc;++i)lc[i]=rc[i]=nt[i]=0; pc=rt=ans=0;
	scanf("%d",&n); for(ll i=1,l,r;i<=n;++i)scanf("%lld%lld",&l,&r),ins(rt,l,r);
	dfs(lb,rb,cb,rt); for(int i=1;i<=pc;++i)lc[i]=rc[i]=nt[i]=0; pc=rt=ans=0;
	for(int i=1;i<=ca;++i)for(int j=1;j<=cb;++j){
		ll x=la[i],y=lb[j],len=max(ra[i]-la[i],rb[j]-lb[j]);
		x^=x&len;y^=y&len;
		if(!find(x^y,len))ins(rt,x^y,(x^y)+len);
	}dfs(la,ra,ca,rt);
	printf("%d",(ans+mod)%mod);
}