#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define LOLDBG
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
#define MAXNODE 100000
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

map<unsigned int,int> m;

inline int wez(unsigned int x)
{
    map<unsigned int,int>::iterator it=m.find(x);
    if (it==m.end()) return 0;
    return it->se;
}

double go(int mx, unsigned int u)
{
    int s=wez(u);
    if (mx>=s) return mx;
    int l=wez(2*u),r=wez(2*u+1);
    return 0.5*(go(max(mx,s-l),2*u)+go(max(mx,s-r),2*u+1));
}

int main()
{
    //os_base::sync_with_stdio(0);
    int h,q;
    CZ2(h,q);
    FOR(sfsd,q)
    {
        char s[10];
        scanf("%s",s);
        if (s[0]=='a')
        {
            int v,e;
            CZ2(v,e);
            while(v) {m[v]+=e;v/=2;}
        }
        else
            printf("%.10f\n",go(0,1));
    }

    return 0;
}