#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 2010;
const int INF = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    string X[100];
    for (int i = 0; i < 26; ++i) {
        X[i] = "A";
        X[i + 26] = "B";
        X[i] = X[i] + (char)(i + 'a');
        X[i + 26] = X[i + 26] + (char)(i + 'a');
    }

    int N, K, MM = 0;
    string ans[100];
    cin >> N >> K;
    for (int i = 0; i < K - 1; ++i) ans[i] = X[MM++];
    for (int i = 0; i < N - K + 1; ++i) {
        string P;
        cin >> P;
        if (P == "YES") {
            ans[i + K - 1] = X[MM++];
        } else {
            ans[i + K - 1] = ans[i];
        }
    }
    for (int i = 0; i < N; ++i) cout << ans[i] << " ";
        cout << endl;
    return 0;
}