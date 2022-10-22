#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2000010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN], y[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, a;
    cin >> N;
    long long temp = 0, add = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> a;
        temp += abs(a - i);
        x[i] = a;
        if (a <= i) ++add;
        if (a > i) ++y[a - i];
    }

    long long cnt = 0, ans = temp, ansi = 0;
    for (int i = 0; i < N; ++i) {
        temp -= abs(N - x[N - i]);
        temp += x[N - i];
        ++y[i + x[N - i]];
        add -= 1;
        add += y[i];
        temp = temp + add - (N - add);
        if (temp < ans) {
            ans = temp;
            ansi = i + 1;
        }
    }
    cout << ans << " " << ansi << endl;
    return 0;
}