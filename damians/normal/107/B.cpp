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

double sil[100005];

double npok(int a,int b)
{
    if (b==0 || a==b) return 1.0;
    return sil[a]/(sil[b]*sil[a-b]);
}



int main()
{
    ios_base::sync_with_stdio(0);
    sil[0]=1;
    REP(i,1,100000) sil[i]=sil[i-1]*i;
    int n,m,h;
    cin>>n>>m>>h;
    h--;
    int suma=0;
    int inni=0;
    int oni=0;
    FOR(i,m)
    {
        int a;cin>>a;
        if (i==h)
        {
            a--;
            oni=a;
        }
        else inni+=a;
        suma+=a;
    }
    DBG(suma);
    DBG(oni);
    DBG(inni);
    n--;
    if (suma<n)
    {
        cout<<-1.0;
        return 0;
    }
    vi tp1,tp2;
    if (inni<n) tp1.pb(0);
    REP(i,1,inni) tp1.pb(i);
    REP(i,1,suma-n) tp1.pb(i);
    REP(i,1,suma) tp2.pb(i);
    REP(i,1,inni-n) tp2.pb(i);
    while(tp1.sz<tp2.sz) tp1.pb(1);
    while(tp1.sz>tp2.sz) tp2.pb(1);
    sort(ALL(tp1));
    sort(ALL(tp2));
    double wyn=1.0;
    FOR(i,tp1.sz) wyn*=tp1[i]*1.0/tp2[i];
    cout<<setprecision(12)<<fixed<<1.0-wyn;

    return 0;
}