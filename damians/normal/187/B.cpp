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
#define INF (1<<30)+1
int d[60][60][60];
int dpb[60][60][62];

int main()
{
    //ios_base::sync_with_stdio(0);
    int n,m,r;cin>>n>>m>>r;
    FOR(i,m)
    {
        FOR(j,n) FOR(k,n) cin>>d[i][j][k];
        
    }
    FOR(l,m)
    {
        FOR(k,n) FOR(i,n) FOR(j,n) REMIN(d[l][i][j],d[l][i][k]+d[l][k][j]);
    }

    REP(z,0,61) FOR(m1,n) FOR(m2,n)
    {
        dpb[m1][m2][z]=INF;
        if (z==0)
        FOR(a,m)
        {
            REMIN(dpb[m1][m2][z],d[a][m1][m2]);  
        }
        else
        FOR(m3,n) REMIN(dpb[m1][m2][z],dpb[m1][m3][0]+dpb[m3][m2][z-1]);
    }

    FOR(i,r)
    {
        int s,t,k;cin>>s>>t>>k;
        s--;t--;
        DBG(mp(s,t));
        cout<<dpb[s][t][min(k,61)]<<"\n";
    }

    return 0;
}