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
#define FOR(i,v)for(int i=0;i<v;i++)
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
using namespace std;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

int n;
ll x[20000],y[20000],z[20000];
double czas[20000];
double czasp[20000];
ll px,py,pz;
double vs,vp;

double dist(double x1, double y1, double z1,double x2, double y2, double z2)
{
    return sqrt(pow(x1-x2,2.0)+pow(y1-y2,2.0)+pow(z1-z2,2.0));
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    n++;
    DBG(n);
    FOR(i,n) cin>>x[i]>>y[i]>>z[i];
    cin>>vp>>vs;
    DBG(vp);
    cin>>px>>py>>pz;
    czas[0]=0.0;
    DBG(x[1]);
    DBG(vs);
    
    FOR(i,n-1) {DBG(dist(x[i],y[i],z[i],x[i+1],y[i+1],z[i+1]));czas[i+1]=czas[i]+dist(x[i],y[i],z[i],x[i+1],y[i+1],z[i+1])/vs;DBG(vs);DBG(dist(x[i],y[i],z[i],x[i+1],y[i+1],z[i+1])/vs);}
    FOR(i,n) czasp[i]=dist(x[i],y[i],z[i],px,py,pz)/vp;


    double bdist=1e20;
    double xb,yb,zb,tb;
    FOR(k,n-1)
    {
        double v0=x[k+1]-x[k],v1=y[k+1]-y[k],v2=z[k+1]-z[k];
        double cz=czas[k+1]-czas[k],cz0=0,cz1=cz,czm;
        DBG(cz0);
        DBG(cz1);
        double x0=x[k],y0=y[k],z0=z[k],x1=x[k+1],y1=y[k+1],z1=z[k+1],x2,y2,z2;
        int z=80;
        while(z--)
        {
            DBG(czm);
            czm=(cz1+cz0)*0.5;
            x2=x0+v0*czm/cz;
            y2=y0+v1*czm/cz;
            z2=z0+v2*czm/cz;
            if (dist(px,py,pz,x2,y2,z2)/(vp)<czas[k]+czm) cz1=czm;
            else cz0=czm;
        }
        DBG(czas[k]+cz0);
        if (abs(dist(px,py,pz,x2,y2,z2)/(vp)-czas[k]-czm)<bdist)
        {
            bdist=abs(dist(px,py,pz,x2,y2,z2)/(vp)-czas[k]-czm);
            tb=czas[k]+cz0;
            xb=x0+v0*cz0/cz;
            yb=y0+v1*cz0/cz;
            zb=z0+v2*cz0/cz;
        }
    }
    if (bdist<1e-9)
    {
        printf("YES\n");
        printf("%.10f\n",tb);
        printf("%.10f %.10f %.10f\n",xb,yb,zb);
    }
    else
    {
        puts("NO");
    }
    
    
    
    

    return 0;
}