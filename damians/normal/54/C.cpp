#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)REP(i,0,(int)(v)-1)
#define FORD(i,v)REPD(i,(int)(v)-1,0)
#define pb push_back
#define sz size
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define ALL(x) (x).begin(),(x).end()
using namespace std;
int N,K,D;
ll L[2000],R[2000];
double pr[2000];
double dp[2000][2000];

ll wiod(ll x)
{
    while(x/10)
        x/=10;
    return x;
}

ll wiod2(ll x)
{
    int k=0;
    while(x/10)
        {x/=10;k++;}
    x=1;
    FOR(i,k) x*=10;
    return x;
}

ll ilejed(ll x)
{
    if (x==0) return 0;
    ll w=wiod(x);
    if (w==1)
        return x-wiod2(x)+1+ilejed(wiod2(x)-1);
    if (w==2) return (ilejed(2*wiod2(x)-1));
    return ilejed(x-wiod2(x));
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>N;
    FOR(i,N) cin>>L[i]>>R[i];
    FOR(i,N) pr[i]=double(ilejed(R[i])-ilejed(L[i]-1))/(double(R[i]-L[i]+1));
    cin>>K;
    FOR(i,N+1) dp[0][i]=0;
    dp[0][0]=1.0;
    REP(k,1,N)
    {
        dp[k][0]=dp[k-1][0]*(1-pr[k-1]);
        REP(i,1,N) dp[k][i]=dp[k-1][i]*(1-pr[k-1])+dp[k-1][i-1]*pr[k-1];
    }
    double wyn=0;
    REP(i,0,N) if (100*i>=K*N)wyn+=dp[N][i];
    printf("%.15lf\n",wyn);
    return 0;
}