#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=716333,inf=1e17,mod=998244353;typedef ll aN[N];ll mv=0,last=0,x,p[145],w[145],used[145];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll move(ll u,ll c){if(!u)mv+=c;printf("? %lld %lld\n",u,c),fflush(stdout);return x=readll()-last,last+=x,x;}
int main(){
    ll n=readll(),m=readll(),lst,now,nm=n*m;ref(i,1,n)w[i]=-114514;
    ref(t,1,n){
        for(move(0,-1),lst=-114514;now=move(0,1),lst==-114514||!(now!=1&&lst==1);lst=now);move(0,-1);
        ll cnt=0,ans=0;ref(i,1,n)if(w[i]==-114514)used[p[++cnt]=i]=0;ll l=1,r=cnt;
        while(l<r){ll mid=(l+r)>>1;
            rep(i,l,mid)if(!used[p[i]])move(p[i],-1),used[p[i]]=1;
            rep(i,mid+1,r)if(used[p[i]])move(p[i],1),used[p[i]]=0;
            if(move(0,-1)!=-1)r=mid;else l=mid+1;move(0,1);
        }if(!used[ans=p[l]])move(ans,-1);rep(i,1,m)move(ans,-1);w[ans]=mv-m-1;
    }printf("!");rep(i,1,n)printf(" %lld",((w[i]-mv)%nm+nm)%nm);puts("");return 0;
}