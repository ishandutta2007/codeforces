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

bool sw=0;
int n,m;

int wyn[200][200];

void wyp()
{
    if (!sw)
    {
        FOR(i,n) {FOR(j,m) cout<<wyn[i][j]<<" ";cout<<endl;}
    }
    else
    {
        FOR(i,m) {FOR(j,n) cout<<wyn[j][i]<<" ";cout<<endl;}
    }
    
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin>>n>>m;
    
    if (n>m)
    {
        sw=1;
        swap(n,m);
    }
    if (n==1)
    {
        if (m==1)
        {
            cout<<1;
            return 0;
        }
        if (m<=3)
        {
            cout<<-1;
            return 0;
        }
        if (m==4)
        {
            wyn[0][0]=3;
            wyn[0][1]=1;
            wyn[0][2]=4;
            wyn[0][3]=2;
            wyp();
        }
        int ind=0;
        for(int j=1;j<=m;j+=2) wyn[0][ind++]=j;
        for(int j=2;j<=m;j+=2) wyn[0][ind++]=j;
        wyp();
    }
    if (n==2)
    {
        if (m<=2)
        {
            cout<<-1;
            return 0;
        }
        if (m==3)
        {
            wyn[0][0]=5;
            wyn[0][1]=1;
            wyn[0][2]=4;
            wyn[1][0]=3;
            wyn[1][1]=6;
            wyn[1][2]=2;
            wyp();
        }
    }
    int a=0,b=0;
    for(int j=1;j<=n*m;j+=2)
    {
        wyn[a][b]=j;
        a++;
        if (a==n)
        {
            b++;
            a=0;
        }
    }
    for(int j=2;j<=n*m;j+=2)
    {
        wyn[a][b]=j;
        a++;
        if (a==n)
        {
            b++;
            a=0;
        }
    }
    wyp();
    
    

    return 0;
}