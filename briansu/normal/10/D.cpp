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



ll d[2][MAXn];
ll n,m;
ll dp[MAXn],pre[MAXn];
vector<ll> ans;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    REP(i,n)cin>>d[0][i+1];
    cin>>m;
    REP(i,m)cin>>d[1][i+1];
    FILL(pre,0);
    for(int i=1;i<=n;i++)
    {
        ll mx=0,p=0;
        for(int j=1;j<=m;j++)
        {
            if(d[1][j]<d[0][i]&&dp[j]>mx)
            {
                mx=dp[j];
                p=j;
            }
            if(d[1][j]==d[0][i]&&dp[j]<mx+1)
            {
                dp[j]=mx+1;
                pre[j]=p;
            }
        }
    }
    ll mx=0,id=0;
    for(int i=1;i<=m;i++)if(dp[i]>mx)mx=dp[i],id=i;
    cout<<mx<<endl;
    while(id)ans.pb(d[1][id]),id=pre[id];
    reverse(ALL(ans));
    for(ll k:ans)cout<<k<<" ";
    cout<<endl;
}