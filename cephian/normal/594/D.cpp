#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const int S = 1000005, N = 200005,M = 1e9+7;
ll fact[S],a[S],bit[N];

ll pw(ll a, ll b) {
    if(!b) return 1;
    if(b&1) return (a*pw(a,b-1))%M;
    ll t = pw(a,b/2);
    return (t*t)%M;
}

struct query {
    int l,r,i;
    bool operator<(const query& q) const {
        return l < q.l;
    }
};

ll bit_q(int i) {
    return (i)?(bit[i]*bit_q(i^(i&-i)))%M:1;
}

void bit_u(int a, ll v) {
    for(;a <= N;a+=a&-a)
        bit[a] = (bit[a]*v)%M;
}

int last_pos[S] = {0};
ll tot[S];

vector<query> queries;
ll ans[N],all[N];
int perm[N];

void ud_val(int ind) {
    int b = a[ind];
    while(b != 1) {
        int p = fact[b];
        if(last_pos[p]) bit_u(last_pos[p],pw(tot[p],M-2));
        last_pos[p] = ind;
        bit_u(last_pos[p],tot[p]);
        b/=fact[b];
    }
}

int main() {
    ios::sync_with_stdio(0);
    for(int i = 1; i < S; ++i)
        fact[i] = i;
    for(int i = 2; i < S; ++i) {
        if(fact[i] == i) {
            for(ll j = ll(i)*i; j < S; j+=i)
                fact[j] = i;
            tot[i] = ((i-1)*pw(i,M-2))%M;
        }
    }

    int n,q;
    cin >> n;
    fill(bit,bit+n+1,1);
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> q;
    for(int i = 0; i < q; ++i) {
        query qu;
        qu.i = i;
        cin >> qu.l >> qu.r;
        queries.push_back(qu);
    }

    sort(queries.rbegin(),queries.rend());
    all[n+1]=1;
    for(int i = n; i >= 1; --i)
        all[i] = (all[i+1]*a[i])%M;
    all[0] = all[1];
    int ind = n+1;
    for(int i = 0; i < q; ++i) {
        while(ind > 1 && ind-1 >= queries[i].l) {
            --ind;
            ud_val(ind);
        }
        ll al = (all[queries[i].l]*pw(all[queries[i].r+1],M-2))%M;

        ans[i] = (al*bit_q(queries[i].r))%M;
        perm[queries[i].i] = i;
    }
    for(int i = 0; i < q; ++i) {
        cout << ans[perm[i]] << "\n";
    }
    return 0;
}