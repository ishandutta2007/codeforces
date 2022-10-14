#include <bits/stdc++.h>

using namespace std;

#define long int64_t

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        vector<int> odds;
        for (int i = 0; i < N; i++) {
            if (arr[i] & 1) {
                odds.push_back(arr[i]);
            }
        }
        int O = odds.size();
        int E = N - O;
        int ans = O * E + E * (E - 1) / 2;
        for (int i = 0; i < O; i++) {
            for (int j = i + 1; j < O; j++) {
                if (gcd(odds[i], odds[j]) > 1) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}