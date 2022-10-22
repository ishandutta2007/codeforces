#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

struct node {
    int l, r;
};

node x[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> x[i].l >> x[i].r;
        }
        int t = 0;
        for (int i = 0; i < N; ++i) {
            if (t <= x[i].l) {
                cout << x[i].l << " ";
                t = x[i].l + 1;
            } else 
            if (t <= x[i].r) {
                cout << t << " ";
                ++t;
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}