#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int K = 16;
const int N = 5050;

map<ll, int> ind;
int a[16][5050];
int b[100100];
ll row[16];
int ni[16];
int8_t vis[100100], cur[100100];

vector<int> adj[100100];
int k;

vector<int> st;
vector<int> swaps[1<<16];

int dp[1<<16];

void dfs(int u) {
    if (vis[u]) {
        if (!cur[u]) return;
        vector<int> re;
        int seen = 0;
        for (int j = st.size()-1; j>=0; --j) {
            int v = st[j];
            int cat = v/N;
            if (seen&(1<<cat)) {
                return;
            }
            seen |= (1<<cat);
            re.push_back(v);
            //cerr << "  PB" << endl;
            if (v == u) break;
            assert(j!=0);
        }
        seen >>= 1;
        //cerr << " ?? " << re.size() << endl;
        //cerr << " FOR " << bitset<15>(seen) << " :: ";
        //cerr; for (auto& x : re) //cerr << x/N << "," << x%N << " ";
        //cerr << endl;
        swaps[seen] = move(re);
        return;
    }
    vis[u] = 1;
    cur[u] = 1;
    st.push_back(u);
    for (auto& v : adj[u]) {
        dfs(v);
    }
    cur[u] = 0;
    st.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> k;
    ll sum = 0;
    ll goal = 0;
    for (int i=1; i<=k; ++i) {
        cin >> ni[i];
        for (int j=1; j<=ni[i]; ++j) {
            cin >> a[i][j];
            row[i] += a[i][j];
            b[i*N+j] = a[i][j];
            ind[a[i][j]] = i*N+j;
            sum += a[i][j];
        }
    }

    if (sum%k != 0) {
        cout << "No" << endl;
        return 0;
    }

    goal = sum/k;

    for (int i=1; i<=k; ++i) {
        for (int j=1; j<=ni[i]; ++j) {
            int z = i*N+j;
            ll oth = b[z] + goal - row[i];
            if (ind.count(oth)) {
                int y = ind[oth];
                if (y/N == i) continue;
                adj[y].push_back(z);
                //cerr << " : " << y/N << "," << y%N << "->" << z/N << "," << z%N << endl;
            }
        }
    }


    for (int i=1; i<=k; ++i) {
        for (int j=1; j<=ni[i]; ++j) {
            int z = i*N+j;
            if (vis[z]) continue;
            dfs(z);
        }
    }

    for (int i=1; i<=k; ++i) {
        if (goal == row[i]) {
            swaps[1<<(i-1)] = vector<int>({i*N+1});
        }
    }

    for (int i=0; i<(1<<16); ++i) {
        dp[i] = -1;
    }

    dp[0] = 0;

    for (int i=1; i<(1<<k); ++i) {
        int beg = (i-1)&i;
        for (int j=beg; j!=i; j=(j-1)&i) {
            if (dp[j] == -1) continue;

            int k = i^j;
            if (swaps[k].empty()) continue;

            dp[i] = j;
            break;

            if (j==0) break;
        }
    }

    if (dp[(1<<k)-1] == -1) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    vector<pii> ans(k+1);
    int q = (1<<k)-1;
    while (q) {
        int nxt = dp[q];
        int k = q^nxt;

        int sz = swaps[k].size();
        for (int i=0; i<sz; ++i) {
            int j = (i+1)%sz;
            int ind = swaps[k][j]/N;
            ans[ind].first = b[swaps[k][j]];
            ans[ind].second = swaps[k][i]/N;
        }

        q = nxt;
    }

    for (int i=1; i<=k; ++i) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

    return 0;
}