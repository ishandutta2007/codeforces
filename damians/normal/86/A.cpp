#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <map>
#include <queue>
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
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

ll reflect(ll x)
{
    stringstream ss;
    ss<<x;
    string s=ss.str();
    FOR(i,s.sz) s[i]='0'+('9'-s[i]);
    stringstream ss2(s);
    ll k;
    ss2>>k;
    return k;
}

int main()
{
    ios_base::sync_with_stdio(0);
    ll l,r;cin>>l>>r;
    ll R=r;
    ll pot=1;
    while(R>=10)
    {
        R/=10;
        pot*=10;
    }
    if (R>=5) 
    {
        if (5*pot>=l)
            cout<<5*pot*reflect(5*pot)<<endl;
        else cout<<max(r*reflect(r),l*reflect(l));
        return 0;
    }
    else
        cout<<max(r*reflect(r),l*reflect(l));

    

    return 0;
}