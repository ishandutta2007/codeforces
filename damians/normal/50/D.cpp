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
int N,K;
int p[1000][2];
double eps;
double R;
double pr[200][200];
double d[200];

void czysc()
{
    FOR(i,200) FOR(j,200) pr[i][j]=-1.0;
}

double dist(pair<double,double> A, pair<double,double> B)
{
    return sqrt((A.fi-B.fi)*(A.fi-B.fi)+(A.se-B.se)*(A.se-B.se));
}

double prob(double D)
{
    if (D<=R) return 1.0;
    if (R==0.0) return 0.0;
    return exp(1-pow(D/R,2));
}

double go(int ile,int h)
{
    if (pr[ile][h]!=-1.0)
        return pr[ile][h];
    if (ile>h) return 0.0;
    if (ile==0 && h==0) return 1.0;
    double w=0.0;
    if (ile>0)
        w+=go(ile-1,h-1)*prob(d[h]);
    w+=go(ile,h-1)*(1.0-prob(d[h]));
    pr[ile][h]=w;
    return w;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin>>N;
    int ep;
    cin>>K>>ep;
    eps=1.0-0.001*ep;
    FOR(i,N+1)
    {
        cin>>p[i][0]>>p[i][1];
        if (i!=0)
        {
            p[i][0]-=p[0][0];
            p[i][1]-=p[0][1];
        }
        d[i]=dist(mp(p[i][0],p[i][1]),mp(0.0,0.0));
        //DBG(d[i]);
    }
    double lo=0.0,hi=20000.0,mid;
    double prawd;
    //R=1.0;
    //czysc();
    //DBG(go(1,2));
    while(hi-lo>1e-11)
    {
        prawd=0.0;
        mid=(lo+hi)*0.5;
        R=mid;
        czysc();
        REP(l,K,N) prawd+=go(l,N);
        //DBG(prawd);
        if (prawd>eps)
            hi=mid;
        else
            lo=mid;
    }
    printf("%.10f\n",mid);
    
    
    return 0;
}