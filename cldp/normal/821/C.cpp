#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 300010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int T[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    string P;
    int ans = 0, nxt = 0;
    vector<int> X;
    for (int i = 0; i < N + N; ++i) {
        cin >> P;
        if (P == "add") {
            int a;
            cin >> a;
            X.push_back(a);
        } else {
            ++nxt;
            if (X.empty()) continue;

            if (X.back() == nxt) {
                X.pop_back();
                continue;
            }
            X.clear();
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}