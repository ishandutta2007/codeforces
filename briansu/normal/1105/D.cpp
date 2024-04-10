//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#ifdef brian
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXn][MAXn], s[10];
ll dx[] = {1, -1, 0 ,0};
ll dy[] = {0, 0, 1 ,-1};

vector<ii> q[10];
ll ct[10];
typedef pair<ll, ii> iii;

int main()
{
    IOS();
    ll n, m, p;
    cin>>n>>m>>p;
    REP1(i,p)cin>>s[i];
    FILL(d, -1);
    REP1(i,n)
    {
        string s;
        cin>>s;
        REP1(j, m)
        {
            if(s[j-1] == '#')d[i][j] = -1;
            else if(s[j-1] == '.')d[i][j] = 0;
            else d[i][j] = s[j-1] - '0', q[s[j-1] - '0'].pb(ii(i, j));
        }
    }
    while(1)
    {
        bool fg = 0;
        REP1(i, p)if(SZ(q[i]))fg = 1;
        if(!fg)break;
        REP1(i, p)
        {
            vector<ii> ret;
            priority_queue<iii, vector<iii>, greater<iii> > pq;
            for(ii t:q[i])pq.push({0, t});
            while(SZ(pq))
            {
                ll dis = pq.top().X;
                ll x = pq.top().Y.X;
                ll y = pq.top().Y.Y;
                pq.pop();
                if(dis == s[i])continue;
                REP(j, 4)
                {
                    ll xx = x + dx[j], yy = y + dy[j];
                    if(d[xx][yy] == 0)
                    {
                        d[xx][yy] = i;
                        pq.push({dis+1,{xx,yy}});
                        ret.pb({xx,yy});
                    }
                }
            }
            q[i] = ret;
        }
    }
    REP1(i,n)REP1(j,m)if(d[i][j] > 0)ct[d[i][j]]++;
    REP1(i,p)cout<<ct[i]<<" ";
}