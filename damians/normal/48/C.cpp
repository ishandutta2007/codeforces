#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
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
#define EPS 1e-8
using namespace std;
int n;
int st[3000];

int al(double a)
{
    double mam=a;
    int nr=0;
    FOR(i,n)
    {
        nr=nr+floor(mam);
        mam=mam-floor(mam)+a;
        if (nr<st[i]) return -1;
        if (nr>st[i]) return 1;
    }
    return 0;
}

int rub(double a)
{
    double mam=a;
    int nr=0;
    FOR(i,n+1)
    {
        nr=nr+floor(mam);
        mam=mam-floor(mam)+a;
    }
    return nr;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    FOR(i,n) cin>>st[i];
    double lo,hi,mid,lewy,prawy;
    lo=1.0;hi=1000000.0;
    while(hi-lo>1e-9)
    {
        mid=0.5*(hi+lo);
        if (al(mid)>=0)
            hi=mid;
        else
            lo=mid;
    }
    lewy=mid+EPS;
    lo=1.0;hi=1000000.0;
    while(hi-lo>1e-9)
    {
        mid=0.5*(hi+lo);
        if (al(mid)<=0)
            lo=mid;
        else
            hi=mid;
    }
    prawy=mid-EPS;
    //printf("%.10f\n",lewy);printf("%f\n",prawy);
    if (rub(lewy)==rub(prawy))
    {
        cout<<"unique"<<endl;
        cout<<rub(lewy)<<endl;
    }
    else
        cout<<"not unique"<<endl;
    
    return 0;
}