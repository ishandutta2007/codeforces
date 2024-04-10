#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(i,n) memset(i,n,sizeof(i));
#define SZ(A) ((int)A.size())
#define ALL(A) A.begin(),A.end()
#define X first
#define Y second
#define pb push_back
#ifdef brian
#define  debug(...) do{\
    fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename t> void _do(t &&_x){cerr<<_x<<endl;}
template<typename t,typename ...T> void _do(t &&_x,T &&...tail){cerr<<_x<<", ";_do(tail...);}
template<typename _a,typename _b>
ostream& operator <<(ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
#else
#define debug(...)
#define endl '\n'
#endif // brian

const ll INF=ll(1e15);
const ll MAXn=1e5+5,MAXlg=20;
const ll MOD = 1000000007;

ll n;
pair<ii,ll> d[MAXn];
vector<ll> I;
ll cnt;
ll ans=0;
struct node
{
    ll l,r;
    node *lc,*rc;
    ll d;
    node(ll li,ll ri,node *lci,node *rci):l(li),r(ri),lc(lci),rc(rci),d(0){}
    void ad(ll li,ll ri,ll k)
    {
        if(li>=r||ri<=l)return;
        else if(li<=l&&ri>=r)d=max(d,k);
        else
        {
            if(d!=0)
            {
                lc->d=max(lc->d,d);
                rc->d=max(rc->d,d);
                if(d>=k)return;
                d=0;
            }
            lc->ad(li,ri,k);
            rc->ad(li,ri,k);
        }
    }
    ll qr(ll k)
    {
        if(l==r-1)return d;
        else
        {
            if(d!=0)
            {
                lc->d=max(lc->d,d);
                rc->d=max(rc->d,d);
                d=0;
            }
            ll h=(l+r)/2;
            if(k<h)return lc->qr(k);
            else return rc->qr(k);
        }
    }
};
node *build(ll l,ll r)
{
    if(l==r-1)return new node(l,r,0,0);
    else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    REP(i,n)cin>>d[i].X.Y>>d[i].X.X>>d[i].Y;
    REP(i,n)I.pb(d[i].X.Y);
    REP(i,n)I.pb(d[i].X.X);
    sort(ALL(I));
    I.resize(unique(ALL(I))-I.begin()+1);
    REP(i,n)
    {
        d[i].X.X=(lower_bound(ALL(I),d[i].X.X)-I.begin());
        d[i].X.Y=(lower_bound(ALL(I),d[i].X.Y)-I.begin());
    }
    sort(d,d+n,greater<pair<ii,ll> >());
    //REP(i,n)debug(i,d[i].X,d[i].Y);
    cnt=I.size();
    node *rt=build(0,cnt);
    REP(i,n)
    {
        ll tmp=rt->qr(d[i].X.X)+d[i].Y;
        ans=max(ans,tmp);
        rt->ad(d[i].X.Y+1,cnt,tmp);
    }
    cout<<ans<<endl;
}