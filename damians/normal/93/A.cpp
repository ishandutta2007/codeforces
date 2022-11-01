#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
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
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }



int main()
{
    ios_base::sync_with_stdio(0);
    ll n,m,a,b;
    cin>>m>>n>>a>>b;
    if (n==1)
    {
        cout<<1<<endl;
            return 0;
    }
    if (b==m)
    {
        if ((b-1)/n == (a-1)/n || a%n==1)
        {
            cout<<1<<endl;
            return 0;
        }
        cout<<2<<endl;
            return 0;
        
    }
    ll c=0,d=0,x;
    DBG(a);
    DBG(b);
    DBG(n);
    if (a%n!=1)
    {
        if (a%n==0)
        {
            d=1;
        }
        else
            d=(n-(a%n))+1;
        a+=d;
        DBG(d);
    }
    if (b%n!=0)
    {
        c=b%n;
        b-=c;
        DBG(c);
    }
    x=b-a+1;
    DBG(x);
    if (x>0)
    {
        if (c==0 && d==0)
        {
            cout<<1<<endl;
            return 0;
        }
        DBG(c);
        DBG(d);
        if (c+d==n || d==0 || c==0)
        {
            cout<<2<<endl;
            return 0;
        }
        cout<<3<<endl;
        return 0;
    }
    else if (x==0)
    {
        if (c==0 || d==0)
        {
            cout<<1<<endl;
            return 0;
        }
        cout<<2<<endl;
        return 0;
    }
    else
    {
        cout<<1<<endl;
        return 0;
    }

    return 0;
}