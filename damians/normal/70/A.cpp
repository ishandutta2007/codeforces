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
#define MOD 1000003
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

ll pot2[1000005];
ll t[1000005];

ll go(int n)
{
    if (n==0) return 0;
    if (n==1) return 3;
    if (t[n]!=-1) return t[n];
    ll w=pot2[2*n-2]+3*go(n-1);
    t[n]=w%MOD;
    return w%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    pot2[0]=1;
    REP(i,1,1000000) pot2[i]=(pot2[i-1]*2)%MOD;
    REP(i,0,1000000) t[i]=-1;
    int n;
    cin>>n;
    ll w=pot2[2*n]-go(n);
    w%=MOD;
    w=(w+MOD)%MOD;
    cout<<w<<endl;

    return 0;
}