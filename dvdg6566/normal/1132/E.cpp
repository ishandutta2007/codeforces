#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll FMOD = 1e9+6;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 12960

ll blocks;
ll rmvblocks,Q;
ll A[10],t;
ll memo[13000],shift;

int main(){
    // freopen("in.txt","r",stdin);
    cin >> Q;
    for (ll i=1;i<=8;++i){
        cin>>A[i];
        t = t + i*A[i];
    }
    if (t <= Q){
        cout<<t;
        return 0;
    }
    for (ll i=1;i<=8;++i){
        ll grpsize = 840/i;
        ll num_grp = max(0LL,A[i]/grpsize-1);
        A[i] -= num_grp * grpsize;
        blocks += num_grp;
        // cout<<A[i]<<'\n';
    }

    ll rmv = (Q - 12959)/840+1;
    if (rmv > 0){
        Q -= rmv * 840;
        shift = 840 * rmv;
        blocks -= rmv;
    }
    // cout<<blocks<<' '<s<Q<<'\n';

    for (int i=0;i<=blocks&&i*840<=MAXN;++i){
        memo[i*840] = 1;
        // cout<<i*840<<'\n';
    }

    for (ll i=1;i<=8;++i){
        ll reps = log2(A[i]);
        for (ll j=0;j<reps;++j){
            // cout<<i<<' '<<(1<<j)<<'\n';
            ll val = i*(1<<j);
            for (ll i=MAXN;i>=val;--i)if (memo[i-val])memo[i] = 1;
        }
        ll leftover = A[i] - (1<<reps)+1;
        // cout<<i<<' '<<leftover<<'\n';
        ll val = i*leftover;
        for (ll i=MAXN;i>=val;--i)if (memo[i-val])memo[i] = 1;
    }
    // cout<<shift<<'\n';
    // for (ll i=1;i<=MAXN;++i)if (memo[i])cout<<i<<' ';cout<<'\n';
    for (ll i=Q;i>=0;--i){
        if (memo[i]){
            cout<<i+shift;
            return 0;
        }
    }
}