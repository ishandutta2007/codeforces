//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
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
template<typename _a,typename _b> ostream &operator << (ostream &_s,pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
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
#else
#define debug(...)
#define endl '\n'
#endif // brian
//}

const ll MAXn=2e5+5,MAXlg=35;
const ll MOD=1000000007;
const ll INF=ll(8e18);


ll a[MAXn],b[MAXn],c[MAXn];
ll cnt[MAXlg];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;
    cin>>n;
    REP(i,n)cin>>b[i];
    REP(i,n)cin>>c[i];
    ll s=0;
    REP(i,n)s+=b[i]+c[i];
    s/=2*n;
    REP(i,n)a[i]=(b[i]+c[i]-s)/n;
    //_OUTC(cout,a,a+n);
    debug('\n');
    REP(i,n)for(int j=0,I=1;j<MAXlg;j++,(I<<=1LL))if(a[i]&I)cnt[j]++;
    REP(i,n)
    {
        ll k=0,l=0;
        for(int j=0,I=1;j<MAXlg;j++,(I<<=1LL))
        {
            if(a[i]&I){k+=cnt[j];l+=n;}
            else l+=cnt[j];
            debug((k%2),((b[i]&I)>0),(l%2),((c[i]&I)>0),I);
            if(((k%2)!=((b[i]&I)>0))||((l%2)!=((c[i]&I)>0))){cout<<-1<<endl;return 0;}
            k/=2;l/=2;
        }
    }
    REP(i,n)cout<<(i==0?"":" ")<<a[i];
    cout<<endl;
}