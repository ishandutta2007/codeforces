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
    #else
    #define debug(...)
    #define pary(...)
    #define endl '\n'
    #endif // brian
    //}

const ll MAXn=5e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);



ll n;
vector<ll> d[3];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    if(n==1)
    {
        ll k;
        cin>>k;
        cout<<k<<endl;return 0;
    }
    REP(i,n)
    {
        ll k;
        cin>>k;
        if(k>0)d[0].pb(k);
        else if(k==0)d[1].pb(k);
        else d[2].pb(k);
    }
    REP(i,3)sort(ALL(d[i]));
    if(SZ(d[0])==0&&SZ(d[2])<=1)
    {
        cout<<0<<endl;
        return 0;
    }
    for(ll k:d[0])cout<<k<<" ";
    REP(i,SZ(d[2])-(SZ(d[2])%2))cout<<d[2][i]<<" ";
    cout<<endl;
}