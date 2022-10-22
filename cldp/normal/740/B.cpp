#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
const int MAXN = 1010;

int X[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, M, ans = 0;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> X[i];
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        int temp = 0;
        while (a != b) {
            temp += X[a];
            ++a;
        }
        temp += X[b];
        if (temp > 0) ans += temp;
    }
    cout << ans << endl;
    
    return 0;
}