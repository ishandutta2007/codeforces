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
int n,m;
bool d[200][200];

void NIE()
{
    cout<<"NO";
    exit(0);
}

void TAK()
{
    cout<<"FHTAGN!";
    exit(0);
}

bool odw[200];
bool odw1[200];
vi st;
int last;

bool dfs(int u,int p)
{
    odw[u]=1;
    FOR(i,n)
    {
        if (d[i][u] && i!=p)
        {
            if (odw[i])
            {
                st.pb(u);
                last=i;
                return 1;
            }
            if (dfs(i,u))
            {
                if (last>=0)
                st.pb(u);
                if (last==u) last=-5;
                return 1;
            }
        }
    }
    return 0;
}

void dfs2(int u)
{
    odw1[u]=1;
    FOR(i,n)
    {
        if (d[i][u] && !odw1[i]) dfs2(i);
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    if (n!=m) NIE();
    FOR(i,m)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        d[a][b]=d[b][a]=1;
    }
    dfs2(0);
    dfs(0,-1);
    bool ok=1;
    FOR(i,n)
    {
        if (!odw1[i]) ok=0;
    }
    if (ok && st.sz>=3) TAK();
    else NIE();
    

    return 0;
}