#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=2916333,e7=1e7+7,inf=1e17;typedef ll aN[N];aN col,a,z;ll n,x,y,t,cnt=0;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
#define fl fflush(stdout)
aN head,next,to;void add(ll u,ll v){/*printf("%lld %lld\n",u,v);*/next[++cnt]=head[u],to[head[u]=cnt]=v;}
void dfs(ll u,ll c){col[u]=c;rfor(ll i=head[u];i;i=next[i])if(!~col[to[i]])dfs(to[i],c^1);}
int main(){
    if(((n=readll())&1)^1){
        puts("First"),fl;ll s=n/2*2;rep(i,1,2*n)printf("%lld ",(i-1)%s+1);puts(""),fl;
    }else{
        puts("Second"),fl;rep(i,1,2*n)z[i]=readll(),a[z[i]]^=i,col[i]=-1;
        rep(i,1,2*n)add(i,i<=n?i+n:i-n),add(i,a[z[i]]^i);rep(i,1,n*2)if(!~col[i])dfs(i,0);//rep(i,1,2*n)printf("%lld ",col[i]);puts("");
        ll sum=0;rep(i,1,n*2)if(!col[i])sum+=i;ll p=!!(sum%(2*n));rep(i,1,n*2)if(col[i]==p)printf("%lld ",i);puts(""),fl;
    }return 0;
}
/*
//a=2f
2
1,3 2,4
6
1,7 2,8 3,9 4,10 5,11 6,12
//4k+2 -> choose 1
4
1,5 2,6 3,7 4,8//2n=8
//ax1+1+ax2+2+ax3+3+...+ax4+a=a^2s+a(a+1)/2
//a=2f   (4f(fs)+f(2f+1))%4f=(2f^2+f)%4f
//f=2d   (8d(d)+2d)%8d=2d  != 0
//f=2d+1 ans%2=1           != 0
//a=2f   ans               != 0

//a=2f+1
//%a=...
//a*a%2a=a
////a=2f+1
//1
//1,(2)
//3
//5,1 6,2 ,1
//2,1 3,2 3,1
//0 1 0 1 1 0
//5
//1,(3) 2,(4) 5,(7) (6),8 9,(10)
//(1),9 (2),8 (3),7 (4),6 5,(10)
//
////a=4f+3
////a*(a+1)/2=(k*a+(4f+3)2f)%2(4f+3)
////1,a 2,a+1 3,a+2 ... a-1,2a-2 (2a-1),(2a)
////(k(a-1)+a(a-1)/2)%2a=-k(0<=k<=4f+2)+(4f+3)(2f+1)%2(4f+3)=4f+3-k!=0
////a=4f+3  ans              //

////a=4f+1
//%a=1,1 2,3 2,4 3,4 0,0
////a*(a+1)/2=(4f+1)(2f+1)
*/