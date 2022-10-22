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


int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int ans = N;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        ans = min(ans, b - a + 1);
    }
    cout << ans << endl;
    for (int i = 0; i < N; ++i) cout << i % ans << " ";
    cout << endl; 
    
    return 0;
}