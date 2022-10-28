#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define fi first
#define se second
#define N 1000005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
LL ksm(LL a,LL b)
{
    LL c=1,d=a;
    while(b)
    {
        if(b&1)
            c=(c*d)%P;
        d=(d*d)%P;
        b>>=1;
    }
    return c;
}

int sum[N],jc[N],njc[N],cf[N],ans,k;

inline int C(int n,int m)
{
    if(n<m) return 0;
    return (LL)jc[n]*njc[n-m]%P*njc[m]%P;
}

void init()
{
    int i,j;
    for(i=1;i<=1000000;i++)
    {
        sum[i]+=i;
        for(j=i+i;j<=1000000;j+=i)
            sum[j]-=sum[i];
    }
    jc[0]=njc[0]=1;
    for(i=1;i<=200000;i++)
    {
        jc[i]=jc[i-1]*(LL)i%P;
        njc[i]=ksm(jc[i],P-2);
    }
}

inline void calc(int x)
{
    int i;
    for(i=1;i*i<=x;i++)
        if(x%i==0)
        {
            ans=(ans+(LL)C(cf[i],k-1)*(sum[i]))%P;
            cf[i]++;
            if(i*i!=x)
            {
                ans=(ans+(LL)C(cf[x/i],k-1)*(sum[x/i]))%P;
                cf[x/i]++;
            }
        }
}

int main()
{
    int n,q,x,i;
    init();
    cin>>n>>k>>q;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        calc(x);
    }
    for(i=1;i<=q;i++)
    {
        scanf("%d",&x);
        calc(x);
        printf("%d\n",ans);
    }
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")