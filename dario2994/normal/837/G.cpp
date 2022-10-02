#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 1<<17;
const LL INF = 1e9 + 10;

struct Node {
    void BuildPref() {
        sort(vec.begin(), vec.end());
        pref.resize(vec.size() + 1);
        pref[0] = {0, 0};
        for (int i = 0; i < (int)vec.size(); i++) {
            pref[i+1].first = pref[i].first + vec[i].second.first;
            pref[i+1].second = pref[i].second + vec[i].second.second;
        }
    }

    LL GetAns(LL x) {
        int it = lower_bound(vec.begin(), vec.end(), pair<LL, pair<LL, LL>>{x, {-INF, -INF}}) - vec.begin();
        return pref[it].first * x + pref[it].second;
    }
    
    vector<pair<LL, pair<LL, LL>>> vec;
    vector<pair<LL, LL>> pref;
};

Node st[MAXN*2];
LL GetAns(int v, int l, int r, const int a, const int b, LL x) {
    if (b < l or r < a) return 0;
    if (a <= l and r <= b) return st[v].GetAns(x);
    int m = (l+r)/2;
    return GetAns(2*v, l, m, a, b, x) + GetAns(2*v+1, m+1, r, a, b, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    LL pot = 1;
    while (pot < N) pot *= 2;
    for (int i = 0; i < N; i++) {
        LL x1, x2, y1, a, b, y2;
        cin >> x1 >> x2 >> y1 >> a >> b >> y2;
        st[pot + i].vec.push_back({-INF, {0, y1}});
        st[pot + i].vec.push_back({x1, {a, b-y1}});
        st[pot + i].vec.push_back({x2, {-a, y2-b}});
    }
    for (int i = pot-1; i > 0; i--) {
        st[i].vec = st[2*i].vec;
        st[i].vec.insert(st[i].vec.end(), st[2*i+1].vec.begin(), st[2*i+1].vec.end());
    }
    for (int i = 1; i < 2*pot; i++) st[i].BuildPref();

    int m;
    cin >> m;
    LL last = 0;
    for (int tt = 0; tt < m; tt++) {
        LL l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        x += last;
        x %= (LL)1e9;
        last = GetAns(1, 0, pot-1, l, r, x);
        cout << last << "\n";
    }
}