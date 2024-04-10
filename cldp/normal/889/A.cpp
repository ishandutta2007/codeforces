#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN];
bool y[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        y[a] = true;
    }
    int ans = 0;
    for (int i = 0; i <= N; ++i) {
        if (!y[i]) ++ans;
    }
    cout << ans << endl;
    return 0;
}