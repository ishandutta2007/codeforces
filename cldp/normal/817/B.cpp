#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 300010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    map<int, int> S;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        ++S[x[i]];
    }
    auto iter = S.begin();
    if (iter->second >= 3) {
        long long ans = iter->second;
        cout << ans * (ans - 1) * (ans - 2) / 6 << endl;
        return 0;
    } else 
    if (iter->second == 2) {
        long long ans = iter->second;
        ++iter;
        cout << ans * (ans - 1) / 2 * iter->second << endl;
        return 0;
    } else {
        ++iter;
        if (iter->second >= 2) {
            long long ans = iter->second;
            cout << ans * (ans - 1) / 2 << endl;
            return 0;
        } else {
            ++iter;
            cout << iter->second << endl;
        }
    }
    return 0;
}