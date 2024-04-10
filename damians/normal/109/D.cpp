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

int t[100003];

bool luck(int x)
{
    stringstream ss;
    ss<<x;
    string s=ss.str();
    FOR(j,s.sz) if (s[j]!='4' && s[j]!='7') return 0;
    return 1;
}

vector<pii> v;

vector<pii> ciag;

vector<pii> wyn;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    FOR(i,n) cin>>t[i];
    int lu=-1;
    bool so=1;
    FOR(i,n)
    {
        if (i<n-1 && t[i]>t[i+1]) so=0;
        if (luck(t[i])) lu=i;
    }
    if (!so && lu==-1)
    {
        cout<<-1;
        return 0;
    }
    FOR(i,n) v.pb(mp(t[i],i));
    sort(ALL(v));
    ciag.resize(n);
    FOR(i,n) ciag[v[i].se]=mp(v[i].fi,i);
    //DBG(ciag);
    queue<int> Q;
    FOR(i,n) Q.push(i);
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        if (ciag[u].se==u) continue;
        if (u==lu) continue;
        if (ciag[u].se==lu)
        {
            if (ciag[u].fi!=ciag[lu].fi) wyn.pb(mp(u,lu));
            swap(ciag[u],ciag[lu]);
            lu=u;
        }
        else
        {
            int x=ciag[u].se;
            Q.push(lu);
            Q.push(u);
            Q.push(x);
            if (ciag[x].fi!=ciag[lu].fi) wyn.pb(mp(x,lu));
            swap(ciag[x],ciag[lu]);
            if (ciag[u].fi!=ciag[x].fi) wyn.pb(mp(u,x));
            swap(ciag[u],ciag[x]);
            lu=u;
        }
    }
    //DBG(ciag);
    cout<<wyn.sz<<"\n";
    FORE(j,wyn) cout<<j->fi+1<<" "<<j->se+1<<"\n";
    

    return 0;
}