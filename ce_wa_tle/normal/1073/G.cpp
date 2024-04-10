#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define log fdjsf
typedef long long ll;const ll N=4e5+7,mod=998244353;typedef ll aN[N];char s[N];aN log,rk,tp,sa,st[23],a,c,sum,sk,h;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int cmp(ll i,ll j){return a[i]<a[j];}ll getsum(ll i,ll j,ll w){ll res=sum[j]-sum[i-1];return w?res:j-i+1-res;}
ll n,q;ll mi(ll i,ll j){if(i==j)return n-sa[i]+1;ll l=log[j-++i+1];return std::min(st[l][i],st[l][j-(1<<l)+1]);}
ll getans(ll la,ll ra,ll lb,ll rb){return getsum(la,ra,0)*getsum(lb,rb,1)+getsum(la,ra,1)*getsum(lb,rb,0);}
void sort(ll n,ll m,const ll*rk,const ll*tp,ll*sa){static ll a[N];
    memset(a,0,sizeof(ll)*(m+1));rep(i,1,n)a[rk[i]]++;rep(i,1,m)a[i]+=a[i-1];per(i,n,1)sa[a[rk[tp[i]]]--]=tp[i];
}int main(){
    n=readll(),q=readll();scanf("%s",s+1);rep(i,1,n)rk[tp[i]=i]=s[i]-'a'+1;sort(n,26,rk,tp,sa);
    rfor(ll w=1,p=0,m=26;w<=n&&(w==1||m<n);m=p,p=0,w<<=1){
        rep(i,n-w+1,n)tp[++p]=i;rep(i,1,n)if(sa[i]>w)tp[++p]=sa[i]-w;sort(n,m,rk,tp,sa),std::swap(rk,tp);
        p=rk[sa[1]]=1;rep(i,2,n)rk[sa[i]]=tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+w]==tp[sa[i-1]+w]?p:++p;
    }ll p=0;rep(i,1,n)if(rk[i]^1){for(p&&--p;i+p<=n&&s[i+p]==s[sa[rk[i]-1]+p];)++p;st[0][rk[i]]=p;}
    rep(i,2,n)log[i]=log[i>>1]+1;rep(i,1,log[n])rep(j,1,n-(1<<i)+1)st[i][j]=std::min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    rep(i,1,q){
        ll k=readll(),l=readll(),t=-1,res=0;rep(i,1,k)a[c[i]=i]=rk[readll()];rep(i,1,l)a[c[i+k]=i+k]=rk[readll()];
        std::sort(c+1,c+k+l+1,cmp);rep(i,1,k+l+1){sum[i]=sum[i-1]+(c[i]<=k),h[i]=i!=1&&i<=k+l?mi(a[c[i-1]],a[c[i]]):0;
        while(t&&h[i]<h[sk[t]])res+=getans(sk[t],i-1,sk[t-1],sk[t]-1)*h[sk[t]],t--;sk[++t]=i;}printf("%lld\n",res);
    }return 0;
}