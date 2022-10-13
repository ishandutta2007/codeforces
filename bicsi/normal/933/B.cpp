#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

void Add(vector<int>& repr, int pos, int k) {
    if (pos % 2 == 0) {
        if (repr[pos] < k - 1) repr[pos] += 1;
        else { repr[pos] = 0; Add(repr, pos + 1, k); }
    } else {
        if (repr[pos] > 0) repr[pos] -= 1;
        else { repr[pos] = (k - 1); Add(repr, pos + 1, k); }
    }
}

vector<int> Solve(long long p, int k) {
    vector<int> ans(100, 0);


    for (int bit = 0; p; bit += 1) {
        for (int j = 0; j < (p % k); ++j) {
            Add(ans, bit, k);
        }
        p /= k;
    }

    while (ans.back() == 0) {
        ans.pop_back();
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    

    long long p; int k; cin >> p >> k;
    auto ret = Solve(p, k);
    cout << ret.size() << endl;
    for (auto x : ret) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}