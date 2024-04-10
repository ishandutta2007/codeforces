//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
#define li inline
#define re register
#define ll __int128
#define abs(a) ((a)>0?(a):-(a))
namespace Miller_Rabin
{
	const int Pcnt=12;
	const ll p[Pcnt]={2,3,5,7,11,13,17,19,61,2333,4567,24251};
	li ll pow(re ll a,re ll b,re ll p)
	{
		re ll ans=1;
		for(;b;a=a*a%p,b>>=1)if(b&1)ans=ans*a%p;
		return ans;
	}
	li bool check(re ll x,re ll p)
	{
		if(x%p==0||pow(p%x,x-1,x)^1)return true;
		re ll t,k=x-1;
		while((k^1)&1)
		{
			t=pow(p%x,k>>=1,x);
			if(t^1&&t^x-1)return true;
			if(!(t^x-1))return false;
		}return false;
	}
	inline bool MR(re ll x)
	{
		if(x<2)return false;
		for(re int i=0;i^Pcnt;++i)
		{
			if(!(x^p[i]))return true;
			if(check(x,p[i]))return false;
		}return true;
	}
}
namespace Pollard_Rho
{
	#define Rand(x) (1ll*rand()*rand()%(x)+1)
	li ll gcd(const ll a,const ll b){return b?gcd(b,a%b):a;}
	li ll mul(const re ll x,const re ll y,const re ll X)
	{
		ll k=(1.0L*x*y)/(1.0L*X)-1,t=x*y-k*X;
		while(t<0)t+=X;return t;
	}
	li ll PR(const re ll x,const re ll y)
	{
		re int t=0,k=1;re ll v0=Rand(x-1),v=v0,d,s=1;
		while(true)
		{
			v=(mul(v,v,x)+y)%x,s=mul(s,abs(v-v0),x);
			if(!(v^v0)||!s)return x;
			if(++t==k){if((d=gcd(s,x))^1)return d;v0=v,k<<=1;}
		}
	}
	li void Resolve(re ll x,re ll&ans)
	{
		if(!(x^1)||x<=ans)return;
		if(Miller_Rabin::MR(x)){if(ans<x)ans=x;return;}
		re ll y=x;while((y=PR(x,Rand(x)))==x);while(!(x%y))x/=y;
		Resolve(x,ans);Resolve(y,ans);
	}
	li long long check(ll x)
	{
		re ll ans=0;Resolve(x,ans);
		return ans;
	}
}
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int p[100030],cnt=0;
bool vis[200003];
void init(int n=200000)
{
    for(int i=2; i<=n; ++i) if(!vis[i])
    {
        p[++cnt]=i;
        for(int j=2; i*j<=n; ++j) vis[i*j]=1;
    }
    //printf("%lld\n",cnt);
    return ;
}
int a[100003];
int f[103][103];
bool t[100003];
int query(int x,int y){
    printf("? %lld %lld\n",x,y);
    fflush(stdout);
    return read();
}
int Lcm(int x,int y){
    return x/__gcd(x,y)*y;
}
signed main()
{
    init();
	for(int T=read();T--;)
	{
		int n=read();
        if(n<=90)
        {
            for(int i=1; i<=n; ++i) t[i]=0;
            for(int i=1; i<n; ++i)
                for(int j=i+1; j<=n; ++j)
                    f[i][j]=f[j][i]=query(i,j);
            int s=-1,A=0,B=0;
            for(int i=1; i<n; ++i)
                for(int j=i+1; j<=n; ++j)
                    if(f[i][j]>s) s=f[i][j],A=i,B=j;
            int r=(sqrt(s*4+1)+1)/2,l=r-n+1;
            multiset<int> s1,s2,s3;
            for(int i=l; i<=r-2; ++i) s3.insert(Lcm(i,r));
            for(int i=1; i<=n; ++i) if(i!=A&&i!=B) s1.insert(f[i][A]);
            for(int i=1; i<=n; ++i) if(i!=A&&i!=B) s2.insert(f[i][B]);
            assert(s1!=s2);
            int pos,val=r-1;
            if(s1==s3) a[A]=r,a[B]=r-1,pos=B;
            else a[A]=r-1,a[B]=r,pos=A;
            t[A]=t[B]=1;
            while(val>l)
            {
                for(int i=1; i<=n; ++i) if(!t[i]&&f[i][pos]==val*(val-1))
                {
                    a[i]=val-1;
                    t[i]=1;
                    pos=i;
                    break;
                }
                --val;
            }
        }
        else
        {
            mt19937 rnd(time(0));
            int A=0,B=0,C=0,D=0;
            for(int i=1; i<=4900; ++i)
            {
                int x=rnd()%n+1,y=rnd()%n+1;
                while(x==y)
                {
                    x=rnd()%n+1,y=rnd()%n+1;
                }
                int g=query(x,y),q=Pollard_Rho::check(g);
                if(q>D) D=q,C=g,A=x,B=y;
            }
            //C is lcm,D is the largest d
            int ano=rnd()%n+1;
            while(ano==A||ano==B) ano=rnd()%n+1;
            int tmp=query(ano,A),va,vb,qqq;
            if(tmp%D==0)
            {
                va=D,vb=C/D,qqq=A;
            }
            else va=C/D,vb=D,qqq=B;
            for(int i=1; i<=n; ++i)
            {
                if(A==i)
                {
                    a[i]=va;
                }
                else if(B==i)
                {
                    a[i]=vb;
                }
                else
                {
                    if(qqq==A) a[i]=query(i,A)/D;
                    else a[i]=query(i,B)/D;
                }
            }
        }
        printf("! ");
        for(int i=1; i<=n; ++i) printf("%lld ",a[i]);
        puts("");
        fflush(stdout);
	}
	return 0;
}