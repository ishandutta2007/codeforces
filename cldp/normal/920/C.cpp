#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN];
string Q;
int y[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> x[i];
    }
    cin >> Q;
    for (int i = 0; i < Q.size(); ++i) {
        y[i + 1] = y[i];
        if (Q[i] == '1') ++y[i + 1];
    }
    bool ans = true;
    for (int i = 1; i <= N; ++i) {
        int a = i;
        int b = x[i];
        if (a > b) swap(a, b);
        if (a == b) continue;
        if (y[b - 1] - y[a - 1] != b - a) ans = false;
    }
    if (ans) cout << "YES" << endl; else cout << "NO" << endl;
    return 0;
}