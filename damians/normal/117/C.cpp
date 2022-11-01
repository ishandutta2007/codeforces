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


char s[5004][5004];
short d[5004];
vi v;
bool cykl;
int a0;
int n;

void dfs(int a)
{
    if (v.sz) return;
    if (d[a]==1)
    {
        cykl=1;
        a0=a;
        return;
    }
    if (d[a]==2) return;
    d[a]=1;
    FOR(i,n)
    {
        if (s[a][i])
        {
            dfs(i);
            if (cykl)
            {
                v.pb(a);
                if (a0==a)
                {
                    cykl=0;
                    
                }
                break;
            }
        }
    }
    d[a]=2;
}

int main()
{
    CZ(n);
    FOR(i,n)
    {
        scanf("%s",s[i]);
        FOR(j,n) s[i][j]-='0';
    }
    FOR(i,n)
    if (d[i]==0)
    dfs(i);
    DBG(v);
    reverse(ALL(v));
    if (!v.sz)
    {
        cout<<-1;
        return 0;
        
    }
    while(!s[v[2]][v[0]])
    {
        v.erase(v.begin()+1);
    }
    FOR(i,3) cout<<v[i]+1<<" ";
    

    return 0;
}