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


int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    
    int a,b,t;
    cin>>n>>m;
    m--;
    FOR(i,n)
    {
        cin>>a>>b>>t;
        if (a==b)
        {
            cout<<t<<"\n";
            continue;
        }
        a--;b--;
        DBG(a);
        vi v1,v2;
        int z=t/(2*m)-1;
        DBG(z);
        int z1=z*2*m+a;
        int z2=z*2*m+2*m-a;
        DBG(z2);
        FOR(j,6)
        {
            v1.pb(z1+j*2*m);
            v1.pb(z2+j*2*m);
        }
        DBG(v1);
        sort(ALL(v1));
        int h;
        FOR(j,v1.sz)
        {
            if (v1[j]>=t)
            {
            h=v1[j];
            break;
            }
        }
        DBG(h);
        v1.clear();
        z=t/(2*m)-2;
        z1=z*2*m+b;
        z2=z*2*m+2*m-b;
        FOR(j,6)
        {
            v1.pb(z1+j*2*m);
            v1.pb(z2+j*2*m);
        }
        sort(ALL(v1));
        DBG(v1);
        FOR(j,v1.sz)
        {
            if (v1[j]>=h)
            {
            h=v1[j];
            break;
            }
        }
        cout<<h<<"\n";
    }
    

    return 0;
}