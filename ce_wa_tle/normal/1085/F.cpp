#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=216333,e7=1e7+7,inf=1e17;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct qj{ll l,r;};qj operator&(const qj&a,const qj&b){return(qj){std::max(a.l,b.l),std::min(a.r,b.r)};}
struct bit{
    aN f;ll sum,n;void clear(ll x){n=x,sum=0,memset(f,0,sizeof f);}
    void update(ll u,ll c){sum+=c;while(u<=n)f[u]+=c,u+=u&-u;}
    ll query(ll u)const{ll res=0;while(u)res+=f[u],u&=~-u;return res;}
    ll query(qj b)const{b=b&(qj){1,n};return b.l<=b.r?query(b.r)-query(b.l-1):0;}
    ll min()const{ll u=0;rfor(ll i=1<<20;i;i>>=1)if(i+u<=n&&!f[i+u])u+=i;return u+1;}
    ll max()const{ll u=0,s=sum;rfor(ll i=1<<20;i;i>>=1)if(i+u<=n&&f[i+u]<s)s-=f[u+=i];return u+!!sum;}
}s[3];ll t[1145],a[1145141],n,m;
void solve(){/*(n==1000)&&printf("[%lld,%lld]=%lld\n",b.l,b.r,b.l<=b.r?query(b.r)-query(b.l-1):0);*/
//    rep(i,0,2){rep(j,1,n)printf("%lld",s[i].query(j)-s[i].query(j-1));puts("");}
    ll sum=0;qj q,h;rep(i,0,2)sum+=
        s[i].query(q=(qj){s[(i+1)%3].min(),s[(i+2)%3].min()-1})+
        s[i].query(h=(qj){s[(i+2)%3].max()+1,s[(i+1)%3].max()}),sum-=s[i].query(q&h)/*,(n==1000)&&printf("%lld\n",sum)*/;
    printf("%lld\n",n-sum);
};
int main(){
    t['P']=1,t['R']=0,t['S']=2,n=readll(),m=readll();
    s[0].clear(n),s[1].clear(n),s[2].clear(n);ll x,c;rep(i,1,n)s[a[i]=t[readchar()]].update(i,1);
//    if(n==1000)rep(i,n-50,n)putchar("RPS"[a[i]]);puts("");
    solve();rep(i,1,m)x=readll(),c=readchar(),s[a[x]].update(x,-1),s[a[x]=t[c]].update(x,1),solve();return 0;
}
/*
10 0
PPRSRRRRPS
*/