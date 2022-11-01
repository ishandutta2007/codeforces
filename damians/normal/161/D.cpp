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

#define M 50001

int dol[M][504];
int n,k;
vi kr[M];
bool odw[M];

int iles[504];

ll dfs(int u)
{
    int z=0;
    odw[u]=1;
    while(z<kr[u].sz)
    {
        if (odw[kr[u][z]]) {swap(kr[u][z],kr[u].back());kr[u].pop_back();continue;}
        z++;
    }
    ll wyn=0;
    FOR(i,kr[u].sz)
        wyn+=dfs(kr[u][i]);
    dol[u][0]=1;
    DBG(u+1);
    DBG(wyn);
    FOR(i,kr[u].sz)
    {
        z=kr[u][i];
        FOR(j,k)
        {
            wyn+=(ll)dol[u][k-j-1]*dol[z][j];
        }
        FOR(j,k) dol[u][j+1]+=dol[z][j];
    }
    DBG(u+1);
    DBG(wyn);
    DBG(vi(dol[u],dol[u]+4));
    return wyn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;cin>>k;//k++;
    FOR(i,n-1)
    {
        int a,b;cin>>a>>b;
        a--;b--;
        kr[a].pb(b);
        kr[b].pb(a);
    }
    cout<<dfs(0);

    return 0;
}