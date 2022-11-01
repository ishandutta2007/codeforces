#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
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
using namespace std;
double a[51][51][51];
ll npok[51][51];
int bas[60];
double sum;
int n,m;

double bern(int k, int s, int r)
{
    if (k>s)
        return 0.0;
    double p=1.0/double(r);
    double w=1.0;
    REP(i,1,s)
    {
        if (i<=k)
            w*=p;
        if (i<=s-k)
            w*=(1-p);
    }
    w*=double(npok[s][k]);
    return w;
}

int main()
{
    cin>>n>>m;
    sum=0;
    FOR(i,51) FOR(j,51) npok[i][j]=0;
    npok[0][0]=1;
    REP(i,1,50)
    {
        npok[i][0]=1;
        npok[i][i]=1;
        REP(j,1,i-1)
            npok[i][j]=npok[i-1][j]+npok[i-1][j-1];
    }
    FOR(i,m)
        cin>>bas[i];
    FOR(i,51) FOR(j,51) FOR(k,51) a[i][j][k]=0.0;
    FOR(i,51) a[0][i][0]=1.0;
    FOR(i,n+1) FOR(j,n+1)
    {
            a[i][0][j]=1.0*(i==(j+bas[0]-1)/bas[0]);
    }
    REP(y,1,m-1) REP(x,1,n) REP(z,1,n)
    {
        REP(i,(x-1)*bas[y]+1,min(z,bas[y]*x))
        {
            REP(k,0,x)
                a[x][y][z]+=bern(i,z,y+1)*a[k][y-1][z-i];
        }
        REP(i,0,min(z,(x-1)*bas[y]))
        {
            a[x][y][z]+=bern(i,z,y+1)*a[x][y-1][z-i];
        }
        
    }
    sum=0.0;
    REP(i,1,n)
    {
        sum+=double(i)*a[i][m-1][n];
    }
    printf("%.18f",sum);
    return 0;
}