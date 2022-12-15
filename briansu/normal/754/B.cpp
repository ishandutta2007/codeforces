#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(i,n) memset(i,n,sizeof(i));
#define X first
#define Y second
#define pb push_back
#ifdef brian
#define  debug(...) do{\
    fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename t> void _do(t &&x){cerr<<x<<endl;}
template<typename t,typename ...T> void _do(t &&x,T &&...tail){cerr<<x<<", ";_do(tail...);}
#else
#define debug(...)
#endif // brian

const ll INF=ll(1e18);

const ll MAXn=500005;
const ll MAXlg=19;

ll d[6][6];
ll dx[4][2]={{-1,1},{-1,1},{-1,1},{0,0}};
ll dy[4][2]={{-1,1},{0,0},{1,-1},{1,-1}};

bool ck()
{
    debug(1);
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(d[i][j]!=1)continue;
            REP(k,4)
            {
                if(d[i+dx[k][0]][j+dy[k][0]]==1&&
                   d[i+dx[k][1]][j+dy[k][1]]==1)return 1;
            }
        }
    }
    return 0;
}
int main()
{
    for(int i=1;i<=4;i++)
    {
        string s;
        cin>>s;
        stringstream ss(s);
        for(int j=1;j<=4;j++)
        {
            char c;
            ss>>c;
            assert(c=='.'||c=='x'||c=='o');
            if(c=='.')d[i][j]=0;
            else if(c=='x')d[i][j]=1;
            else d[i][j]=2;
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(d[i][j]!=0)continue;
            d[i][j]=1;
            if(ck())
            {
                cout<<"YES"<<endl;
                return 0;
            }
            d[i][j]=0;
        }
    }
    cout<<"NO"<<endl;


}