#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> X(n), Y(n);
    for (int i = 0; i < n; ++i) {
        cin >> X[i] >> Y[i];
    }

    vector<bool> Vis(n, 0);
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (Vis[i]) continue;

        ans += 1;
        deque<int> Q;
        auto push = [&](int x) {
            if (Vis[x]) return;
            Vis[x] = true;
            Q.push_back(x);
        };
        push(i);
        while (!Q.empty()) {
            int top = Q.front();
            Q.pop_front();

            int x = X[top], y = Y[top];
            for (int j = 0; j < n; ++j) {
                if (X[j] == x or Y[j] == y)
                    push(j);    
            }
        }
    }

    cout << ans - 1 << endl;
    return 0;
}