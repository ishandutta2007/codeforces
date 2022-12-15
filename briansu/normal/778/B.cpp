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
#define endl '\n'
#define pary(...)
#endif // brian
//}

const ll MAXn=5e3+5,MAXlg=__lg(10*MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


ll n,m;
map<string,ll> mp;
string cst[MAXn];
ll d[MAXn][3];
ll bt[MAXn];
ll ans[MAXn][2];


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    mp["?"]=0;
    REP(i,n)
    {
        string s;
        cin>>s;
        ll t;
        t=mp[s]=i+1;
        cin>>s>>s;
        if(isdigit(s[0]))cst[t]=s,d[t][0]=-1;
        else
        {
            d[t][0]=mp[s];
            cin>>s;
            d[t][1]=(s[0]=='A'?0:(s[0]=='O'?1:2));
            cin>>s;
            d[t][2]=mp[s];
        }
    }
    #ifdef brian
    REP(i,n)pary(d[i+1],d[i+1]+3);
    #endif // brian
    REP(k,m)
    {
        ll cnt[2]={0};
        REP(b,2)
        {
            bt[0]=b;
            for(int i=1;i<=n;i++)
            {
                if(d[i][0]==-1)bt[i]=cst[i][k]-'0';
                else
                {
                    if(d[i][1]==0)bt[i]=bt[d[i][0]]&bt[d[i][2]];
                    else if(d[i][1]==1)bt[i]=bt[d[i][0]]|bt[d[i][2]];
                    else bt[i]=bt[d[i][0]]^bt[d[i][2]];
                }
                cnt[b]+=bt[i];
            }
            #ifdef brian
            debug(b,cnt[b]);
            pary(bt+1,bt+n+1);
            #endif // brian

        }
        if(cnt[0]<cnt[1])ans[k][0]=0,ans[k][1]=1;
        else if(cnt[0]>cnt[1])ans[k][0]=1,ans[k][1]=0;
        else ans[k][0]=ans[k][1]=0;
    }
    REP(i,m)cout<<char(ans[i][0]+'0');
    cout<<endl;
    REP(i,m)cout<<char(ans[i][1]+'0');
    cout<<endl;
}