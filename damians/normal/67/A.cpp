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
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

int t[2000];

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    FOR(i,n) t[i]=1;
    REP(i,1,10000)
    {
        REP(j,1,n-1)
        {
            if (s[j-1]=='R' && t[j]<=t[j-1]) t[j]++;
            if (s[j-1]=='=' && t[j]<t[j-1]) t[j]++;
        }
        REPD(j,n-1,1)
        {
            if (s[j-1]=='L' && t[j]>=t[j-1]) t[j-1]++;
            if (s[j-1]=='=' && t[j]>t[j-1]) t[j-1]++;
        }
        
        
    }
    //DBG(vector<int>(t,t+n));
    FOR(i,n) cout<<t[i]<<" ";

    return 0;
}