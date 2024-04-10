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
template<typename _t>
struct ary
{
    _t _a,_b;
    ary(_t _ai,_t _bi):_a(_ai),_b(_bi){}
};
template<typename T> void pary(T _a,T _b){_OUTC(cerr,_a,_b);}
#else
#define debug(...)
//#define endl '\n'
#endif // brian
//}

const ll MAXn=1e5+5,MAXlg=8;
const ll MOD=1000000007;
const ll INF=ll(1e15);


ii p[2];
ii can;
ii d[MAXn];
ll n;
lf ans=0;
ll sq(const ll &x){return x*x;}
lf dis(const ii &a,const ii &b)
{
    return sqrt(sq(a.X-b.X)+sq(a.Y-b.Y));
}
set<pair<lf,ll> > st[2];
void an(lf x)
{
    cout<<fixed<<setprecision(10)<<x<<endl;
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    REP(i,2)cin>>p[i].X>>p[i].Y;
    cin>>can.X>>can.Y;
    cin>>n;
    REP(i,n)cin>>d[i].X>>d[i].Y;
    REP(i,n)ans+=2*dis(can,d[i]);
    REP(i,n)
    {
        lf t=dis(can,d[i]);
        REP(j,2)st[j].insert(make_pair(dis(p[j],d[i])-t,i));
    }
    debug(ans,st[0],st[1]);
    if(n==1||((*st[0].begin()).X>=0&&(*st[1].begin()).X>=0))an(ans+min((*st[0].begin()).X,(*st[1].begin()).X));
    pair<lf,ll> tmp[4]={(*st[0].begin()),*(st[0].begin()),(*st[1].begin()),*(st[1].begin())};
    auto it=st[0].begin();
    it++;
    tmp[1]=*it;
    it=st[1].begin();
    it++;
    tmp[3]=*it;
    //REP(i,4)debug(tmp[i]);
    if(tmp[0].X<0&&tmp[2].X<0&&tmp[0].Y!=tmp[2].Y)an(ans+tmp[0].X+tmp[2].X);
    if(tmp[0].X<0&&tmp[2].X<0)
    {
        lf k=min({tmp[0].X+tmp[3].X,tmp[1].X+tmp[2].X,tmp[0].X,tmp[2].X});
        an(ans+k);
    }
    an(ans+min((*st[0].begin()).X,(*st[1].begin()).X));

}