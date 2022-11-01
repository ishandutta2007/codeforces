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

map<string,int> ile;
int vow[300];

int cnt(string g)
{
    int w=0;
    FOR(i,g.sz) w+=vow[g[i]];
    return w;
}

int main()
{
    ios_base::sync_with_stdio(0);
    vow['e']=1;
    vow['i']=1;
    vow['o']=1;
    vow['u']=1;
    vow['a']=1;
    int n,k;
    cin>>n>>k;
    FOR(i,n)
    {
        string s[4];
        FOR(j,4) cin>>s[j];
        int sam[4];
        FOR(j,4) sam[j]=cnt(s[j]);
        bool ok=1;
        FOR(j,4)
        {
            if (sam[j]<k) ok=0;
        }
        if (!ok) break;
        FOR(j,4)
        {
            int z=s[j].sz;
            int mam=0;
            while(mam<k)
            {
                z--;
                mam+=vow[s[j][z]];
            }
            s[j]=s[j].substr(z);
        }
        if (s[0]==s[1] && s[2]==s[3]) ile["aabb"]++;
        if (s[0]==s[3] && s[2]==s[1]) ile["abba"]++;
        if (s[0]==s[2] && s[1]==s[3]) ile["abab"]++;
        if (s[0]==s[1] && s[2]==s[3] && s[2]==s[1]) ile["aaaa"]++;
    }
    if (ile["aaaa"]==n)
    {
        cout<<"aaaa";
        return 0;
    }
    FORE(i,ile)
    {
        if (i->se==n) {cout<<i->fi;return 0;}
    }
    cout<<"NO";

    return 0;
}