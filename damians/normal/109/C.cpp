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

bool luck(int x)
{
    stringstream ss;
    ss<<x;
    string s=ss.str();
    FOR(j,s.sz) if (s[j]!='4' && s[j]!='7') return 0;
    return 1;
}

bool odw[1000000];
vi kr[200000];
ll ile;

void dfs(int u)
{
    odw[u]=1;
    ile++;
    FORE(j,kr[u]) if (!odw[*j]) dfs(*j);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    FOR(i,n-1)
    {
        int a,b;cin>>a>>b;
        a--;b--;
        int c;cin>>c;
        if (!luck(c)) {kr[a].pb(b);kr[b].pb(a);}
    }
    ll wyn=n*1LL*(n-1)*1LL*(n-2);
    FOR(i,n)
    {
        
        if (!odw[i]) 
        {
            ile=0;
            dfs(i);
            wyn-=2*ile*(ile-1)*(n-ile);
            wyn-=ile*(ile-1)*(ile-2);
        }
    }
    cout<<wyn;

    return 0;
}