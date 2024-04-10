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
#define N  200000+10
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

int a[110][110],flag[110];
VI c;

struct node
{
    int x,y;
}b[110];

bool cmp(node a,node b)
{
    return a.x<b.x;
}

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

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int n=read(),m=read();
    rep(i,1,m)
     rep(j,1,n) a[i][j]=read();
    int ans=m;
    c.clear();
    rep(i,1,m) c.pb(i);
    rep(i,1,n-1)
    {
        int s=0,t=0;
        rep(j,1,m)
        {
            b[j].x=a[j][i]-a[j][n];
            b[j].y=j;
            s+=b[j].x;
        }
        sort(b+1,b+m+1,cmp);
        rep(j,1,m) flag[j]=0;
        rep(j,1,m)
         if(s<0)
         {
             t++;
             s-=b[j].x;
             flag[j]=1;
         }
        //printf("i=%d s=%d t=%d\n",i,s,t);
        if(s>=0)
        {
            if(t<ans)
            {
                ans=t;
                c.clear();
                rep(j,1,m)
                 if(flag[j]) c.pb(b[j].y);
            }
        }
    }
    printf("%d\n",ans);
    for(int i=0;i<c.size();i++) printf("%d ",c[i]);
    return 0;
}