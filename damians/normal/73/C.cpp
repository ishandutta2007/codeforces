#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define LOLDBG
#ifdef LOLDBG
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cout<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define ALL(x) (x).begin(),(x).end()
#define INF 1000000000
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

int c[300][300];

int t[104][102][300];

int main()
{
    ios_base::sync_with_stdio(0);
    string s;int k;
    int n;
    cin>>s>>k>>n;
    char c1,c2;
    FOR(i,300) FOR(j,300) c[i][j]=0;
    FOR(i,n)
    {
        int a;
        cin>>c1>>c2>>a;
        c[c1][c2]=a;
        //DBG(a);
    }
    FOR(i,104) FOR(j,102) FOR(l,300) t[i][j][l]=-INF;
    REP(l,'a','z')
    {
        if (s[0]==l) t[0][0][l]=0;
        t[0][1][l]=0;
    }
    REP(i,1,s.sz-1)
    {
        REP(j,0,k)
        {
            REP(l,('a'),('z'))
            REP(l1,('a'),('z'))
                if (s[i]==l1)
                {
                    t[i][j][l1]=max(t[i][j][l1],t[i-1][j][l]+c[l][l1]);
                }
                else
                {
                    if (j!=0)
                        t[i][j][l1]=max(t[i][j][l1],t[i-1][j-1][l]+c[l][l1]);
                }
            
        }
    }
    int best=-INF;
    REP(j,0,k) REP(l,'a','z') best=max(best,t[s.sz-1][j][l]);
    cout<<best;

    return 0;
}