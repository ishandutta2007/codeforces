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

int d[11];
int e[2][11];
vi v[2];
int wyn[10];

int go(int x)
{
    FOR(j,2) FOR(i,10) e[j][i]=d[i];
    e[0][x]--;
    e[1][10-x]--;
    int h=1;
    REP(i,0,9)
    {
        h+=2*min(e[0][i],e[1][9-i]);
    }
    h+=min(e[0][0],e[1][0]);
    return h;
}

void go2(int x)
{
    FOR(j,2) FOR(i,10) e[j][i]=d[i];
    e[0][x]--;
    e[1][10-x]--;
    v[0].pb(x);
    v[1].pb(10-x);
    int h=1;
    REP(i,0,9)
    {
        int mn=min(e[0][i],e[1][9-i]);
        e[0][i]-=mn;
        e[1][9-i]-=mn;
        FOR(j,mn) v[0].pb(i);
        FOR(j,mn) v[1].pb(9-i); 
    }
    int mn=min(e[0][0],e[1][0]);
    e[0][0]-=mn;
    e[1][0]-=mn;
    REP(i,0,9)
    {
        FOR(j,e[0][i]) v[0].pb(i);
    }
    REP(i,0,9)
    {
        FOR(j,e[1][i]) v[1].pb(i);
    }
    FOR(i,2) reverse(ALL(v[i]));
    FOR(i,2)
    {
        FOR(j,v[i].sz) cout<<v[i][j];
        FOR(j,mn) cout<<0;
        cout<<"\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    string s;cin>>s;
    FOR(i,s.sz) d[s[i]-'0']++;
    DBG(d[2]);
    int best=1;
    int comam=-1;
    REP(i,1,5)
    {
        
        if (d[i]>0 && d[10-i]>0)
        {
            int f=go(i);
            DBG(i);
            DBG(f);
            if (f>comam)
            {
                comam=f;
                best=i;
            }
        }
    }
    if (comam==-1)
    {
        FOR(dsg,2)
        {
            REPD(i,9,0)
            {
                FOR(j,d[i]) cout<<i;
            }
            cout<<"\n";
        }
    }
    else
    go2(best);
    
    
    

    return 0;
}