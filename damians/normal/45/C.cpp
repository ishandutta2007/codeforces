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

char plec[200006];
int skill[200006];
set<int> ob;


int main()
{
    int n;CZ(n);
    scanf("%s",plec);
    FOR(i,n) CZ(skill[i]);
    FOR(i,n) ob.insert(i);
    priority_queue<pair<int,pii>,vector<pair<int,pii> >,greater<pair<int,pii> > > Q;
    FOR(i,n-1)
    {
        if (plec[i]!=plec[i+1])
        {
            Q.push(mp(abs(skill[i]-skill[i+1]),mp(i,i+1)));
        }
    }
    vector<pii> wyn;
    set<int>::iterator it;
    while(!Q.empty())
    {
        pair<int,pii> p=Q.top();Q.pop();
        pii u=p.se;
        if (!IN(u.fi,ob) || !IN(u.se,ob)) continue;
        wyn.pb(u);
        ob.erase(u.fi);
        ob.erase(u.se);
        it=ob.lower_bound(u.se);
        if (it==ob.end()) continue;
        if (it==ob.begin()) continue;
        u.se=*it;
        it--;
        u.fi=*it;
        if (plec[u.fi]!=plec[u.se])
        {
            Q.push(mp(abs(skill[u.fi]-skill[u.se]),u));
        }
    }
    printf("%d\n",wyn.sz);
    FORE(i,wyn) printf("%d %d\n",(i->fi)+1,(i->se)+1);

    return 0;
}