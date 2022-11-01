#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>
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
#define DBG2(v1,v2) cout<<(v1)<<" - "<<(v2)<<endl;
#define CZ(x) scanf("%d",&(x))
using namespace std;
char g[20][20][20];
char odw[20][20][20];
int k,n,m;
int ile;
void dfs(int a,int b,int c)
{
    if (odw[a][b][c]) return;
    if (g[a][b][c]=='#') return;
    ile++;
    odw[a][b][c]=1;
    REP(i,-1,1) REP(j,-1,1) REP(l,-1,1)
    {
        int a0=a+i,b0=b+j,c0=c+l;
        if (a0>=0 && a0<k && b0>=0 && b0<n && c0>=0 && c0<m && (abs(i)+abs(j)+abs(l)==1))
            dfs(a0,b0,c0);
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>k>>n>>m;
    FOR(i,k) FOR(j,n)
    {
        string s;
        cin>>s;
        FOR(l,m) g[i][j][l]=s[l];
    }
    ile=0;
    FOR(i,20) FOR(j,20) FOR(l,20) odw[i][j][l]=0;
    int x,y;
    cin>>x>>y;
    dfs(0,x-1,y-1);
    cout<<ile<<endl;
    
    return 0;
}