#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vpi V(n);
    for (int i = 0; i < n; ++i) cin >> V[i].first >> V[i].second;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((V[i].first >= V[j].first) != (V[i].first + V[i].second >= V[j].first + V[j].second)) {
                res += 1;
            }
            else {
                if (((V[i].first >= V[j].first) != (V[i].first + V[i].second >= V[j].first)) or ((V[i].first >= V[j].first) != (V[i].first >= V[j].first + V[j].second))) res += 2;
            }
        }
    }
    cout << res << '\n';
}