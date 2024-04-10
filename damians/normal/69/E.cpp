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

int a[110000];
map<int,int> ile;
set<int,greater<int> > jed;

void pisz()
{
    if (jed.empty()) cout<<"Nothing"<<endl;
    else cout<<*(jed.begin())<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    FOR(i,n) cin>>a[i];
    FOR(i,k) ile[a[i]]++;
    FOR(i,k) if (ile[a[i]]==1) jed.insert(a[i]);
    pisz();
    REP(i,k,n-1)
    {
        ile[a[i]]++;
        ile[a[i-k]]--;
        if (ile[a[i]]==1) jed.insert(a[i]); else jed.erase(a[i]);
        if (ile[a[i-k]]==1) jed.insert(a[i-k]); else jed.erase(a[i-k]);
        pisz();
    }
    
    return 0;
}