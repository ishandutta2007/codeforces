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

vector<string> v;
int dx[]={1,1,-1,-1,0,0,1,-1,0};
int dy[]={-1,1,-1,1,-1,1,0,0,0};
set<vector<string> > st;

int main()
{
    ios_base::sync_with_stdio(0);
    v.resize(8);
    FOR(i,8) cin>>v[i];
    v[0][7]='.';
    deque<vector<string> > Q;
    Q.push_back(v);
    int cnt=0;
    while(!Q.empty())
    {
        cnt++;
        vector<string> b=Q.front();Q.pop_front();
        if (IN(b,st)) continue;
        st.insert(b);
        if (b[0][7]=='M')
        {
            cout<<"WIN";
            return 0;
        }

        int x,y;
        FOR(i,8) FOR(j,8) if (b[i][j]=='M') {x=i;y=j;}
        FOR(k,9)
        {
            int x1=x+dx[k],y1=y+dy[k];
            if (x1<0 || y1<0 || x1>=8 || y1>=8) continue;
            if (b[x1][y1]=='S') continue;
            if (x1 && b[x1-1][y1]=='S') continue;
            vector<string> h=b;
            h[x][y]='.';
            h[x1][y1]='M';
            FOR(i,8) if (h[7][i]=='S') h[7][i]='.';
            FOR(i,8) REPD(j,6,0)
            {
                if (h[j][i]=='S')
                {
                    h[j+1][i]='S';
                    h[j][i]='.';
                }
            }
            Q.push_back(h);
        }
    }
    cout<<"LOSE";

    return 0;
}