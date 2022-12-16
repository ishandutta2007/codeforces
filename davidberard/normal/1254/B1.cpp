#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 100100;

vector<int> primes;
uint8_t is_comp[1001000];

void setup() {
    for (ll i=2; i < 1001000; ++i) {
        if (!is_comp[i]) {
            primes.push_back(i);
            for (ll j=i*i; j < 1001000; j += i) {
                is_comp[j] = 1;
            }
        }
    }
}

int a[N];
int sum;
int n;

ll solve(vector<int>& pos) {
    ll x = 0;
    ll sum_above = 0, sum_below = 0;
    for(auto& x: pos) {
        sum_above += x;
    }
    ll best = 0x3f3f3f3f3f3f3f3fll;
    for (ll i=pos[0]; i<=pos.back(); ++i) {
        ll t = sum_above-(pos.size()-x)*i + x*i - sum_below;
        best = min(best, t);
        if (pos[x] == i) {
            sum_above -= i;
            sum_below += i;
            ++x;
        }
    }
    return best;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum == 1) {
        cout << -1 << "\n";
        return 0;
    }

    ll best = 0x3f3f3f3f3f3f3f3fll;
    int k = 0;
    for (int i=2; i<=sum; ++i) {
        if (sum%i == 0) {
            k = i;
            int cnt = 0;
            vector<int> pos;
            ll ans = 0;
            for (int j=0; j<n; ++j) {
                if (a[j]) {
                    pos.push_back(j);
                    ++cnt;
                    if (cnt == k) {
                        ans += solve(pos);
                        pos = vector<int>();
                        cnt = 0;
                    }
                }
            }
            best = min(best, ans);
        }
    }

    cout << best << "\n";
    return 0;
}