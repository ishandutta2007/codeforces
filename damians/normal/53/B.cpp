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


int main()
{
    ios_base::sync_with_stdio(0);
    ll h,w;
    cin>>h>>w;
    ll best=0,h1,w1;
    ll k=1,l;
    while (k<=h)
    {
        l=min(w,k*5/4);
        if (l*k>=best && 5*l>=4*k)
        {
            best=l*k;
            h1=k;
            w1=l;
        }
        k*=2;
    }
    k=1;
    while (k<=w)
    {
        l=min(h,k*5/4);
        if (l*k>=best && 5*l>=4*k)
        {
            best=l*k;
            h1=l;
            w1=k;
        }
        k*=2;
    }
    cout<<h1<<" "<<w1;
    return 0;
}