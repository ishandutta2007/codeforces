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
const ll INF=ll(1e17);

ll dp[10], tdp[2][10], ndp[10];

void smax(ll &a, ll b)
{
    a = max(a, b);
}

int main()
{
    IOS();
    REP(i, 10)dp[i] = -INF;
    dp[0] = 0;
    ll n;
    cin>>n;
    while(n--)
    {
        ll k;
        cin>>k;
        ll mx3 = 0, mx2 = 0;
        vector<ll> dt1;
        while(k--)
        {
            ll c, d;
            cin>>c>>d;
            if(c == 3)mx3 = max(mx3, d);
            else if(c == 2)mx2 = max(mx2, d);
            else dt1.pb(d);
        }
        sort(ALL(dt1), greater<ll>());
        dt1.resize(min(SZ(dt1), 3));
        REP(i, 10)ndp[i] = dp[i];
        if(mx3 != 0)REP(i, 10)smax(ndp[(i + 1) % 10], dp[i] + mx3 * ((i == 9) + 1));
        if(mx2 != 0)REP(i, 10)smax(ndp[(i + 1) % 10], dp[i] + mx2 * ((i == 9) + 1));
        do{
            ll fg = 0;
            REP(i, 10)tdp[0][i] = dp[i];
            REP(j, SZ(dt1)){
                fg = !fg;
                REP(i, 10)tdp[fg][i] = tdp[!fg][i];
                REP(i, 10)smax(tdp[fg][(i + 1) % 10], tdp[!fg][i] + dt1[j] * ((i == 9) + 1));
            }
            REP(i, 10)smax(ndp[i], tdp[fg][i]);
        }while(next_permutation(ALL(dt1), greater<ll>()));
        if(mx2 != 0 && SZ(dt1) > 0)
        {
            dt1.resize(1);
            dt1.pb(mx2);
            sort(ALL(dt1));
            do{
                ll fg = 0;
                REP(i, 10)tdp[0][i] = dp[i];
                REP(j, SZ(dt1)){
                    fg = !fg;
                    REP(i, 10)tdp[fg][i] = tdp[!fg][i];
                    REP(i, 10)smax(tdp[fg][(i + 1) % 10], tdp[!fg][i] + dt1[j] * ((i == 9) + 1));
                }
                REP(i, 10)smax(ndp[i], tdp[fg][i]);
            }while(next_permutation(ALL(dt1)));
        }
        REP(i, 10)smax(dp[i], ndp[i]);
    }
    ll mx = 0;
    REP(i,10)smax(mx, dp[i]);
    cout<<mx<<endl;
}