#include <string>
#include <vector>
#include <algorithm>
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
#define LOLDBG1
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
#define M 500
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

int x[200],y[200];
int pos[1000][1000];

int x0,y0,d,n;

bool DFS(int x1, int y1)//wygr?
{
    DBG(x1-M);DBG(y1-M);
    if ((x1-M)*(x1-M)+(y1-M)*(y1-M)>d*d) return 1;
    if (pos[x1][y1]==1) return 0;
    if (pos[x1][y1]==2) return 1;
    int ile=0,iled=0;
    FOR(i,n)
    {
        ile++;
        iled+=DFS(x1+x[i],y1+y[i]);
    }
    if (x1-M==1 && y1-M==2) {DBG(ile);DBG(iled);}
    if (iled==ile)
    {
        pos[x1][y1]=1;
        return 0;
    }
    else
    {
        pos[x1][y1]=2;
        return 1;
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    
    cin>>x0>>y0>>n>>d;
    FOR(i,n) cin>>x[i]>>y[i];
    FOR(i,2*M) FOR(j,2*M) pos[i][j]=0;
    if (!DFS(M+x0,M+y0)) cout<<"Dasha"<<endl;
    else cout<<"Anton"<<endl;
    

    return 0;
}