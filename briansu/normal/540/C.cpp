#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(i,n) memset(i,n,sizeof(i));
#define SZ(A) ((int)A.size())
#define ALL(A) A.begin(),A.end()
#define X first
#define Y second
#define pb push_back
#ifdef brian
#define  debug(...) do{\
    fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename t> void _do(t &&_x){cerr<<_x<<endl;}
template<typename t,typename ...T> void _do(t &&_x,T &&...tail){cerr<<_x<<", ";_do(tail...);}
template<typename _a,typename _b>
ostream& operator <<(ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
#else
#define debug(...)
#define endl '\n'
#endif // brian

const ll INF=ll(1e15);
const ll MAXn=5e2+5,MAXlg=20;
const ll MOD = 1000000007;

ll r,c;
ii f,e;
bool d[MAXn][MAXn];
bool v[MAXn][MAXn];
ll dx[4]={1,-1,0,0};
ll dy[4]={0,0,-1,1};
queue<ii> q;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>r>>c;
    FILL(d,0);
    cin.ignore(1);
    for(int i=1;i<=r;i++)
    {
        string s;
        getline(cin,s);
        stringstream ss(s);
        for(int j=1;j<=c;j++)
        {
            char ch;
            ss>>ch;
            assert(ch=='.'||ch=='X');
            d[i][j]=(ch=='.');
        }
    }
    cin>>f.X>>f.Y;
    cin>>e.X>>e.Y;
    REP(i,4)q.push(ii(f.X+dx[i],f.Y+dy[i]));
    while(q.size())
    {
        while(q.size()&&(v[q.front().X][q.front().Y]||(!d[q.front().X][q.front().Y]&&ii(q.front().X,q.front().Y)!=e)))q.pop();
        if(q.empty())break;
        ii tmp=q.front();
        ll x=tmp.X,y=tmp.Y;
        q.pop();
        v[x][y]=1;
        if(tmp==e)break;
        REP(i,4)
        {
            if(!v[x+dx[i]][y+dy[i]]&&(d[x+dx[i]][y+dy[i]]||ii(x+dx[i],y+dy[i])==e))
            q.push(ii(x+dx[i],y+dy[i]));
        }
    }
    if(v[e.X][e.Y])
    {
        ll k=0;
        REP(i,4)
        {
            if(d[e.X+dx[i]][e.Y+dy[i]]||ii(e.X+dx[i],e.Y+dy[i])==f)
            k++;
        }
        if(k>=2||!d[e.X][e.Y])
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}