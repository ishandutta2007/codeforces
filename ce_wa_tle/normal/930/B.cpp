#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=414514,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;char c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(){char c=getchar();for(;c<'A'||c>'z';c=getchar());return c;}
char s[5555];ll t[27][28][5555];
int main(){
    scanf("%s",s+1);ll n=strlen(s+1),ans=0;rep(i,1,n)rep(j,1,n)t[s[i]-'a'][s[j]-'a'][(j-i+1+n)%n+1]++;
    rep(i,1,n)rep(j,1,n)if(t[s[i]-'a'][s[j]-'a'][(j-i+1+n)%n+1]==1)t[s[i]-'a'][27][(j-i+1+n)%n+1]++;
    rep(i,0,26){ll max=0;rep(j,1,n)max=std::max(max,t[i][27][j]);ans+=max;}printf("%.15lf\n",ans/1.0/n);
	return 0;
}/*printf("%lld\n",max);*/