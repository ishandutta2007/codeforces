#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
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
#define CZ(x) scanf("%d",&(x))
#define M 10000000
using namespace std;

int p[21000000];
int l;

int nwd(int a,int b)
{
    return (a==0?b:nwd(b%a,a));
}

int zn(int x)
{
    if (x==p[x]) return x;
    p[x]=zn(p[x]);
    return p[x];
}

void unia(int x,int y)
{
    if (zn(x)==zn(y)) return;
    if ((l++)&1) p[p[y]]=p[x];
    else p[p[x]]=p[y];
}

int main()
{
    FOR(i,M+2) p[i]=-1;
    int n;
    l=0;
    CZ(n);
    int x0;
    FOR(i,n)
    {
        CZ(x0);
        p[x0]=x0;
    }
    int x,y,z;
    for(int b=1;b*b<=M/2;b++) for(int a=b+1;a*a<=2*M;a++)
    {
        if (a%2==0 && b%2==0) continue;
        if (a&1 && b&1) continue;
        if (nwd(a,b)==1)
        {
            x=a*a-b*b;
            y=2*a*b;
            z=a*a+b*b;
            if (x<=M && y<=M && p[x]>=0 && p[y]>=0) unia(x,y);
            if (z<=M && p[x]>=0 && p[z]>=0) unia(x,z);
            if (z<=M && p[y]>=0 && p[z]>=0) unia(y,z);
        }
    }
    int wyn=0;
    FOR(i,M+1)
        if (i==p[i]) wyn++;
    
    cout<<wyn<<endl;
    return 0;
}