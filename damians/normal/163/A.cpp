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
#define un(v) v.erase(unique(ALL(v)),v.end())
#define LOLDBG
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
#define MOD 1000000007
int dp[5002][5002];
int sum[5002][300];

int main()
{
    ios_base::sync_with_stdio(0);
    string s,t;
    cin>>s>>t;
    int n=s.sz,m=t.sz;
    ll wyn=0;
    FOR(j,m)
    {
        FOR(i,n)
        {
            if (s[i]!=t[j]) {dp[i][j]=0;continue;}
            dp[i][j]=1;
            if (i) dp[i][j]+=sum[i-1][s[i-1]];
            if (t[j]==s[i-1]) dp[i][j]-=dp[i-1][j];
            dp[i][j]%=MOD;
            if (dp[i][j]<0) dp[i][j]+=MOD;
            sum[i][t[j]]=(sum[i][t[j]]+dp[i][j])%MOD;
            wyn+=dp[i][j];
        }
        wyn%=MOD;
    }
    cout<<wyn;

    return 0;
}