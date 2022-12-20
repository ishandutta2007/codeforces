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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXn], dt[2][MAXn][2];

int main()
{
    IOS();
    ll n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    REP1(i, n)d[i] = s[i - 1] == '1';
    
    REP1(i, n)REP(j, 2)dt[0][i][j] = dt[1][i][j] = 2;

    {
        ll mn[2] = {-1, -1};
        ll mx[2] = {-1, -1};
        REP1(i, n)
        {
            ll t = d[i];
            if(mn[t] == -1)mn[t] = i;
            mx[t] = i;
            if(mn[0] == -1)dt[0][i][1] = 0;
            else if(mx[0] - mn[0] + 1 <= k)dt[0][i][1] = 1;
            if(mn[1] == -1)dt[0][i][0] = 0;
            else if(mx[1] - mn[1] + 1 <= k)dt[0][i][0] = 1;
        }
    }
    REP1(i, n)debug(i, dt[0][i][0], dt[0][i][1]);
    {
        ll mn[2] = {-1, -1};
        ll mx[2] = {-1, -1};
        REP1(i, n)
        {
            ll t = d[i];
            if(mx[t] == -1)mx[t] = i;
            mn[t] = i;
            if(mn[0] == -1)dt[1][i][1] = 0;
            else if(mx[0] - mn[0] + 1 <= k)dt[1][i][1] = 1;
            if(mn[1] == -1)dt[1][i][0] = 0;
            else if(mx[1] - mn[1] + 1 <= k)dt[1][i][0] = 1;
        }
    }
    REP1(i, n)debug(i, dt[1][i][0], dt[1][i][1]);
    if(dt[0][n][0] <= 1 || dt[0][n][1] <= 1)
    {
        cout<<"tokitsukaze"<<endl;
        return 0;
    }
    bool fg = 1;
    for(int i = 1;i + k - 1 <= n;i ++)
    {
        if(!((dt[0][i - 1][0] + dt[1][i + k][0] <= 1) || (dt[0][i - 1][1] + dt[1][i + k][1] <= 1)))fg = 0;
    }
    if(fg)
    {
        ll tt = 0;
        for(int i = 1;i <= n;i ++)
        {
            tt += d[i];
            if(i >= k)
            {
                tt -= d[i - k];
                if(tt == k || tt == 0)
                {
                    cout<<"once again"<<endl;
                    return 0;
                }
            }
        }
        cout<<"quailty"<<endl;
        return 0;
    }
    cout<<"once again"<<endl;
}