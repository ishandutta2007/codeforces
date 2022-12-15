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
#else
#define debug(...)
#endif // brian

const ll INF=ll(1e15);
const ll MAXn=1e6+5,MAXlg=20;
const ll MOD = 1000000007;

ll n,m,k;
ll d[MAXn];
ll s[MAXn];
ll id[MAXn];
ll tmp[2][MAXn];
vector<ll> tt;
bool chk(ll now)
{
    tt.resize(n+now);
    merge(d,d+n,s+m-now,s+m,tt.begin());

    ll it=0;
    for(int dt=0;;dt++)
    {
            if(tt[it]<dt)return 0;
            else it+=k;
            if(it>=now+n)return 1;
    }

}
ll cnt[10000005];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    REP(i,n)cin>>tmp[0][i];
    REP(i,m)cin>>tmp[1][i];
    REP(i,n)cnt[tmp[0][i]]++;
    partial_sum(cnt,cnt+10000005,cnt);
    REP(i,n)d[--cnt[tmp[0][i]]]=tmp[0][i];
    FILL(cnt,0);
    REP(i,m)cnt[tmp[1][i]]++;
    partial_sum(cnt,cnt+10000005,cnt);
    REP(i,m)
    {
        ll a=--cnt[tmp[1][i]];
        s[a]=tmp[1][i];
        id[a]=i+1;
    }
    ll l=-1,r=m+1;
    while(l!=r-1)
    {
        ll h=(l+r)/2;
        if(chk(h))l=h;
        else r=h;
    }
    cout<<l<<endl;
    for(int i=m-l;i<m;i++)cout<<id[i]<<" ";
    cout<<endl;

}