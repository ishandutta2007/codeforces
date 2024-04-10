#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef set<int> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 1000100
#define MAXL 19

struct ConvexHull{
    deque<pi> dq;
    ConvexHull(){}
    ld intersect(pi a, pi b){
        return (ld)(b.s-a.s)/(a.f-b.f);
    }
    void insert(pi cur){
        // cout<<"Inserting "<<cur.f<<' '<<cur.s<<'\n';
        while (SZ(dq) > 1){
            if (intersect(dq[SZ(dq) - 1],cur) >= intersect(dq[SZ(dq)-2],cur))dq.pop_back();
            else break;
        }
        dq.pb(cur);
    }
    ll query(ll xc){
        while(SZ(dq) > 1){
            if (dq[0].f*xc+dq[0].s <= dq[1].f*xc+dq[1].s)dq.pop_front();
            else break;
        }
        return dq[0].f*xc+dq[0].s;
    }
}*H;

vector<pair<pi,ll>> V;
ll N,a,b,c;
ll dp[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("in.txt","r",stdin);
    cin>>N;
    for (int i=1;i<=N;++i){
        cin>>a>>b>>c;
        V.pb(mp(mp(a,b),c));
    }
    sort(ALL(V));
    for (int i=1;i<N;++i){
        assert(V[i].f.f != V[i-1].f.f);
        assert(V[i].f.s != V[i-1].f.s);
    }
    // for (auto i : V)cout<<i.f.f<<' '<<i.f.s<<'\n';
    H = new ConvexHull();
    H->insert(mp(0,0));
    for (int i=1;i<=N;++i){
        ll ch = V[i-1].f.s;
        ll cr = V[i-1].f.f;
        ll l = ch * cr - V[i-1].s + H->query(ch);
        dp[i] = l;
        H->insert(mp(-cr, dp[i]));
        // cout<<"Dp value "<<dp[i]<<'\n';
    }
    cout<<*max_element(dp,dp+N+1);
}