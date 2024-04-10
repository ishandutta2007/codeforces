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
#define LOLDBG1
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
map<int,char> m;
int n;



int main()
{
    ios_base::sync_with_stdio(0);
    string s;cin>>s;
    n=s.sz;
    m[0]=0;
    m[n+1]=0;
    REP(i,1,n) m[i]=s[i-1];
    map<int,char>::iterator it,it1;
    int go=1;

    while(1)
    {
        if (go==n+1) break;
        it=m.find(go);
        it1=m.find(go);
        it1++;
        int a=it->fi;
        int b=it1->fi;
        //DBG(it->se);
        //DBG(it1->se);
        if (it->se == it1->se)
        {
            m.erase(a);
            m.erase(b);
            it=m.lower_bound(a);
            it--;
            go=it->fi;
        }
        else
        {
            go=b;
        }
    }
    REP(i,1,n)
    {
        if (IN(i,m)) cout<<m[i];
    }
    

    return 0;
}