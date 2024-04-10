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



#define X 29
#define ull unsigned long long
#define qpa 1000007

string s;
string a,b;
int n;
ull hasze[10003];
ull pX[10003];

vector<ull> syf[1000007];
void insertuj(ull x)
{
    int d=x%qpa;
    if (find(ALL(syf[d]),x)==syf[d].end()) syf[d].pb(x);
}

inline ull h(int a, int b)//[a..b)
{
    return hasze[a]-pX[b-a]*hasze[b];
}

ull geth(string g)
{
    ull a=0;
    FOR(i,g.sz) a+=g[i]*pX[i];
    return a;
}


bool aok[3000];
bool bok[3000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>s>>a>>b;
    pX[0]=1;REP(i,1,3000) pX[i]=X*pX[i-1];
    n=s.sz;
    hasze[n]=0;
    REPD(i,n-1,0) hasze[i]=hasze[i+1]*X+s[i];
    ull a1=geth(a),b1=geth(b);
    FOR(i,n)
    {
        if (i+a.sz<=n) aok[i]=(h(i,i+a.sz)==a1);
        if (i+b.sz<=n) bok[i]=(h(i,i+b.sz)==b1); 
    }
    FOR(i,n) REP(j,i,n)
    {
        if (j-i<max(a.sz,b.sz)) continue;
        if (aok[i] && bok[j-b.sz]) insertuj(h(i,j));
    }
    int wyn=0;
    FOR(j,qpa) wyn+=syf[j].sz;
    cout<<wyn;
    
    

    return 0;
}