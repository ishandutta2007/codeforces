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


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll bs = 880301;
const ll INF=ll(1e15);

ll MOD;
ll my_pw(ll x,ll k)
{
    if(k == 0)return 1;
    ll a = my_pw(x,k/2);
    a = a * a % MOD;
    if(k & 1)return a * x % MOD;
    else return a;
}

//ll invpw[MAXn];
ll pw[MAXn],hs[MAXn];

ll get(ll l,ll r) //[l,r]
{
    return (hs[r+1] - hs[l] * pw[r-l+1] % MOD + MOD) % MOD;
}

int main()
{
    IOS();
    srand(time(0));
    MOD = vector<ll>({1000000087,1000000093,1000000097,1000000033})[rand()%4];
    pw[0] = 1;
    REP1(i,MAXn-1)pw[i] = pw[i-1] * bs % MOD;
    //REP(i,MAXn)invpw[i] = my_pw(pw[i],MOD-2);
    string s,t;
    cin>>s>>t;
    ll ct0=0,ct1=0;
    for(char c:s)if(c == '0')ct0++;else ct1++;
    ll tt = 0;
    hs[0] = 0;
    REP(i,SZ(t))hs[i+1] = (hs[i] * bs + t[i]) % MOD;
    REP1(i,SZ(t))
    {
        if((SZ(t) - ct0 * i) % ct1 == 0 && (SZ(t) - ct0 * i) > 0)
        {
            ll a = i,b = (SZ(t) - ct0 * i) / ct1;
            ll dta = -1, dtb = -1;
            ll now = 0;
            bool ok = 1;
            for(char c:s)
            {
                if(c == '0')
                {
                    ll tmp = get(now,now + a - 1);
                    if(dta == -1)dta = tmp;
                    else if(dta != tmp)ok = 0;
                    now += a;
                }else{
                    ll tmp = get(now,now + b - 1);
                    if(dtb == -1)dtb = tmp;
                    else if(dtb != tmp)ok = 0;
                    now += b;
                }
            }
            if(ok && !(a==b&&dta == dtb))tt++;
        }
    }
    cout<<tt<<endl;
}