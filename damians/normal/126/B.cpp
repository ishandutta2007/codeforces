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

#define DBG(vari) cerr<<#vari<<" = "<<vari<<endl;

#define DBG2(v1,v2) cerr<<(v1)<<" - "<<(v2)<<endl;

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



vi fpref(string s)

{

    vi pr(s.sz);

    pr[0]=0;

    int t=0;

    REP(i,1,s.sz-1)

    {

        if (s[i]==s[t])

        {

            t++;

            pr[i]=t;

        }

        else

        {

            while(t>0)

            {

                t=pr[t-1];

                if (s[t]==s[i])

                {

                    t++;

                    break;

                }

            }

            pr[i]=t;

        }

    }

    return pr;

}





int main()

{

    ios_base::sync_with_stdio(0);
    string s;cin>>s;
    //wyn=0;
    vi v=fpref(s);
    int mx=0;
    REP(i,1,int(v.sz)-2) mx=max(mx,v[i]);
    int n=s.sz;
    int z=v[n-1];
    while(z>mx)
    {
        z=v[z-1];
    }
    if (z==0)
    {
        cout<<"Just a legend";
        return 0;
    }
    else
    {
        FOR(i,z) cout<<s[i];
    }
    



    return 0;

}