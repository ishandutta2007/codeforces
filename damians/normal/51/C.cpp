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
#define MIN(a,b) ((a)<(b)?a:b)
#define MAX(a,b) ((a)<(b)?b:a)
using namespace std;
vector<ll> p;
ll M,mn,mx,h1,h2;
set<ll> st;
ll n,b;

bool check(ll d)
{
    if (d>=M) 
    {
        h1=mn;
        h2=mx;
        return 1;
    }
        
       
    h1=*(upper_bound(p.begin(),p.end(),mn+d));
    h2=*(--(lower_bound(p.begin(),p.end(),mx-d)));
    return (h2-h1<=d);
}

int main()
{
    ios_base::sync_with_stdio(0);
    scanf("%d",&n);
    st.insert(-100);
    st.insert(200000000001LL);
    mn=2000000000000LL;
    mx=-1;
    FOR(i,n)
    {
        scanf("%d",&b);
        st.insert(b);
        mn=MIN(mn,b);
        mx=MAX(mx,b);
    }
    for(set<ll>::iterator it=st.begin();it!=st.end();it++)
        p.pb(*it);
    ll lo=0,hi=200000000000LL,mid;
    M=mx-mn;
    //DBG(M);
    while (hi-lo>1)
    {
        mid=(hi+lo)/2;
        if (check(mid))
            hi=mid;
        else lo=mid;
    }
    if (check(lo)) mid=lo; else mid=hi;
    check(mid);
    double D=0.5*mid;
    printf("%.6f\n%.6f %.6f %.6f",D,double(mn)+D,0.5*(h1+h2),double(mx)-D);
    return 0;
}