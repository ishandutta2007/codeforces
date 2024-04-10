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
char s[514514];
ll l[114];
void get(ll S){
    std::cout<<"next";
    rep(i,0,9)if(S>>i&1)std::cout<<' '<<i;std::cout<<std::endl;
//    fflush(stdout);
//    gets(s);
    ll n=0,t=0;
    char ch=getchar();while(ch!='\n')s[n++]=ch,ch=getchar();
    ref(i,0,n)if(s[i]==' ')++t;else l[s[i]^48]=t;
}
#define x0 1
#define x1 2
#define x2 4
#define x3 ((1<<10)-8)
int main(){
//    std::cout<<"next 1 2"<<std::endl;
//    get(x0|x1);
    do get(x0|x1),get(x1);while(l[0]!=l[1]);
    do get(x0|x2);while(l[0]!=l[1]);
    while(l[2]!=l[3])get(x2|x3);
    while(l[0]!=l[3])get(x0|x1);
    std::cout<<"done"<<std::endl;
	return 0;
}