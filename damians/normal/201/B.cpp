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
#define sqr(x) ((x)*(x))
ll c[1001][1001];
ll s[1001];


int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;cin>>n>>m;
    FOR(i,n) FOR(j,m) cin>>c[i][j];
    int bx=-1;
    ll B=1LL<<60;
    FOR(i,n) s[i]=0;
    FOR(i,n) FOR(j,m) s[i]+=c[i][j];
    FOR(i,n+1)
    {
        ll w=0;
        int pos=4*i;
        int akt=2;
        FOR(j,n)
        {
            w+=sqr(pos-akt)*s[j];
            akt+=4;
        }
        if (w<B) 
        {
            B=w;
            bx=i;
        }
    }
    //DBG(B);
    //DBG(bx);
    ll wyn=B;
    int by=-1;
    B=1LL<<60;
    FOR(i,m) s[i]=0;
    FOR(i,m) FOR(j,n) s[i]+=c[j][i];
    FOR(i,m+1)
    {
        ll w=0;
        int pos=4*i;
        int akt=2;
        FOR(j,m)
        {
            w+=sqr(pos-akt)*s[j];
            akt+=4;
        }
        if (w<B) 
        {
            B=w;
            by=i;
        }
    }
    cout<<wyn+B<<"\n";;
    cout<<bx<<" "<<by<<"\n";
    
    

    return 0;
}