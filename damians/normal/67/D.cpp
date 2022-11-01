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
#define INF 100000000
using namespace std;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

map<int,int> m;
vector<pair<int,int> > v;
int t[2000000];
int h[2000000];

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    v.resize(n);
    FOR(i,n) cin>>v[i].fi;FOR(i,n) cin>>v[i].se;
    FOR(i,n) t[v[i].fi]=i;
    FOR(i,n) h[t[v[i].se]]=i;
    DBG(vector<int>(h,h+(n)));
    sort(ALL(v));
    m[INF]=0;
    m[-INF]=INF;
    map<int,int>::iterator it;
    FOR(i,n)
    {
        it=m.lower_bound(h[i]);
        int war=(it->se)+1;
        m[h[i]]=(it->se)+1;
        while(1)
        {
            DBG(i);
            it=m.find(h[i]);
            it--;
            if (((it->se))<=war) m.erase(it);
            else break;
        }
        DBG(m.sz);
    }
    int wyn=0;
    for(it=m.begin();it!=m.end();it++)
    {
        if ((it->se)!=INF) wyn=max(wyn,(it->se));
    }
    cout<<wyn;

    return 0;
}