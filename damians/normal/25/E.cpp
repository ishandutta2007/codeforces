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

bool kmp(string t, string p) { // text, pattern | zwraca 0-based indeksy trafien wzorca
   vi kn(p.sz+1,-1); // funkcja prefiksowa Knutha
   REP(i,1,p.sz) {
      int j = kn[i-1];
      while (j != -1 && p[j] != p[i-1]) j=kn[j];
      kn[i] = j+1;
   }
   int ppos=0,tpos=0;
   while (tpos<t.sz) {
      while (ppos!=-1 && (ppos == p.sz || p[ppos]!=t[tpos])) ppos=kn[ppos];
      ppos++;
      tpos++;
      if (ppos==p.sz) return 1;
   }
   return 0;
}

string lacz(string a,string b)
{
    int best=0;
    unsigned h1=0,h2=0,pot=1;
    int a1=a.sz-1,b1=0;
    while(a1>=0 && b1<b.sz)
    {
        h1=h1*29+a[a1];
        h2=h2+pot*b[b1];
        pot*=29;
        a1--;
        b1++;
        if (h1==h2) best=b1;
    }
    string wyn=a;
    REP(i,best,b.sz-1) wyn+=b[i];
    return wyn;
}

vector<string> s;

int main()
{
    ios_base::sync_with_stdio(0);
    s.resize(3);
    FOR(i,3) cin>>s[i];
    REPD(i,2,0)
    {
        FOR(j,s.sz) if (i!=j && kmp(s[j],s[i]))
        {
            s.erase(s.begin()+i);
            break;
        }
    }
    int per[3]={0,1,2};
    sort(ALL(s));
    int best=1000000000;
    while(1)
    {
        string g="";
        //DBG(s);
        FOR(j,s.sz)
        {
            g=lacz(g,s[j]);
            //DBG(g);
        }
        REMIN(best,int(g.sz));
        if (!next_permutation(ALL(s))) break;
    }
    cout<<best;
    

    return 0;
}