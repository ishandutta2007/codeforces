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
int d1[800][800],d2[800][800],d3[800][800];
int n,m;

int main()
{
    ios_base::sync_with_stdio(0);
    CZ(n);CZ(m);
    int a,b;
    FOR(i,800) FOR(j,800) d1[i][j]=d2[i][j]=d3[i][j]=0;
    FOR(i,m)
    {
        CZ(a);CZ(b);
        a--;b--;
        d1[a][b]=d1[b][a]=1;
    }
    FOR(i,n) FOR(j,n) FOR(k,n)  d2[i][j]+=d1[i][k]*d1[k][j];
    FOR(i,n) FOR(j,n) FOR(k,n) if (k!=i && k!=j) d3[i][j]+=(d2[i][k]-d1[i][j]*d1[j][k])*d1[k][j];
    //FOR(i,n) FOR(j,n) d3[i][j]-=d1[i][j]*d2[j][j]+d2[i][i]*d1[i][j];
    //FOR(i,n) FOR(j,n) cout<<i<<" "<<j<<" "<<d2[i][j]<<endl;
    //cout<<endl; 
    //FOR(i,n) FOR(j,n) cout<<i<<" "<<j<<" "<<d3[i][j]<<endl;
    ll w=0;
    FOR(i,n) REP(j,i+1,n-1)
    {
        if (i==j) continue;
        w+=d2[i][j]*d3[i][j];
        FOR(k,n)
        {
            if (k!=i && k!=j) w-=d1[j][k]*d1[k][i]*(d2[k][i]-d1[k][j]*d1[j][i]+d2[j][k]-d1[j][i]*d1[i][k]);
        }
    }
    cout<<w/5<<endl;
    return 0;
}