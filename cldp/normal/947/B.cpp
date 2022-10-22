#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 101000;
const int INF = 1000000007;
const double PI = acos(-1.0);

int cnt[MAXN];

long long v[MAXN], t[MAXN];
long long sum[MAXN];
long long cal[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> v[i];
    for (int i = 1; i <= N; ++i) cin >> t[i];
    for (int i = 1; i <= N; ++i) sum[i] = sum[i - 1] + t[i];
    for (int i = 1; i <= N; ++i) {
        if (t[i] >= v[i]) {
            --cnt[i];
            cal[i] += v[i];
            continue;
        } else {
            int L = i, R = N + 1;
            while (L + 1 < R) {
                int mid = (L + R) / 2;
                if (sum[mid] - sum[i - 1] >= v[i]) R = mid; else L = mid;
            }
            --cnt[R];
            cal[R] += v[i] - (sum[L] - sum[i - 1]);
        }
    }

    long long temp = 0;
    for (int i = 1; i <= N; ++i) {
        ++temp;
        temp += cnt[i];
        long long ans = temp * t[i] + cal[i];
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}