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
#define LOLDBG
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

bool zlo[300][300];

int main()
{
    ios_base::sync_with_stdio(0);
    string s;cin>>s;
    int n;cin>>n;
    FOR(i,n)
    {
        string a;cin>>a;
        zlo[a[0]][a[1]]=1;
        zlo[a[1]][a[0]]=1;
    }
    vector<pii> v;
    int j=0;
    int w=0;
    while(j<s.sz)
    {
        int k=1;
        while(j+k<s.sz && (s[j+k-1]==s[j+k] || zlo[s[j+k]][s[j+k-1]])) k++;
        int lit[40]={0};
        FOR(i,k) lit[s[j+i]-'a']++;
        int ile=0;
        int mn=3543644;
        //DBG(mp(j,k));
        FOR(i,40)
        {
            ile+=!!(lit[i]);
            if (lit[i]) REMIN(mn,lit[i]);
        }
        if (ile>1) w+=mn;
        j+=k;
    }

    cout<<w;

    return 0;
}