#include <string>
#include <vector>
#include <algorithm>
#include <functional>
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
#define INF 2000000000
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }
int t[1005][1005];
int tab[1005];
int n;

int go(int od, int ludz)
{
    if (od==n) return tab[ludz];
    if (od==n-1) return max(tab[n-1],tab[ludz]);
    if (t[od][ludz]!=-1) return t[od][ludz];
    int w=INF;
    REMIN(w,max(tab[od],tab[od+1])+go(od+2,ludz));
    REMIN(w,max(tab[od],tab[ludz])+go(od+2,od+1));
    REMIN(w,max(tab[od+1],tab[ludz])+go(od+2,od));
    t[od][ludz]=w;
    return w;
}

int main()
{
    ios_base::sync_with_stdio(0);
    FOR(i,1005) FOR(j,1005) t[i][j]=-1;
    cin>>n;
    FOR(i,n) cin>>tab[i];
    int w=go(1,0);
    cout<<w<<endl;
    int od=1;
    int ludz=0;
    while(1)
    {
        //DBG(w);
        if (od==n)
        {
            cout<<ludz+1<<endl;
            return 0;
        }
        if (od==n-1)
        {
            cout<<ludz+1<<" "<<n<<endl;
            return 0;
        }
        int a1,a2;
        if (w==max(tab[od],tab[od+1])+go(od+2,ludz))
        {
            w=go(od+2,ludz);
            a1=od+1;a2=od+2;
            od+=2;
        }
        else if (w==max(tab[od],tab[ludz])+go(od+2,od+1))
        {
            w=go(od+2,od+1);
            a1=od+1;a2=ludz+1;
            ludz=od+1;
            od+=2;
            
        }
        else if (w==max(tab[od+1],tab[ludz])+go(od+2,od))
        {
            w=go(od+2,od);
            a1=od+2;
            a2=ludz+1;
            ludz=od;
            od+=2;
            
        }
        if (a1>a2) swap(a1,a2);
        cout<<a1<<" "<<a2<<endl;
    }

    return 0;
}