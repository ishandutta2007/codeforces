#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
const int MAXN = 2010;



int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    map<int, int> C;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        ++C[a];
    }
    int ans = 0;
    if (C.size() <= 2) {
        cout << 0 << endl;
        return 0;
    } else {
        for (auto iter = C.begin(); iter != C.end(); ++iter) {
            ans += iter->second;
        }
        auto iter = C.begin();
        ans -= iter->second;
        iter = C.end();
        --iter;
        ans -= iter->second;
    }
    cout << ans << endl;
    return 0;
}