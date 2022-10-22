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

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        x[i + N] = x[i];
    }
    int s, f;
    cin >> s >> f;
    int l = f - s;

    int temp = 0;
    for (int i = 0; i < l; ++i) temp += x[i];
    int ans1 = temp, ans2 = s, ans3 = s;
    for (int i = 0; i < N - 1; ++i) {
        temp += x[i + l] - x[i];
        --ans3;
        if (ans3 == 0) ans3 += N;
        if (temp > ans1) {
            ans1 = temp;
            ans2 = ans3;
        } else 
        if (temp == ans1) {
            if (ans3 < ans2) ans2 = ans3;
        } 
    }
    cout << ans2 << endl;
    return 0;
}