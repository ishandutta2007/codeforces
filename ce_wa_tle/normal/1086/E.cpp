#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=216333,e7=1e7+7,inf=1e17,mod=998244353;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll cl(ll u){return u<=0?0:1;}
struct bit{
    aN a,f;ll size,n;char ch;void clear(ll x){n=x,size=0,memset(a,0,sizeof(ll)*(n+1)),memset(f,0,sizeof(ll)*(n+1));}
    void update(ll u,ll c){
        if(cl(a[u]+c)==cl(a[u])){a[u]+=c;return;}size+=c=cl(a[u]+=c)?1:-1;while(u&&u<=n)f[u]+=c,u+=u&-u;
    }ll query(ll u)const{ll res=0;while(u)res+=f[u],u&=~-u;return res;}
    ll mq(ll u,ll q)const{return(query(u)-(q&&q<=u&&cl(a[q])))%mod;}
    void full(ll n){clear(n);rep(i,1,n)a[i]=1,f[i]=i&-i;size=n;}
}s,t;ll a[2555][2555],f[2555][2555];
ll pow(ll a,ll b,ll p){ll res=1;while(b){if(b&1)res=res*a%p;a=a*a%p,b>>=1;}return res;}
int main(){
    ll n=readll(),s1,s2,x,ans=0;rep(i,1,n)rep(j,1,n)a[i][j]=readll();f[0][0]=1;
    rfor(ll i=1,j;j=1,i<=n;i++)for(f[i][0]=f[i-1][0]*i%mod;j<=i;j++)f[i][j]=(f[i][j-1]+mod-f[i-1][j-1])%mod;
    rfor(ll i=1,sum;s.full(n),t.clear(n),sum=0,i<=n;ans=(ans+sum*pow(f[n][n],n-i++,mod))%mod)rep(j,1,n)
    t.update(a[i-1][j],1),s1=t.mq(a[i][j]-1,a[i-1][j]),s2=s.mq(a[i][j]-1,a[i-1][j])-s1,x=i>1?t.size:n-j
    ,sum=(sum+(n-j-x+1>=0?s1*f[n-j][n-j-x+1]:0)+(n-j-x>=0?s2*f[n-j][n-j-x]:0))%mod,t.update(a[i][j],-inf)
    ,s.update(a[i][j],-1);printf("%lld\n",ans);return 0;
}
//A=
//1 2 3 4 5
//3 1 5 2 4
//B=
//1 2 3 4 5
//3 1 x y y
//x in {1,2,3,4}(<=A[i][j])&{1,2,4,5}(!=A[i-1][j])&{2,4,5}(!=A[i][k(k<j))
//ans+=f[n-j][n-j-(j-|{1,2,3}&{3,1,x}|)]
//1. x in{1,2}(A[i-1][k(k<j)] ans+=f[n-j][n-j-j+|{1,2,3}&{3,1}|+1]
//2. x in{4,5}(A[i-1][k(k>j)] ans+=f[n-j][n-j-j+|{1,2,3}&{3,1}|]
//T = {x|x!=A[i][k(k<j)}&{x|x=A[i-1][k(k<=j)]}
//S = {x|x!=A[i][k(k<j)}
//x in {x|x!=A[i-1][j]}&S&[1..A[i][j]-1]  -> s=s.query(A[i][j]-1)-s.a[A[i-1][j]]
//x1 in {x|x!=A[i-1][j]}&T&[1..A[i][j]-1] -> s1=t.query(A[i][j]-1)-t.a[A[i-1][j]]
//x2 in S&[1..A[i][j]-1]\T&[1..A[i][j]-1] -> s2=s-s1
//{1,2,3}\{3,1}={1,2,3}&{1,2,4,5} = T.size
/*
2
1 2
2 1
5
1 2 3 4 5
2 1 4 5 3
1 2 3 4 5
2 1 4 5 3
1 2 5 3 4
5
1 4 2 3 5
5 1 3 4 2
3 2 4 1 5
1 4 5 3 2
5 2 3 4 1
*/