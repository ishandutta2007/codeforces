#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define int long long

const int MOD = 1000003;

int combo[800000];

int inv(int x) {
    int po = MOD-2,p = x,ans=1;
    while (po>0) {
        if (po & 1 == 1) ans = ans * p % MOD;
        p = (p*p) % MOD;
        po /= 2;
    }
    return ans;
}

 main() {
    combo[1] = 1;
    FOR(i,2,800000) combo[i] = combo[i-1]*(i % MOD) % MOD;
    int n,c; cin >> n >>c;
    int z = combo[n+c]*inv(combo[c]) % MOD;
    z = (z*inv(combo[n])-1) % MOD;
    if (z<0) z += MOD;
    cout << z;
}