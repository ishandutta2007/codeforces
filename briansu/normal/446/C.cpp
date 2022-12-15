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


const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000009;
const ll INF=ll(1e15);

ii operator + (ii a, ii b){return ii((a.X + b.X)%MOD, (a.Y + b.Y)%MOD);}
ii operator - (ii a, ii b){return ii((a.X - b.X)%MOD, (a.Y - b.Y)%MOD);}
ll operator * (ii a, ii b){return (a.X * b.X + a.Y * b.Y)%MOD;}


ii bs[MAXn], prebs[MAXn];

struct node{
    int l, r;
    node *lc, *rc;
    ii d;ll tt;
    node(int li, int ri, node *lci = 0, node *rci = 0):l(li), r(ri), lc(lci), rc(rci), d(0, 0), tt(0){}
    void pull()
    {
        tt = (lc->d * prebs[lc->r - lc->l] + rc->d * prebs[rc->r - rc->l] + lc->tt + rc->tt) % MOD;
    }
    void ins(int li,int ri)
    {
        if(li >= r || ri <= l)return;
        else if(li <= l && ri >= r)d = d + ii(ii(1,1) * bs[l - li + 1], ii(1,1) * bs[l - li + 2]);
        else{
            lc->ins(li, ri);
            rc->ins(li, ri);
            pull();
        }
        debug(li, ri, l, r, d, tt);
    }
    ll qr(int li, int ri)
    {
        debug(li, ri, l, r, d, tt);
        if(li >= r || ri <= l)return 0;
        else{
            ll tl = max(li, l), tr = min(r, ri);
            ll ret = d * (prebs[tr - l] - prebs[tl - l]);
            if(li <= l && ri >= r)ret = (ret + tt) % MOD;
            else ret = (ret + lc->qr(li, ri) + rc->qr(li, ri)) % MOD;
            return ret;
        }
    }
};

node *build(ll l,ll r)
{
    if(l == r-1)return new node(l, r);
    else return new node(l, r, build(l, (l+r)/2), build((l+r)/2, r)); 
}

ll d[MAXn];

int main()
{
    IOS();
    bs[1] = ii(1, 0);
    bs[2] = ii(0, 1);
    for(int i = 3;i < MAXn;i ++)bs[i] = bs[i-1] + bs[i-2];
    for(int i = 1;i < MAXn;i ++)prebs[i] = prebs[i-1] + bs[i];
    int n, q;
    cin>>n>>q;
    REP1(i, n)cin>>d[i];
    REP1(i,n)d[i] += d[i-1];
    node *rt = build(1, n+1);
    while(q--)
    {
        ll tp, l, r;
        cin>>tp>>l>>r;
        if(tp == 1)rt->ins(l, r+1);
        else{
            ll tt = (rt->qr(l, r+1) + d[r] - d[l-1]) % MOD;
            cout<<(tt + MOD) % MOD<<endl;
        }
    }
}