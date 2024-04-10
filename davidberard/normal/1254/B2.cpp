#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 1001000;

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
ll sum;
int n;

pii rem;
ll dist = 0;
ll solve(vector<pii>& pos, ll k) {
    ll x = 0;
    ll sum_above = 0, sum_below = 0;
    ll cnt_above = 0, cnt_below = 0;
    ll need = k;
    rem = pii(0, 0);
    dist += pos.back().first - pos[0].first+1;
    for(auto& x: pos) {
        ll take = min(need, x.second);
        sum_above += x.first*take;
        cnt_above += take;
        need -= take;
        if (x.second != take) {
            if (rem.first != 0) {
                cerr << " " << k << ":" << endl;
                for (auto& p : pos) {
                    cerr << "  (" << p.first << " " << p.second << ")";
                }
                cerr << endl;
                assert(rem.first == 0);
            }
            rem = pii(x.first, x.second-take);
            x.second = take;
        }
    }

    ll best = 0x3f3f3f3f3f3f3f3fll;
    for (ll i=pos[0].first; i<=pos.back().first; ++i) {
        ll t = sum_above-cnt_above*i + cnt_below*i - sum_below;
        best = min(best, t);
        //cerr << "! " << i << " : " << t << " :: " << sum_above << " " << sum_below << " " << cnt_above << " " << cnt_below << endl;
        //cerr << " .. " << pos[x].first << " " << i << " " << pos[x].first*pos[x].second << endl;
        if (pos[x].first == i) {
            sum_above -= pos[x].first*pos[x].second;
            sum_below += pos[x].first*pos[x].second;
            cnt_above -= pos[x].second;
            cnt_below += pos[x].second;
            ++x;
        }
    }
    return best;
}

vector<ll> get_pd() {
    vector<ll> ans;
    ll s = sum;
    for (auto& p : primes) {
        if (s%p == 0) {
            ans.push_back(p);
            while (s%p == 0) s /= p;
        }
    }
    if (s > 1) ans.push_back(s);
    for (auto& p : ans) {
        cerr << "! " << p << endl;
    }
    return ans;
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

    auto pd = get_pd();

    ll best = 0x3f3f3f3f3f3f3f3fll;
    for (auto& p : pd) {
            ll k = p;
            ll tsm = 0;
            vector<pii> pos;
            ll ans = 0;
            for (int j=0; j<n; ++j) {
                ll b = a[j]%k;

                pos.emplace_back(j, b);
                tsm += b;
                if (tsm >= k) {
                    ans += solve(pos, k);
                    pos.clear();
                    if (rem.first != 0) {
                        pos.push_back(rem);
                    }
                    tsm = rem.second;
                }
            }
            best = min(best, ans);
            //cerr << " for " << p << " " << ans << endl;
    }

    cout << best << "\n";
    return 0;
}