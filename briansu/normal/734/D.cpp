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

const ll MAXn=2e5+5;
const ll MOD=1000000007;
const ll INF=ll(1e15);


ll n,x,y;
struct pc
{
    ii p;
    ll t;//0 cross 1 dig 2 queen
    pc(ii pi=ii(0,0),ll ti=-1):p(pi),t(ti){};
};
pc d[8];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>x>>y;
    REP(i,n)
    {
        char c;
        ii p;
        cin>>c>>p.X>>p.Y;
        ll t;
        if(c=='R')t=0;
        else if(c=='B')t=1;
        else t=2;
        if(p.X+p.Y==x+y)
        {
            if(p.Y>y)
            {
                if(d[7].t==-1||d[7].p.Y>p.Y)d[7]=pc(p,t);
            }
            else
            {
                if(d[3].t==-1||d[3].p.Y<p.Y)d[3]=pc(p,t);
            }
        }
        else if(p.X-p.Y==x-y)
        {
            if(p.Y>y)
            {
                if(d[1].t==-1||d[1].p.Y>p.Y)d[1]=pc(p,t);
            }
            else
            {
                if(d[5].t==-1||d[5].p.Y<p.Y)d[5]=pc(p,t);
            }
        }
        else if(p.X==x)
        {
            if(p.Y>y)
            {
                if(d[0].t==-1||d[0].p.Y>p.Y)d[0]=pc(p,t);
            }
            else
            {
                if(d[4].t==-1||d[4].p.Y<p.Y)d[4]=pc(p,t);
            }

        }
        else if(p.Y==y)
        {
            if(p.X>x)
            {
                if(d[2].t==-1||d[2].p.X>p.X)d[2]=pc(p,t);
            }
            else
            {
                if(d[6].t==-1||d[6].p.X<p.X)d[6]=pc(p,t);
            }
        }
    }
    REP(i,8)
    {
        if(d[i].t==-1)continue;
        if(i%2==0)
        {
            if(d[i].t==0||d[i].t==2)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
        else
        {
            if(d[i].t==1||d[i].t==2)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;


}