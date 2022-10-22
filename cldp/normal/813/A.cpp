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
    int N, M;
    cin >> N;
    int ans = 0, a, b;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        ans += a;
    }
    cin >> M;
    bool flag = false;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        if (a >= ans) {
            ans = a;
            flag = true;
            break;
        } 
        if (b >= ans) {
            flag = true;
            break;
        }
    }
    if (!flag) ans = -1;
    cout << ans << endl;
    return 0;
}