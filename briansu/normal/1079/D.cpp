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

inline lf sq(lf a){return a * a;};
lf dis(lf a,lf b,lf c,lf d){return sqrt(sq(a-c) + sq(b-d));}

ll a,b,c;
lf gx(lf y){return -(b * y + c) / a;}
lf gy(lf x){return -(a * x + c) / b;}

int main()
{
    IOS();
    ll x1,y1,x2,y2;
    cin>>a>>b>>c>>x1>>y1>>x2>>y2;
    lf mn = abs(x1-x2) + abs(y1-y2);
    if(a==0||b==0)
    {
        cout<<fixed<<setprecision(12)<<mn<<endl;
        return 0;
    }
    {
        lf p = gy(x1), q = gy(x2);
        mn = min(mn,fabs(p-y1) + fabs(q-y2) + dis(x1,p,x2,q));
    }
    {
        lf p = gy(x1), q = gx(y2);
        mn = min(mn,fabs(p-y1) + fabs(q-x2) + dis(x1,p,q,y2));
    }
    {
        lf p = gx(y1), q = gx(y2);
        mn = min(mn,fabs(p-x1) + fabs(q-x2) + dis(p,y1,q,y2));
    }
    {
        lf p = gx(y1), q = gy(x2);
        mn = min(mn,fabs(p-x1) + fabs(q-y2) + dis(p,y1,x2,q));
    }
    cout<<fixed<<setprecision(12)<<mn<<endl;
}