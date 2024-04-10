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



int main()
{
    ios_base::sync_with_stdio(0);
    ll x,y,z,k;
    vector<ll> v(3),w(3,0);
    cin>>v[0]>>v[1]>>v[2]>>k;
    FOR(i,3) v[i]--;
    sort(ALL(v));
    ll best=0;
    FOR(i,min(v[0],k)+1)
    {
        w[0]=i;
        ll k1=k-i;
        if (k1/2<=v[1])
        {
            if (i+k1/2+min(v[2],k1-k1/2)<=k)
            best=max(best,(i+1)*((k1/2)+1)*((min(v[2],k1-k1/2))+1));
        }
        else
        {
            if (i+v[1]+min(v[2],k1-v[1])<=k)
            best=max(best,(i+1)*(v[1]+1)*(min(v[2],k1-v[1])+1));
        }
    }
    cout<<best<<endl;
    

    return 0;
}