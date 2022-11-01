#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define LOLDBG
#ifdef LOLDBG
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cout<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

ll a[150];
ll dp[102][50000];

ll go(int nr,ll x)
{
    if (nr==-1) return x;
    if (x==0) return 0;
    if (x<50000)
    {
        if (dp[nr][x]!=-1) return dp[nr][x];
        dp[nr][x]=go(nr-1,x)-go(nr-1,x/a[nr]);
        return dp[nr][x];
    }
    return go(nr-1,x)-go(nr-1,x/a[nr]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    ll n;
    int k;
    cin>>n>>k;
    FOR(i,k) cin>>a[i];
    sort(a,a+k);
    FOR(i,100) FOR(j,50000) dp[i][j]=-1;
    cout<<go(k-1,n)<<endl;
    

    return 0;
}