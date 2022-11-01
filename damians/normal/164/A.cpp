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
#define N 111111
int f[N];
int dobre[N];

vi kr[N],krt[N];
void dod(int a,int b)
{
    kr[a].pb(b);
    krt[b].pb(a);
}

bool odw[N];
int n,m;

void go1()
{
    queue<int> Q;
    FOR(i,N) odw[i]=0;
    FOR(i,n) 
    {
        if (f[i]==1)
        {
            odw[i]=1;
            Q.push(i);
        }
    }
    while(Q.sz)
    {
        int u=Q.front();Q.pop();
        
        FORE(i,kr[u])
        {
            if (!odw[*i]) 
            {
                odw[*i]=1;
                Q.push(*i);
            }
        }
    }
}

void go2()
{
    queue<int> Q;
    FOR(i,N) odw[i]=0;
    FOR(i,n) 
    {
        
        if (f[i]==2)
        {
            odw[i]=2;
            Q.push(i);
        }
    }
    while(Q.sz)
    {
        int u=Q.front();Q.pop();
        if (f[u]==1) continue;
        FORE(i,krt[u])
        {
            if (!odw[*i]) 
            {
                odw[*i]=1;
                Q.push(*i);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    FOR(i,n) cin>>f[i];
    FOR(i,m)
    {
        int a,b;cin>>a>>b;
        a--;b--;
        dod(a,b);
    }
    go1();
    FOR(i,n) dobre[i]+=odw[i];
    go2();
    FOR(i,n) dobre[i]+=odw[i];
    FOR(i,n) if (dobre[i]==2) puts("1"); else puts("0");

    return 0;
}