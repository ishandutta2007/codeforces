#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=2916333,e7=1e7+7,inf=1e17;typedef ll aN[N];char s1[N],s2[N],s3[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
void reads(char*s,int l='0',int r='z'){*s=readchar(l,r);while(*++s=getchar(),*s>=l&&*s<=r);*s=0;}
int main(){
    ll n=readll();reads(s1),reads(s2);if(*s1^*s2){rep(i,1,n)putchar(49);return 0;}
    if(s2[n-1]^49&&n!=1){ll now=n-1;strcpy(s3,s2);while(49^s3[now])s3[now--]=1;s3[now]=0;s2[n-1]^=strcmp(s3,s1)>0;}
    puts(s2);return 0;
}