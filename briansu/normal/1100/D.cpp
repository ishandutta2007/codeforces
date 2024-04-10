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
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}

#define endl '\n'

const ll MAXn=1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

const ll N = 999, M = 666;

ll d[MAXn][MAXn];
ii p[MAXn];


void mov(ii s, ii t)
{
    while(s != t){
        ll dx=0, dy=0;
        if(s.X < t.X)dx = 1;
        else if(s.X > t.X)dx = -1;
        if(s.Y < t.Y)dy = 1;
        else if(s.Y > t.Y)dy = -1;
        if(d[s.X + dx][s.Y + dy])dx = 0;
        s.X += dx, s.Y += dy;
        cout<<s.X<<" "<<s.Y<<endl;
        ll t, a, b;
        cin>>t>>a>>b;
        if(t < 1)exit(0);
        d[p[t].X][p[t].Y] = 0;
        d[a][b] = 1;
        p[t] = ii(a,b);
    }
}

ll ct[5];

int main()
{
    ii now;
    cin>>now.X>>now.Y;
    REP1(i, M)cin>>p[i].X>>p[i].Y, d[p[i].X][p[i].Y] = 1;
    mov(now, ii(500, 500));
    now = ii(500, 500);
    REP1(i, M)
    {
        ll t = 0;
        if(p[i].X > 500)t+=2;
        if(p[i].Y > 500)t+=1;
        ct[t]++;
    }
    if(ct[0] < 166)mov(now, ii(999,999));
    else if(ct[1] < 166)mov(now, ii(999, 1));
    else if(ct[2] < 166)mov(now, ii(1, 999));
    else mov(now, ii(1, 1));
}