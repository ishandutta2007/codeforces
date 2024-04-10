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

ll p10[20];

ll licz(ll n)
{
    n++;
    vi v;
    ll N=n;
    while(N)
    {
        v.pb(N%10);
        N/=10;
    }
    //DBG(v);
    int d=v.sz;
    ll sum=0;
    ll mam=0;
    REPD(i,d-1,0)
    {
        REP(c,0,v[i]-1)
        {
            sum+=(mam+c)*p10[i];
            if (i) sum+=45*i*p10[i-1];
            //DBG(mp(i,45*i*p10[i-1]))
        }
        //DBG(sum);
        mam+=v[i];
    }
    return sum;
}

ll digs(ll n)
{
    ll sum=0;
    ll N=n;
    while(N)
    {
        sum+=N%10;
        N/=10;
    }
    return sum;
}

ll sdigs(int n)
{
    ll w=0;
    REP(i,1,n) w+=digs(i);
    return w;
}

int randu()
{
    int a=0;
    FOR(i,20) a=a*2+rand()%2;
    return a;
}

int main()
{
    p10[0]=1;
    REP(i,1,20)p10[i]=p10[i-1]*10;
    ll a;cin>>a;
    map<ll,int> m;
    if (a<1000000)
    {
        FOR(i,a)
        {
            int r=randu();
            m[licz(r)%a]=r;
        }
        while(1)
        {
            int r=(1<<22)+randu();
            int x=licz(r)%a;
            if (IN(x,m))
            {
                cout<<m[x]+1<<" "<<r<<"\n";
                return 0;
            }
        }
        return 0;
    }
    FOR(i,1<<14)
        {
            int r=i+1;
            m[licz(r)%a]=r+1;
        }
    ll lo=1,hi=p10[17],mid;
    //DBG(hi);
    //DBG(a);
    while(hi-lo>1)
    {
        //DBG(mp(lo,hi));
        mid=(hi+lo)/2;
        if (licz(mid)>a)hi=mid;
        else lo=mid;
    }
    //DBG(hi);
    while(1)
        {
            ll x=licz(hi)%a;
            if (IN(x,m))
            {
                cout<<m[x]<<" "<<hi<<"\n";
                //DBG((licz(hi)-licz(m[x]-1))%a;
                return 0;
            }
            hi++;
        }

    return 0;
}