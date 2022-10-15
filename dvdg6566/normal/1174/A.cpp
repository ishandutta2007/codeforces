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
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 200100

deque<ll> dq;
ll N,a,l,r;

int main(){
    // freopen("in.txt","r",stdin);
    cin>>N;
    for (int i=1;i<=2*N;++i){
        cin>>a;
        dq.pb(a);
    }
    sort(ALL(dq));

    for (int i=0;i<N;++i)l+=dq[i];
    for (int i=N;i<2*N;++i)r+=dq[i];

    if (l != r){
        for (auto i : dq)cout<<i<<' ';
    }else cout<<-1;
    return 0;

    ll X = -2;
    while(X!=N*2){
        // cout<<l<<' '<<r<<'\n';
        if (l != r){
            for (auto t : dq)cout<<t<<' ';cout<<'\n';
            return 0;
        }
        ++X;
        int p = dq[0];
        int q = dq[N];
        // cout<<"Change "<<p<<' '<<q<<'\n';
        r -= q;
        r += p;
        l -= p;
        l += q;
        dq.pop_front();
        dq.push_back(p);
    }
    cout<<-1;
}