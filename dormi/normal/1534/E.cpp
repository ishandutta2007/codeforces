#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f;

const int MN = 2001;
int N, K,
    dis[MN], par[MN];

int main() {
    cin >> N >> K;

    // BFS
    memset(dis, 0x3f, sizeof dis);
    queue<int> q;
    dis[0] = 0; par[0] = -1; q.push(0);
    while (!q.empty()) {
        int c = q.front(); q.pop(); // c -> num selected
        for (auto i = 0; i <= K; i++) { // num unselected we add
            if (i <= N-c && K-i <= c) {
                int to = c + i-(K-i);
                if (dis[to] == INF) {
                    dis[to] = dis[c]+1;
                    par[to] = c;
                    q.push(to);
                }
            }
        }
    }

    if (dis[N] == INF) cout << "-1\n";
    else {
        vector<int> sel, nosel(N);
        iota(nosel.begin(), nosel.end(), 1);

        // get ans
        vector<int> path;
        for (auto c = N; c != -1; c = par[c])
            path.push_back(c);
        reverse(path.begin(), path.end());

        // for (auto x : path) printf("path=%d\n", x);
        // printf("\n"); fflush(stdout);

        int sz = path.size(), ans = 0;
        for (auto i = 0; i < sz-1; i++) {
            // a-(K-a) = d
            // a-K+a=d
            // 2a-K=d
            // 2a=d+K
            // a=(d+K)/2
            int a = path[i], b = path[i+1], d = b-a, nsel = (d+K)/2, nnosel = K-nsel; assert((d+K) % 2 == 0);
            vector<int> cnosel, csel;
            for (auto j = 0; j < nsel; j++) {
                csel.push_back(nosel.back());
                nosel.pop_back();
            }
            for (auto j = 0; j < nnosel; j++) {
                cnosel.push_back(sel.back());
                sel.pop_back();
            }
            
            // make query
            cout << "? ";
            for (auto x : csel) cout << x << ' ';
            for (auto x : cnosel) cout << x << ' ';
            cout << '\n'; cout.flush();
            // update nosel,sel
            nosel.insert(nosel.end(), cnosel.begin(), cnosel.end());
            sel.insert(sel.end(), csel.begin(), csel.end());

            int res; cin >> res;
            ans ^= res;
        }
        assert(nosel.empty());

        cout << "! " << ans << '\n'; cout.flush();
    }
}