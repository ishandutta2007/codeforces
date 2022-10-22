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
const int MAXN = 2010;



int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N;
    int A = 0, B = 1000000000;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        A = max(a, A);
        B = min(B, b);
    }
    cin >> M;
    
    int ans = 0;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        ans = max(ans, A - b);
        ans = max(ans, a - B);
    }
    cout << ans << endl;
    return 0;
}