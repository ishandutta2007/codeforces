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
int g[12][12];
int n,m,k;
ll dp[(1<<10)+2][(1<<10)+2];

ll rub(int a, int b)
{
    //cout<<a<<" "<<b<<endl;
    if (dp[a][b]!=-1) return dp[a][b];
    if (__builtin_popcount(b)==2 && a==b) 
    {
        int x,y=-1;
        FOR(i,n) {if ((1<<i)&a) x=i;if (y==-1 && (1<<i)&a) y=i;}
        return g[x][y];
    }
    if (__builtin_popcount(a)==1 && a==b) return 1;
    if (__builtin_popcount(a)==1) return 0;
    if (a==0) return 0;
    if (b&a!=a) return 0;
    int z=0;
    while(!((1<<z)&a)) z++;
    if (z>=n) cout<<"DGSGSGSDG";
    //DBG(z);
    ll w=0;
    FOR(i,n)
    {
        if ((1<<i)&a) continue;
        if (!g[z][i]) continue;
        if (!((1<<i)&b)) continue;
        w+=rub(a^(1<<z)^(1<<i),b^(1<<z))+rub(a^(1<<z),b^(1<<z));
    }
    dp[a][b]=w;
    return w;
}



int main()
{
    ios_base::sync_with_stdio(0);
    int ok;
    cin>>n>>m>>k;
    FOR(i,n) FOR(j,n) g[i][j]=0;
    FOR(i,m)
    {
        int a,b;cin>>a>>b;a--;b--;
        g[a][b]=g[b][a]=1;
    }
    FOR(i,(1<<n)) FOR(j,(1<<n)) dp[i][j]=-1;
    ll wyn=0;
    FOR(i,(1<<n))
    {
        if (__builtin_popcount(i)==k) 
        {
            wyn+=rub(i,(1<<n)-1);
            //DBG(wyn);
        }
    }
    cout<<wyn<<endl;
    return 0;
}