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

bool is_prime(ll x)
{
    if (x<2) return 0;
    for(int j=2;j*j<=x;j++) if (x%j==0) return 0;
    return 1;
}

int n;
ll s;

bool go(int z)
{
    int r=rand()%z;
    r=min(n,r+4);
    if (!is_prime(r) || !is_prime(z-r)) return 0;
    if (r>=3 && z-r>3)
    {
        REP(i,1,n)
        {
            if (i<3) cout<<1<<" ";
            else if (i==r) cout<<2<<" ";
            else cout<<3<<" ";
        }
        return 1;
    }
    return 0;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    s=n*(n+1)/2;
    DBG(s);
    if (is_prime(s))
    {
        FOR(i,n) cout<<1<<" ";
        return 0;
    }
    if (s%2==0)
    {
        ll u=0;
        REP(j,1,s)
        {
            if (is_prime(j) && is_prime(s-j))
            {
                u=j;
                break;
            }
        }
        set<int> st;
        REPD(i,n,1)
        {
            if (i<=u)
            {
                st.insert(i);
                u-=i;
            }
        }
        REP(i,1,n)
        {
            if (IN(i,st)) cout<<1<<" ";
            else cout<<2<<" ";
        }
        return 0;
    }
    if (is_prime(s-2))
    {
        REP(i,1,n)
        {
            if (i==2) cout<<1<<" ";
            else cout<<2<<" ";
        }
        return 0;
    }
    while(!go(s-3)){}
    
    return 0;
}