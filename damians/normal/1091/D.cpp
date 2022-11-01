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
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

#define MOD 998244353

ll mpow(ll a, ll b)
{
    a=a%MOD;
    ll w=1;
    while(b)
    {
        if (b%2) w=(w*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return w;
}
#define N 1000001
int fact[N+1];
int rfact[N+1];
int main()
{
    ios_base::sync_with_stdio(0);
    fact[0]=1;
    REP(i,1,N) fact[i]=(fact[i-1]*1LL*i)%MOD;
    FOR(i,N+1) rfact[i]=mpow(fact[i],MOD-2);
    int n;cin>>n;
    ll w=1;
    REP(l,1,n-1)
    {
        ll s = (l*1LL*(n-l))%MOD;
        s= (s*fact[n])%MOD;
        s=(s*rfact[l+1])%MOD;
        //DBG(s);
        w+=s;
    }
    cout<<w%MOD<<"\n";
    return 0;
}