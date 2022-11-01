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
#define LOLDBG1
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

string d[1001];
char kier[200000];
int len[200000];
int sumx[1001][1001];
int sumy[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;cin>>n>>m;
    FOR(i,n) cin>>d[i];
    int k;cin>>k;
    FOR(i,k) cin>>kier[i]>>len[i];
    FOR(i,n)
    {
        sumx[i][0]=0;
        REP(j,1,m) sumx[i][j]=sumx[i][j-1]+(d[i][j-1]!='#');
    }
    FOR(i,m)
    {
        sumy[i][0]=0;
        REP(j,1,n) sumy[i][j]=sumy[i][j-1]+(d[j-1][i]!='#');
    }
    vector<char> ok;
    FOR(i1,n) FOR(i2,m)
    {
        if (!isupper(d[i1][i2])) continue;
        int a=i1,b=i2;
        int sm;
        bool zle=0;
        FOR(j,k)
        {
            //DBG(j);
            //DBG(k);
            //DBG2(a,b);
            if (kier[j]=='N')
            {
                //DBG(a-len[j]);
                //DBG(len[j]);
                if (a-len[j]<0)
                {zle=1;break;
                }
                sm=sumy[b][a]-sumy[b][a-len[j]];
                //DBG(sm);
                if (sm!=len[j])
                {
                    zle=1;
                    break;
                }
                a=a-len[j];
                DBG(a);
            }
            if (kier[j]=='S')
            {
                if (a+len[j]>=n)
                {zle=1;break;
                }
                sm=sumy[b][a+len[j]+1]-sumy[b][a+1];
                if (sm!=len[j])
                {
                    zle=1;
                    break;
                }
                a=a+len[j];
            }
            if (kier[j]=='E')
            {
                if (b+len[j]>=m)
                {zle=1;break;
                }
                sm=sumx[a][b+len[j]+1]-sumx[a][b+1];
                if (sm!=len[j])
                {
                    zle=1;
                    break;
                }
                b=b+len[j];
            }
            if (kier[j]=='W')
            {
                if (b-len[j]<0)
                {zle=1;break;
                }
                sm=sumx[a][b]-sumx[a][b-len[j]];
                if (sm!=len[j])
                {
                    zle=1;
                    break;
                }
                b=b-len[j];
            }
            DBG(j);
        }
        if (!zle) ok.pb(d[i1][i2]);
    }
    sort(ALL(ok));
    if (!ok.sz) cout<<"no solution";
    else
    {
        FOR(j,ok.sz) cout<<ok[j];
    }

    return 0;
}