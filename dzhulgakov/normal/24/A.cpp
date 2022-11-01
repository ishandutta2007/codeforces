#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define N 128
int n,m;
VPII adj[N];
bool mark[N];
int cost[N][2];

void dfs(int v, int p=-1)
{
    REP(i,SZ(adj[v]))
    {
        int vv = adj[v][i].first;
        if (p==vv || mark[vv]) continue;
        mark[vv]=true;
        if (adj[v][i].second > 0)
        {
            cost[m][0] = 0;
            cost[m][1] = adj[v][i].second;
        }
        else
        {
            cost[m][1] = 0;
            cost[m][0] = -adj[v][i].second;
        }
        m++;
        mark[vv]=true;
        dfs(vv,v);
    }
}

int main()
{
    //freopen("data.in","r",stdin);

    scanf("%d",&n);
    REP(i,n)
    {
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        x--;y--;
        adj[x].push_back(PII(y,-c));
        adj[y].push_back(PII(x,c));
    }
    CLEAR(mark);
    m=0;
    dfs(0);
    int res[2]={0,0};
    REP(i,m) REP(j,2)
    {
        res[j]+=cost[i][j];
    }
    printf("%d\n",min(res[0],res[1]));
    return 0;
}