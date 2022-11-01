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
#define LOLDBG1
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


#define INF (1LL<<49)
vector<ll> opt;
vector<vector<pair<int,ll> > > kr; // (do, koszt)
priority_queue<pair<ll,int> > Q;
vector<bool> dod;
int n;//ile wierzcholkow
set<ll> s[100001];
void czysc(int n1){n=n1;dod.clear();dod.resize(n,0);kr.clear();kr.resize(n);opt.clear();opt.resize(n,INF);}
inline void dod_kr(int skad, int dokad, int koszt){kr[skad].pb(mp(dokad,koszt));}

void dijkstra(int zrodlo)
{
    FOR(i,n) dod[i]=0;
    FOR(i,n) opt[i]=INF;
    opt[zrodlo]=0;
    Q.push(mp(0,zrodlo));
    while(!Q.empty())
    {
        int p=(Q.top()).se;
        
        if (dod[p]) 
        {
            Q.pop();
            continue;
        }
        opt[p]=-((Q.top()).fi);
        Q.pop();
        dod[p]=1;
        ll z=opt[p];
        DBG(p);
        DBG(opt[p]);
        while(IN(z,s[p])) z++;
        DBG(z);
        FOR(i,kr[p].sz)
        {
            if (!dod[kr[p][i].fi] && (opt[kr[p][i].fi]>z+kr[p][i].se))
            {
                opt[kr[p][i].fi]=z+kr[p][i].se;
                Q.push(mp(-opt[kr[p][i].fi],kr[p][i].fi));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;CZ(n);int m;CZ(m);
    czysc(n);
    FOR(i,m)
    {
		int a,b,c;
		CZ3(a,b,c);
		a--;b--;
		dod_kr(a,b,c);
		dod_kr(b,a,c);
	}
	FOR(i,n)
	{
		int k;CZ(k);
		FOR(j,k)
		{
			int a;CZ(a);
			s[i].insert(a);
		}
	}
	dijkstra(0);
	if (opt[n-1]<INF) cout<<opt[n-1];
	else cout<<-1;
    
    return 0;
}