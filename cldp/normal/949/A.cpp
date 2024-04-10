#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200010;
const int INF = 1000000007;
const double PI = acos(-1.0);

vector<int> x[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    string Q;
    cin >> Q;
    int zero = 0, one = 0;
    for (int i = 0; i < Q.size(); ++i) {
        if (Q[i] == '0') ++zero; else ++one;
    }
    if (zero <= one) {
        cout << -1 << endl;
        return 0;
    }

    int T = 0, maxT = 0;
    for (int i = 0; i < Q.size(); ++i) {
        if (Q[i] == '0') {
            x[T].push_back(i);
            ++T;
            maxT = max(maxT, T);
        } else {
            --T;
            if (T < 0) {
                cout << -1 << endl;
                return 0;
            }
            x[T].push_back(i);
        }
    }
    if (T != maxT) {
        cout << -1 << endl;
        return 0;
    }
    cout << T << endl;
    for (int i = 0; i < T; ++i) {
        cout << x[i].size();
        for (int j = 0; j < x[i].size(); ++j) cout << " " << x[i][j] + 1;
        cout << endl;
    }
    return 0;
}