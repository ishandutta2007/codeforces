#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 101000;
const int INF = 1000000007;
const double PI = acos(-1.0);

struct node {
    string t;
    int s, h;
    long long ans;
    bool operator < (const node &B) const {
        return 1LL * s * B.h > 1LL * B.s * h;
    }
};

node x[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string Q;
        cin >> Q;
        x[i].ans = x[i].s = x[i].h = 0;
        for (int j = 0; j < Q.size(); ++j) {
            if (Q[j] == 's') ++x[i].s; else {
                ++x[i].h;
                x[i].ans += x[i].s;
            }
        }
    }
    sort(x, x + N);
    long long ans = 0, s = 0, h = 0;
    for (int i = 0; i < N; ++i) {
        ans += x[i].ans + s * x[i].h;
        s += x[i].s;
        h += x[i].h;
    }
    cout << ans << endl;
    return 0;
}