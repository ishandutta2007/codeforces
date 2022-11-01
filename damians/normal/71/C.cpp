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
#define LOLDBG1
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
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

set<int> st;
int n;

bool check(int p, int d)
{
    int w=p;
    while(w<=n)
    {
        if (!IN(w,st)) return 0;
        w+=d;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    FOR(i,n)
    {
        int a;
        cin>>a;
        if (a)
        st.insert(i+1);
    }
    bool ok=0;
    REPD(i,n/3,1)
    {
        if (n%i) continue;
        REP(j,1,i)
        {
            ok=check(j,i);
            if (ok)
            {
                DBG(i);
                DBG(j);
            }
            if (ok) break;
        }
        if (ok) break;
    }
    puts(ok?"YES":"NO");
        

    return 0;
}