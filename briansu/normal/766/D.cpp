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

const ll MAXn=1e5+5;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll g[2*MAXn];
ll fd(ll a){return g[a]=(g[a]==a?a:fd(g[a]));}
void uni(ll a,ll b){g[fd(a)]=fd(b);}
void build(){REP(i,2*MAXn)g[i]=i;}

map<string,ll> mp;
ll it=-1;

ll n,m,q;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>q;
    build();
    REP(i,n)
    {
        string s;
        cin>>s;
        mp[s]=++it;
    }
    REP(i,m)
    {
        string s[2];
        ll t;
        cin>>t>>s[0]>>s[1];
        ll a,b;
        a=mp[s[0]];
        b=mp[s[1]];
        if(t==1)
        {
            if(fd(2*a)==fd(2*b+1)||fd(2*a+1)==fd(2*b))cout<<"NO"<<endl;
            else
            {
                uni(2*a,2*b);
                uni(2*a+1,2*b+1);
                cout<<"YES"<<endl;
            }
        }
        else
        {
            if(fd(2*a+1)==fd(2*b+1)||fd(2*a)==fd(2*b))cout<<"NO"<<endl;
            else
            {
                uni(2*a,2*b+1);
                uni(2*a+1,2*b);
                cout<<"YES"<<endl;
            }
        }
    }
    REP(i,q)
    {
        string s[2];
        ll a,b;
        cin>>s[0]>>s[1];
        a=mp[s[0]];
        b=mp[s[1]];
        if(fd(2*a)==fd(2*b)||fd(2*a+1)==fd(2*b+1))cout<<1<<endl;
        else if(fd(2*a)==fd(2*b+1)||fd(2*a+1)==fd(2*b))cout<<2<<endl;
        else cout<<3<<endl;
    }
}