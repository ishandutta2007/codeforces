#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,ll> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
ll INF = 1e15;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define f first 
#define s second
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 1000100

ll lastocc[MAXN], firstocc[MAXN];
ll A[MAXN];
ll N,X;
deque<pi> wind;
ll ans;

bool sorted(ll top){
    ll cm = 0;
    for (ll i=0;i<N;++i){
        if (A[i] <= top)continue;
        if (A[i] < cm)return 0;
        cm = A[i];
    }
    return 1;
}

int main(){
    //("in.txt","r",stdin);
    cin >> N >> X;
    memset(firstocc,-1,sizeof(firstocc));
    memset(lastocc,-1,sizeof(lastocc));
    for (ll i=0;i<N;++i){
        cin >> A[i];
        if (firstocc[A[i]] == -1)firstocc[A[i]] = i;
        lastocc[A[i]] = i;
    }
    ll lower = 1;
    ll upper = X;
    while (upper > lower + 1){
        ll mid = (upper+lower)/2;
        if (sorted(mid))upper = mid;
        else lower = mid+1;
    }
    if (sorted(lower)) upper = lower;

    ll cur = upper;
    for (ll i=0;i<N;++i)if(A[i] > cur)wind.pb(mp(A[i], i));
    ll curlast = 0;
    // cout<<1<<' '<<cur<<'\n';
    ans = X - cur + 1;
    //cout<<"Window\n";
    //for (auto v : wind)cout<<v.f<<' ';cout<<'\n';
    //for (ll i=1;i<=X;++i)cout<<firstocc[i]<<' '<<lastocc[i]<<'\n';

    for (ll i=2;i<=X+1;++i){
        if (firstocc[i-1] != -1 && firstocc[i-1] < curlast){break;}
        if (lastocc[i-1] != -1)curlast = lastocc[i-1];
        cur = max(cur, i);
       // cout<<"Run leaving everything under " << i << '\n';
        while(SZ(wind)){
            if (wind[0].f <= cur){
                wind.pop_front();
                continue;
            }
            if (wind[0].s >= curlast){
                break;
            }
            cur = wind[0].f;
        }
        //cout<<i<<' '<<cur<<'\n';
        ans += X - max(i,cur) + 1;
    }
    cout<<ans;
}