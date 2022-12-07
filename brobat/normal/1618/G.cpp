#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 400100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int parent[MAXN], cnt[MAXN], sz[MAXN];
vector <int> v;
set <pair<int, int>> diff;
int n, m, k;
vector <int> p; // prefix sums of v
vector <pair<int, int>> query; // queries in sorted order
vector <int> ans;
int sum = 0;

void pre() {
    cin >> n >> m >> k;
    vector <pair<int, int>> temp;
    forn(i, 0, n) {
        int tt; cin >> tt;
        temp.push_back({tt, 1});
    }
    forn(i, 0, m) {
        int tt; cin >> tt;
        temp.push_back({tt, 0});
    }
    forn(i, 0, n + m) {
        parent[i] = i;
        cnt[i] = 0;
        sz[i] = 1;
    }
    sort(temp.begin(), temp.end());
    forn(i, 0, n + m) {
        if(temp[i].second == 1) {
            cnt[i]++;
            sum += temp[i].first;
        }
        v.push_back(temp[i].first);
    }
    p.resize(n + m);
    p[0] = v[0];
    forn(i, 1, n + m) {
        p[i] = p[i - 1] + v[i];
        diff.insert({v[i] - v[i - 1], i});
    }
    query.resize(k);
    ans.resize(k);
    forn(i, 0, k) {
        cin >> query[i].first;
        query[i].second = i;
    }
    sort(query.begin(), query.end());
}

int find(int x) {
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int psum(int x) {
    if(x - cnt[x] < 0) return p[x];
    return p[x] - p[x - cnt[x]];
}

void merge(int ind) {
    // Merge [ind] with [ind - 1].
    int b = find(ind);
    int a = ind - 1;
    sum -= psum(b);
    sum -= psum(a);
    parent[a] = b;
    cnt[b] += cnt[a];
    sz[b] += sz[a];
    sum += psum(b);
}

void solve() {
    pre();
    for(auto q : query) {
        // Merge all groups with diff less than q.first
        // During each group merging, subtract previous sums from individual group and add new sum to "sum"
        while(!diff.empty() && (*diff.begin()).first <= q.first) {
            merge((*diff.begin()).second);
            diff.erase(diff.begin());
        }
        ans[q.second] = sum;
    }
    for(auto i : ans) cout << i << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}