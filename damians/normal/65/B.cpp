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
#define INF 100000
using namespace std;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

int t[2000];

int ustaw(int x,int nr,int na)
{
    vector<int> v;
    while(x>0) 
    {
        v.pb(x%10);
        x/=10;
    }
    v[nr]=na;
    int p=1;
    int w=0;
    FOR(i,4)
    {
        w+=v[i]*p;
        p*=10;
    }
    return w;
}
set<int> st;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    t[0]=1000;
    FOR(i,n) cin>>t[i+1];
    REP(i,1,n)
    {
        st.clear();
        st.insert(INF);
        FOR(a,4) FOR(b,10)
        {
            int nw=ustaw(t[i],a,b);
            if (nw>=1000 && nw<=2011) st.insert(nw);
        }
        int war=*(st.lower_bound(t[i-1]));
        if (war==INF)
        {
            cout<<"No solution";
            return 0;
        }
        t[i]=war;
    }
    FOR(i,n) cout<<t[i+1]<<endl;
    
    

    return 0;
}