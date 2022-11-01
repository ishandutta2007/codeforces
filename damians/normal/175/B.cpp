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
#define eps 1e-9
map<string,int> m;
vector<pair<string,int> > v;

int lep(int x)
{
    int w=0;
    FOR(i,v.sz) if (v[i].se>x) w++;
    return w;   
}

int niego(int x)
{
    int w=0;
    FOR(i,v.sz) if (v[i].se<=x) w++;
    return w;  
}
    

bool noob(int x)
{
    int n=v.sz;
    if (lep(x)*1.0/n>0.5) return 1;
    return 0;
}

bool random(int x)
{
    int n=v.sz;
    if (niego(x)*1.0/n>=0.5 && lep(x)*1.0/n>0.2+eps) return 1;
    return 0;
}

bool ave(int x)
{
    int n=v.sz;
    if (niego(x)*1.0/n>=0.8-eps && lep(x)*1.0/n>0.1+eps) return 1;
    return 0;
}


bool hc(int x)
{
    int n=v.sz;
    if (niego(x)*1.0/n>=0.9-eps && lep(x)*1.0/n>0.01+eps) return 1;
    return 0;
}

bool pro(int x)
{
    int n=v.sz;
    if (niego(x)*1.0/n>=0.99-eps) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    FOR(i,n)
    {
        string s;
        int x;
        cin>>s>>x;
        REMAX(m[s],x);
    }
    v=vector<pair<string,int> >(ALL(m));
    cout<<v.sz<<"\n";
    FOR(i,v.sz)
    {
        if (noob(v[i].se)) cout<<v[i].fi<<" noob\n";
        else if (random(v[i].se)) cout<<v[i].fi<<" random\n";
        else if (ave(v[i].se)) cout<<v[i].fi<<" average\n";
        else if (hc(v[i].se)) cout<<v[i].fi<<" hardcore\n";
        else if (pro(v[i].se)) cout<<v[i].fi<<" pro\n";
    }

    return 0;
}