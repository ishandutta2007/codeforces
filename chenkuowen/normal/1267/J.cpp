#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> PII;
typedef pair<ll,ll> Pll;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef pair<ll,ll>P;
#define N  2000000+10
#define M  200000+10
#define INF 1e9
#define fi first
#define se second
#define MP make_pair
#define pb push_back
#define pi acos(-1)
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define per(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define lowbit(x) x&(-x)
#define Rand (rand()*(1<<16)+rand())
#define id(x) ((x)<=B?(x):m-n/(x)+1)
#define ls p<<1
#define rs p<<1|1
#define fors(i) for(auto i:e[x]) if(i!=p)

const int MOD=998244353,inv2=(MOD+1)/2;
      int p=1e4+7;
      //double eps=1e-6;
      int dx[4]={-1,1,0,0};
      int dy[4]={0,0,-1,1};

ll dis[N];
int a[N],b[N],m,mx;

int read()
{
   int v=0,f=1;
   char c=getchar();
   while(c<48||57<c) {if(c=='-') f=-1; c=getchar();}
   while(48<=c&&c<=57) v=(v<<3)+v+v+c-48,c=getchar();
   return v*f;
}

ll readll()
{
   ll v=0,f=1;
   char c=getchar();
   while(c<48||57<c) {if(c=='-') f=-1; c=getchar();}
   while(48<=c&&c<=57) v=(v<<3)+v+v+c-48,c=getchar();
   return v*f;
}

ll calc(int K)
{
    ll res=0;
    if(K==1)
    {
        rep(i,1,m) res+=b[i];
        return res;
    }

    rep(i,1,m)
    {
        int k=b[i]/K;
        if(k*K<b[i]) k++;
        int r=k*K-b[i];
        if(k<r) return 4e9;
        res+=k;
    }

    //printf("K=%d res=%I64d\n",K,res);
    return res;
}

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int cas=read();
    while(cas--)
    {
        int n=read();
        rep(i,1,n) a[i]=read();
        sort(a+1,a+n+1);
        int s=1;
        m=0;
        rep(i,2,n)
         if(a[i]==a[i-1]) s++;
          else
          {
              m++; b[m]=s;
              s=1;
          }
        m++; b[m]=s;
        mx=0;
        rep(i,1,m) mx=max(mx,b[i]);
        int r=INF;
        ll ans=4e9;
        rep(i,1,m) r=min(r,b[i]);
        r++;
        rep(i,1,r) ans=min(ans,calc(i));
        printf("%I64d\n",ans);
    }
    return 0;
}