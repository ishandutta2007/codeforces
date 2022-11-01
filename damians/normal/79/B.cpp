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
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
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

int ile[800000];
vi zle[100000];
int n,m,k,t;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k>>t;
    FOR(i,k)
    {
        int a,b;
        cin>>a>>b;
        zle[a].pb(b);
    }
    REP(i,1,n)
    {
        zle[i].pb(13256346);
        sort(ALL(zle[i]));
        ile[i]=m-zle[i].sz+1;
    }
    FOR(sdgsd,t)
    {
        int a,b;
        cin>>a>>b;
        int s=0;
        REP(i,1,a-1)
        {
            s+=ile[i];
        }
        int k=0;
        bool zlo=0;
        REP(j,1,b)
        {
            if (zle[a][k]==b) zlo=1;
            if (j!=zle[a][k]) s++;
            else k++;
        }
        //DBG(s);
        //DBG(ile[1]);
        s+=2;
        s%=3;
        if (zlo) cout<<"Waste";
        else
        {
            if (s==0) cout<<"Carrots";
            if (s==1) cout<<"Kiwis";
            if (s==2) cout<<"Grapes";
        }
        cout<<endl;
    }

    return 0;
}