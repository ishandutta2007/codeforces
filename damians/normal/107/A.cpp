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

map<pii,int> tl;
int next[1000];
int indeg[1000];
int outdeg[1000];

int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;cin>>n>>m;
    FOR(i,n) next[i]=-1;
    FOR(i,m)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        indeg[b]++;
        outdeg[a]++;
        tl[mp(a,b)]=c;
        next[a]=b;
    }
    vi tp1,tp2,tp3;
    FOR(i,n)
    {
        if (indeg[i]==0 && outdeg[i])
        {
            int best=1000000000;
            int u=i;
            while(next[u]!=-1)
            {
                REMIN(best,tl[mp(u,next[u])]);
                u=next[u];
            }
            tp1.pb(i+1);
            tp2.pb(u+1);
            tp3.pb(best);
            
        }
    }
    cout<<tp1.sz<<endl;
    FOR(i,tp1.sz) cout<<tp1[i]<<" "<<tp2[i]<<" "<<tp3[i]<<endl;
    

    return 0;
}