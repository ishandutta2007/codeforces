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

ll wyn[200000];

int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    ll czas=0;
    int t,x;
    vector<pii> ps;
    int i=0;
    while(i<n)
    {
        cin>>t>>x;
        czas=max(czas,(ll)t);
        ps.pb(mp(x,i));
        i++;
        if (ps.sz==m || i==n)
        {
            sort(ALL(ps));
            int l=ps.sz;
            int j=0;
            czas+=ps[0].fi;
            while(j<l)
            {
                int k=0;
                while(j+k<l && ps[j].fi==ps[j+k].fi) {wyn[ps[j+k].se]=czas;k++;}
                czas+=1+k/2;
                j+=k;
                if (j<l) czas+=ps[j].fi-ps[j-1].fi;
                else czas+=ps[j-1].fi;
            }
            ps.clear();
        }
    }
    FOR(i,n) cout<<wyn[i]<<" ";

    return 0;
}