#include <bits/stdc++.h>
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
using ll=long long;
using pii=pair<int, int>;
//#define int ll

#define MOD 1000000007ull

long long DP[100005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, k; cin >> t >> k;
    DP[0] = 1;
    iter(i, 1, 100001) {
        DP[i] = DP[i-1];
        if(i >= k) DP[i] += DP[i-k];
        DP[i] %= MOD;
    }
    iter(i, 1, 100001) DP[i] = (DP[i-1] + DP[i]) % MOD;
    rep(i, t) {
        int a, b; cin >> a >> b;
        cout << (DP[b] - DP[a-1] + MOD) % MOD << endl;
    }
}