#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);



int main() {
    ios_base::sync_with_stdio(false);
    unsigned long long A, B;
    cin >> A >> B;
    vector<unsigned long long> x;
    while (A > 0) {
        x.push_back(A % 10);
        A /= 10;
    }
    sort(x.begin(), x.end());
    vector<unsigned long long> M10;
    M10.push_back(1);
    for (int i = 1; i <= 18; ++i) M10.push_back(M10[i - 1] * 10);
    int N = x.size();
    unsigned long long ans = 0;

    for (int i = N - 1; i >= 0; --i) {
        for (int j = x.size() - 1; j >= 0; --j) {
            unsigned long long temp = M10[i] * x[j];
            int t = 0;
            for (int k = x.size() - 1; k >= 0; --k) {
                if (k == j) continue;
                temp += M10[t] * x[k];
                ++t;
            }
            if (ans + temp <= B) {
                ans += M10[i] * x[j];
                for (int k = j; k + 1 < x.size(); ++k) x[k] = x[k + 1];
                x.pop_back();
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}