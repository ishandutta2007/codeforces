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
#define FOR(i,v)REP(i,0,(int)(v)-1)
#define FORD(i,v)REPD(i,(int)(v)-1,0)
#define pb push_back
#define sz size
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define ALL(x) (x).begin(),(x).end()
using namespace std;
int n,m,a,b;
int pl[300][300];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    FOR(i,n) FOR(j,m) cin>>pl[i][j];
    cin>>a>>b;
    int mn=100000000;
    FOR(i,n) FOR(j,m)
    {
        if (!(i+a<=n && j+b<=m)) continue;
        int licz=0;
        REP(k,i,i+a-1) REP(l,j,j+b-1) licz+=pl[k][l];
        mn=min(mn,licz);
    }
    
    swap(a,b);

    FOR(i,n) FOR(j,m)
    {
        if (!(i+a<=n && j+b<=m)) continue;
        int licz=0;
        REP(k,i,i+a-1) REP(l,j,j+b-1)
         licz+=pl[k][l];
        
        mn=min(mn,licz);
    }
    cout<<mn<<endl;
    
    return 0;
}