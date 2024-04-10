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



int row1[3000];
int col1[3000];
int row2[3000];
int col2[3000];

string d[3000];



int main()

{

    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    FOR(i,n) cin>>d[i];
    FOR(i,n) FOR(j,n) d[i][j]-='0';
    int wyn=0;
    FOR(i,n-1)
    {
        REP(j,0,i)
        {
            //DBG(mp(n-i+j-1,j));
            int x=j;
            int y=n-i+j-1;
            if ((row1[x]+col1[y]+d[x][y])%2)
            {
                wyn++;
                row1[x]++;
                col1[y]++;
            }
        }
    }
    FOR(i,n-1)
    {
        REP(j,0,i)
        {
            //DBG(mp(n-i+j-1,j));
            int x=j;
            int y=n-i+j-1;
            swap(x,y);
            if ((row2[x]+col2[y]+d[x][y])%2)
            {
                wyn++;
                row2[x]++;
                col2[y]++;
            }
        }
    }
    FOR(i,n)
    {
        if ((row1[i]+row2[i]+col1[i]+col2[i]+d[i][i])%2) wyn++;
    }
    cout<<wyn;
    

    

    return 0;

}