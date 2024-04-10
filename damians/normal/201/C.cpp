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
#define LOLDBG1
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

#define INF (1LL<<60)

ll D1[100002];
ll D2[100002];

ll R1[100002];
ll R2[100002];

int main()
{
    ios_base::sync_with_stdio(0);
    vi v;
    int n;cin>>n;
    n--;
    FOR(i,n)
    {
        int a;cin>>a;
        v.pb(a);
    }
    ll dp1=0,dp2=0;
    ll wyn=0;
    D1[0]=D2[0]=0;
    FOR(i,n)
    {
        if (v[i]==1)
        {
            dp2=0;
            dp1+=1;
        }
        else if (v[i]%2)
        {
            int g=v[i]-1;
            dp1=max(dp1+g+1,dp2+g+1);
            dp2+=g;
        }
        else if (v[i]%2==0)
        {
            dp1=max(dp1+v[i]-1,dp2+v[i]-1);
            dp2+=v[i];
        }
        D1[i+1]=dp1;
        D2[i+1]=dp2; 
        DBG(mp(dp1,dp2));
    }
    
    R1[n]=R2[n]=0;
    dp1=dp2=0;
    reverse(ALL(v));
    DBG(v);
    FOR(i,n)
    {
        if (v[i]==1)
        {
            dp1=max(dp2+1,dp1+1);
            dp2=0;
            
        }
        else if (v[i]%2)
        {
            int g=v[i]-1;
            dp1=max(dp1+g+1,dp2+g+1);
            dp2+=g;
        }
        else if (v[i]%2==0)
        {
            dp1=max(dp1+v[i]-1,dp2+v[i]-1);
            dp2+=v[i];
        }
        DBG(dp1);
        DBG(dp2);
        DBG(v[i]);
        R1[n-i-1]=dp1;
        R2[n-i-1]=dp2; 
    }
    DBG(vector<ll>(D1,D1+(n+1)));
    DBG(vector<ll>(D2,D2+(n+1)));
    DBG(vector<ll>(R1,R1+(n+1)));
    DBG(vector<ll>(R2,R2+(n+1)));
    FOR(i,n+1)
    {
        REMAX(wyn,D1[i]+R1[i]);
        REMAX(wyn,D2[i]+R2[i]);
        REMAX(wyn,D1[i]+R2[i]);
        REMAX(wyn,D2[i]+R1[i]);
    }
    cout<<wyn;

    return 0;
}