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
char s[514514],t_[514514],*t=t_;ll next[514514];
int main(){
//    IO(5);
    scanf("%s%s",s+1,t+1);
    ll m=strlen(s+1),n=strlen(t+1);
    ll f=0,j=0;rep(i,1,m)if(s[i]^48)f++;
    rep(i,2,n){
        while(j&&t[i]^t[j+1])j=next[j];
        next[i]=j+=t[i]==t[j+1];
//        printf("%lld\n",j);
    }
    ll ss=n-next[n],s1=f,s0=m-f,now=0;
    ll x=0;rep(i,1,next[n])if(t[i]^48)x++;if(x>s1||next[n]-x>s0)return puts(s+1),0;
    s1-=x,s0-=next[n]-x;
    rep(i,1,next[n])putchar(t[i]);t+=next[n];
//    printf("s=%lld %lld %lld\n",next[n],s0,s1);
    rep(i,next[n]+1,m){
        now++==ss&&(now=1);
        if(s1&&t[now]=='1')putchar('1'),s1--;
        else if(s0&&t[now]=='0')putchar('0'),s0--;
        else putchar(s0?s0--,'0':(s1--,'1'));
    }
	return 0;
}
/*
111000
101
*/