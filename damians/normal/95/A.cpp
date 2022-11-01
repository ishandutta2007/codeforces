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
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

vector<string> zle;
bool wyw[100000];
string s;

bool duza(char c)
{
    return (c>='A' && c<='Z');
}

bool mala(char c)
{
    return (c>='a' && c<='z');
}

string male(string g)
{
    FOR(i,g.sz) if (duza(g[i])) g[i]+='a'-'A';
    return g;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    zle.resize(n);
    FOR(i,n) cin>>zle[i];
    cin>>s;
    char t;cin>>t;
    char T=t+'A'-'a';
    FOR(i,n)
    {
        string g=male(zle[i]);
        FOR(i,s.sz) if (male(s.substr(i,g.sz))==g)
        {
            REP(j,i,i+g.sz-1) wyw[j]=1;
        }
    }
    FOR(i,s.sz)
    {
        if (wyw[i])
        {
            if (duza(s[i]))
            {
                if (s[i]!=T)
                {
                    s[i]=T;
                }
                else
                {
                    if (s[i]=='A') s[i]='B';
                    else s[i]='A';
                }
            }
            else
            {
                if (s[i]!=t)
                {
                    s[i]=t;
                }
                else
                {
                    if (s[i]=='a') s[i]='b';
                    else s[i]='a';
                }
            }
        }
    }
    cout<<s;

    return 0;
}