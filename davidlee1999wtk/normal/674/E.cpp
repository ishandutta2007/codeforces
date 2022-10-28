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
#include<iomanip>
#define INF 1000000000
#define N 500005
#define K 44
#define P 1000000007
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
double dp[N],f[N][K+2];
char _ch;
inline void getint(int &_x)
{
	_x=0;
	for(_ch=getchar();_ch>'9'||_ch<'0';_ch=getchar());
	for(;_ch<='9'&&_ch>='0';_ch=getchar())
		_x=_x*10+_ch-48;
}

int fa[N],n=1;

void upd1(int x,int dep)
{
    int v=fa[x];
    if(v==0) return;
    if(v==1||dep==K)
    {
        for(int i=dep-1;i<dep;i++)
            f[v][i]=f[v][i]/(0.5+0.5*f[x][i-1]);
        return;
    }
    upd1(fa[x],dep+1);
    for(int i=dep-1;i<dep;i++)
        f[v][i]=f[v][i]/(0.5+0.5*f[x][i-1]);
}

void upd2(int x,int dep,double now)
{
    if(fa[x]==0||dep>K)
        return;
    int v=fa[x];
    now*=0.5*f[v][dep-1];
    //debug(x);
    //debug(now);
    //debug(f[v][1]);
    dp[v]+=now;
    for(int i=dep-1;i<dep;i++)
        f[v][i]=f[v][i]*0.5+f[v][i]*f[x][i-1]*0.5;
    upd2(v,dep+1,now);
}

int main()
{
    int q,op,x;
    dp[1]=1;
    for(int i=1;i<=K;i++)
        f[1][i]=1;
    cin>>q;
    while(q--)
    {
        getint(op);
        if(op==1)
        {
            n++;
            getint(fa[n]);
            dp[n]=1;
            for(int i=1;i<=K;i++)
                f[n][i]=1;
            upd1(fa[n],3);
            upd2(n,2,1);
        }
        else
        {
            getint(x);
            printf("%.9f\n",dp[x]-1);
        }
    }
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")  //compiler vc++
//#define O2 __attribute__((optimize("-O2")))