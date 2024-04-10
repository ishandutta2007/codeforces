#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=2e6+9;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll query(const char*s){puts(s),fflush(stdout);ll x=readll();if(x<=0)exit(0);return x;}char s[114514];
int main(){
    ref(i,0,300)s[i]='a';ll sa=300-query(s);ref(i,0,300)s[i]='b';ll sb=300-query(s);
    ll n=sa+sb;ref(i,0,n)s[i]='a';s[n]=0;ll now=sb,lst=now;
    ref(i,0,n-1){s[i]='b';if((now=query(s))>=lst)s[i]='a';sb-=s[i]=='b';lst=now;}
    s[n-1]=sb?'b':'a';query(s);return 0;
}