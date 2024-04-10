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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);



ll n,m,k,s;
vector<ii> d[2];
ii c[2][MAXn];
vector<ii> ans;
bool chk(ll t)
{
    ll ita=0,itb=0;
    ll tmps=s,cnt=0;
    ans.clear();
    while(cnt<k)
    {
        bool a=(ita!=SZ(d[0])),b=(itb!=SZ(d[1]));
        if(!b||(a&&b&&d[0][ita].X*c[0][t].X<d[1][itb].X*c[1][t].X))
        {
            tmps-=d[0][ita].X*c[0][t].X;
            ans.pb(ii(d[0][ita].Y,c[0][t].Y));
            ita++;
        }
        else
        {
            tmps-=d[1][itb].X*c[1][t].X;
            ans.pb(ii(d[1][itb].Y,c[1][t].Y));
            itb++;
        }
        cnt++;
        if(tmps<0)return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k>>s;
    REP(i,2)REP(j,n)cin>>c[i][j].X,c[i][j].Y=j;
    REP(t,2)for(int i=1;i<n;i++)if(c[t][i-1].X<c[t][i].X)c[t][i]=c[t][i-1];
    REP(i,m)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        d[a].pb(ii(b,i));
    }
    sort(ALL(d[0]));
    sort(ALL(d[1]));
    ll l=-1,r=n;
    while(l!=r-1)
    {
        ll h=(l+r)/2;
        if(chk(h))r=h;
        else l=h;
    }
    if(r==n){cout<<-1<<endl;return 0;}
    chk(r);
    cout<<r+1<<endl;
    REP(i,k)cout<<ans[i].X+1<<" "<<ans[i].Y+1<<endl;

}