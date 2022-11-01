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
#define FORE(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define LOLDBG1
#ifdef LOLDBG
#define DBG(vari) cerr<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cerr<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define CZ3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z));
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }
#define MOD 100000000

int dp[102][102][12][2];


int main()
{
    ios_base::sync_with_stdio(0);
    int n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;
    dp[1][0][1][0]=dp[0][1][1][1]=1;
    REP(i,0,n1) REP(j,0,n2) FOR(b,2)
    {
        if (n1==0 && n2==0) continue;
        if (n1==0 && n2==1) continue;
        if (n1==1 && n2==0) continue;
        if (b==0)
        {
            REP(k,1,k1)
            {
                if (k>1)
                {
                    if (i>0)
                    dp[i][j][k][b]=dp[i-1][j][k-1][b];
                }
                else
                {
                    if (i)
                    FOR(l,k2+1) dp[i][j][k][b]=(dp[i][j][k][b]+dp[i-1][j][l][1-b])%MOD;
                }
            }
        }
        else
        {
            REP(k,1,k2)
            {
                if (k>1)
                {
                    if (j)
                    dp[i][j][k][b]=dp[i][j-1][k-1][b];
                }
                else
                {
                    if (j)
                    FOR(l,k1+1) dp[i][j][k][b]=(dp[i][j][k][b]+dp[i][j-1][l][1-b])%MOD;
                }
            }
        }
    }
    ll wyn=0;
    DBG(dp[2][0][1][1]);
    REP(i,1,k1) {DBG(dp[n1][n2][i][0]);wyn+=dp[n1][n2][i][0];}
    REP(i,1,k2) {DBG(dp[n1][n2][i][1]);wyn+=dp[n1][n2][i][1];}
    cout<<wyn%MOD;

    return 0;
}