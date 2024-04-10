#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FORE(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define un(v) v.erase(unique(ALL(v)),v.end())
#define LOLDBG1
#ifdef LOLDBG
#define DBG(vari) cerr<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cerr<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define CZ3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z));
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

char s[2000005];

int main()
{
    ios_base::sync_with_stdio(0);
    int n,r;
    CZ2(n,r);
    if (n==1 && r==1)
    {
        puts("0\nT");
        return 0;
    }
    int best=2000000;
    int J;
    REP(j,1,r)
    {
        if (__gcd(j,r)!=1) continue;
        int wyn=0;
        int dl=0;
        int z;
        int A=r,B=j;
        while(A>1 || B>1)
        {
            //DBG(mp(A,B));
            z=A/B;
            wyn+=z-1;
            dl+=z;
            A%=B;
            swap(A,B);
        }
        if (wyn<best && dl==n)
        {
            best=wyn;
            J=j;
        }
    }
    if (best==2000000) 
    {
        puts("IMPOSSIBLE");
        return 0;
    }
    vi v;
    {
        int A=r,B=J;
        while(A>1 || B>1)
        {
            DBG(mp(A,B));
            int z=A/B;
            v.pb(z);
            A%=B;
            swap(A,B);
        }

    }
    if (v.sz) v.back()--;
    reverse(ALL(v));
    string g="TB";
    {
        printf("%d\n",best-1);
        printf("T");
        int mode=1;
        FOR(j,v.sz)
        {
            FOR(k,v[j]) printf("%c",g[mode]);
            mode=1-mode;
        }
        
    }

    return 0;
}