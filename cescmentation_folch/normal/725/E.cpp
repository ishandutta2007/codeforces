#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<ll> vll;

const int N = 2e5 + 10;

int F[N];
int D[N];
int cnt[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, c;
    cin >> c >> n;
    for (int i = 0; i < n; ++i) {
        cin >> D[i];
        ++cnt[D[i]];
    }
    int lst = 0;
    for (int i = 1; i <= c; ++i) {
        if (cnt[i]) lst = i;
        F[i] = lst;
    }
    for (int mon = 1; mon <= c; ++mon) {
        int k = c;
        int act = k;
        bool fet = false;
        while (k) {
            int p = F[act];
            if (p == 0) break;
            if (p <= mon and mon <= act and !fet) {
                fet = true;
                k -= mon;
                act = min(mon, k);
            }
            else {
                int kk = min(cnt[p], (k/p));
                k -= kk*p;
                act = min(p - 1, k);
            }
        }
        if (k) {
            cout << mon << '\n';
            return 0;
        }
    }
    cout << "Greed is good" << '\n';
}