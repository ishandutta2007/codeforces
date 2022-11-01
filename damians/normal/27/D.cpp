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
pii po[1000];
bool odw[1000];
bool col[1000];
int n,m;

bool kr(int a,int b)
{
    if (po[a].fi<=po[b].fi && po[b].se<=po[a].se) return 0;
    if (po[b].fi<=po[a].fi && po[a].se<=po[b].se) return 0;
    if (po[a].se<=po[b].fi) return 0;
    if (po[b].se<=po[a].fi) return 0;
    return 1;
}

bool fail;

void dfs(int u,int cl)
{
    if (fail) return;
    DBG(u);
    odw[u]=1;
    col[u]=cl;
    FOR(i,m)
    {
        if (i==u) continue;
        if (kr(u,i))
        {
            DBG2(u,i);
            if (odw[i] && col[i]==cl)
            {
                fail=1;
                break;
            }
            else if (!odw[i])
            dfs(i,1-cl);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    FOR(i,m)
    {
        cin>>po[i].fi>>po[i].se;
        if (po[i].fi>po[i].se) swap(po[i].fi,po[i].se);
    }
    fail=0;
    //FOR(i,n) FOR(j,n)
    FOR(i,m) if (!odw[i])
    dfs(i,0);
    if (!fail)
    {
        FOR(i,m) cout<<(col[i]?'o':'i');
        
    }
    else cout<<"Impossible";

    return 0;
}