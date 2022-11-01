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
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cout<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define ALL(x) (x).begin(),(x).end()
#define INF 10000000000000000LL
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

set<pair<string,string> > st;
vi v;
vector<string> t[3];
vector<ll> war;
vector<string> boh;


int main()
{
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    boh.pb("Anka");
    boh.pb("Chapay");
    boh.pb("Cleo");
    boh.pb("Troll");
    boh.pb("Dracul");
    boh.pb("Snowy");
    boh.pb("Hexadecimal");
    FOR(i,n)
    {
        string s1,s2;
        cin>>s1>>s2>>s2;
        st.insert(mp(s1,s2));
    }
    v.resize(3);
    war.resize(3);
    cin>>v[0]>>v[1]>>v[2];
    ll a=INF,b;
    FOR(sdgsdhs,10000)
    {
        //DBG(a);
        FOR(i,3) t[i].clear();
        FOR(i,7)
        {
            int r=rand()%3;
            t[r].pb(boh[i]);
        }
        //DBG(a);
        if (t[0].sz>0 && t[1].sz>0 && t[2].sz>0)
        {
            FOR(i,3) war[i]=v[i]/(t[i].sz);
            ll x=0;
            FOR(i,3) FOR(j,3) x=max(x,war[i]-war[j]);
            int sum=0;
            FOR(i,3)
            {
                FOR(j,t[i].sz) REP(k,0,t[i].sz-1) sum+=IN(mp(t[i][j],t[i][k]),st);
            }
            if (x<a)
            {
                a=x;
                b=sum;
            }
            else if (x==a && sum>b)
            {
                b=sum;
            }
        }
    }
    cout<<a<<" "<<b;
    

    return 0;
}