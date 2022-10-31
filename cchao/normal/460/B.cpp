#include <bits/stdc++.h>
using namespace std;

long long p(long long a, int b) {
    long long r = 1;
    while(b--) r *= a;
    return r;
}

int f(int x) {
    int r = 0;
    while(x) {
        r += x % 10;
        x /= 10;
    }
    return r;
}

int main() {
    int a, b, c; cin >> a >> b >> c;

    vector<int> ans;
    for(int i = 1; i <= 81; ++i) {
        long long x = p(i, a) * b + c;
        if(x <= 0 || x >= 1000000000) continue;
        if(f(x) == i) ans.push_back(x);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i) cout << ans[i] << ' '; cout << endl;
    return 0;
}