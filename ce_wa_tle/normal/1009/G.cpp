#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=2e5+9,mod=1e9+7;typedef ll aN[N];char s[N];ll t[26],cs[N],sum[N][1<<6];
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
    scanf("%s",s);ll n=strlen(s);rfor(char*i=s;*i;i++)t[*i-'a']++;ll m=readll();
    rep(i,1,m){ll x=readll();scanf("%s",s);rfor(char*i=s;*i;i++)cs[x]|=1<<(*i-'a');}
    rep(i,1,n)if(!cs[i])cs[i]=(1<<6)-1;per(i,n,1)ref(j,0,1<<6)sum[i][j]=sum[i+1][j]+!!(cs[i]&j);
    rep(i,1,n){rep(j,0,5)if(cs[i]>>j&1&&t[j]){/*printf("%lld %c",i,(int)j+'a');puts("");*/s[i]=0;t[j]--;ll p=1;
    ref(k,0,1<<6){ll s=sum[i+1][k];rep(l,0,5)if(k>>l&1)s-=t[l];if(s<0){/*printf("%lld %lld\n",i,k);*/p=0;break;}}
    if(p){s[i]=j+'a';break;}t[j]++;}}s[n+1]=0;if((ll)strlen(s+1)!=n)return puts("Impossible"),0;puts(s+1);return 0;
}