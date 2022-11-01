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

int A,B;
vi a,b;

int m[1000002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>A>>B;
    a.resize(A);
    b.resize(B);
    FOR(i,1000002) m[i]=-1;
    FOR(i,A) cin>>a[i];
    FOR(i,B) cin>>b[i]; 
    FOR(i,B) m[b[i]]=i;
    FOR(i,A) a.pb(a[i]);
    int j=0;
    deque<ll> Q;
    int wyn=0;
    int ile=0;
    FOR(i,A)
    {
        j=Q.sz;
        while(j<min(A,B))
        {
            ile++;
            if (ile>5000000) return 1;
            if (m[a[i+j]]==-1) {break;}
            int pos=m[a[i+j]];
            if (Q.sz==0) Q.push_front(pos);
            else
            {
                ll pr=Q.front();
                ll tyl=Q.back();
                ll q=(tyl)/B;
                ll moj=pos+q*B;
                while(moj<=tyl) moj+=B;
                if (moj-pr<B)
                    Q.push_back(moj);
                else
                {
                    //Q.pop_front();
                    break;
                }
            }
            j++;
        }
        REMAX(wyn,j);
        if (Q.sz) Q.pop_front();
    }
    cout<<wyn;

    return 0;
}