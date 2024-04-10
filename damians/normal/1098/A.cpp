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
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }
#define INF (1<<30)
int par[1<<20];
int s[1<<20];
int rem[1<<20];
int val[1<<20];

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    FOR(i,n-1)
    {
        int x;cin>>x;
        par[i+1]=x-1;
    }
    FOR(i,n)
    {
        int x;cin>>x;
        if (x==-1) rem[i]=1;
        else
        {
            s[i]=x;
        }
    }
    FOR(i,n) val[i]=INF;
    REP(i,1,n-1)
    {
        if (rem[i])
        {

            continue;
        }
        int p=par[par[i]];
        int p1=par[i];
        if (s[p]>s[i])
        {
            //DBG(i);
            //DBG(p);
            cout<<-1;
            return 0;
        }

        //val[i]=;
        val[p1]=min(val[p1], s[i]-s[p]);
    }
    val[0]=s[0];
    REP(i,1,n-1)
    {
        if (rem[i])
        {
            if (val[i]==INF) val[i]=0;
        }
        else
        {
            int p=par[par[i]];
            int p1=par[i];
            val[i]=s[i]-s[p]-val[p1];
        }
    }
    ll sum=0;
    FOR(i,n)sum+=val[i];
    cout<<sum<<"\n";


    return 0;
}