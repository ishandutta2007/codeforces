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
      //int p=1e4+7;
      //double eps=1e-6;
      int dx[4]={-1,1,0,0};
      int dy[4]={0,0,-1,1};

char s[2000010];
char c[1100][1100];
int d[1100],a[30],p[1100];


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
    int n=read(),l=read(),k=read();
    scanf("%s",s+1);
    rep(i,0,25) a[i]=0;
    rep(i,1,n*l) a[s[i]-'a']++;
    int now=0;
    if(k>1)
    {
        rep(i,1,l)
        {
            rep(j,1,k)
             if(!p[j])
             {
                while(a[now]==0) now++;
                a[now]--;
                d[j]++;
                c[j][d[j]]=now+'a';
             }
            int flag=1;
            rep(j,1,k-1)
             if(c[j][i]!=c[k][i]) p[j]=1;
            rep(j,1,i)
             if(c[k-1][j]!=c[k][j]){flag=0; break;}
            if(!flag)
            {
                while(d[k]<l)
                {
                    while(a[now]==0) now++;
                    a[now]--;
                    d[k]++;
                    c[k][d[k]]=now+'a';
                }
            }
            if(!flag) break;
        }
    }
    rep(i,1,n)
    {
        while(d[i]<l)
        {
            while(a[now]==0) now++;
            a[now]--;
            d[i]++;
            c[i][d[i]]=now+'a';
        }
    }
    rep(i,1,n)
    {
        rep(j,1,l) printf("%c",c[i][j]);
        printf("\n");
    }
    return 0;
}