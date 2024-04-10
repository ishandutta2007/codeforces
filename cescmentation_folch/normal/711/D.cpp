#include<bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

const int N = 2e5 + 10;
ll mod = 1e9 + 7;

int V[N];
int K[N];
int T[N];
ll ex[N];

vi R;

void dfs(int x, int val, int p) {
    if (V[x] != -1) {
        if (V[x] != val) return;
        R.push_back(p - K[x]);
        return;
    }
    V[x] = val;
    K[x] = p;
    dfs(T[x], val, p + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    memset(V, -1, sizeof V);

    int n;
    cin >> n;
    ex[0] = 1;
    for (int i = 1; i <= n; ++i) ex[i] = (ex[i-1]*2ll)%mod;
    for (int i = 1; i <= n; ++i) cin >> T[i];
    for (int i = 1; i <= n; ++i) dfs(i, i, 0);
    
    int kk = n;
    for (int i = 0; i < R.size(); ++i) kk -= R[i];
    ll res = ex[kk];
    for (int i = 0; i < R.size(); ++i) {
        res =  (res*(ex[R[i]]-2))%mod;
    }
    cout << res << endl;
}