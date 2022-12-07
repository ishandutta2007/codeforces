#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    vector<vector<int>> ans;

    auto multiply = [&](int a, int b) -> int {
        int res = 0;
        while(b > 0) {
            if(b & 1) {
                ans.push_back({res, a, 1});
                res = res + a;
            }
            ans.push_back({a, a, 1});
            a += a;
            b >>= 1;
        }
        return res;
    };

    int n;
    cin >> n;
    
    ans.push_back({n, n, 1}); // 1 --> add, 0 --> XOR
    ans.push_back({n, n, 0});
    vector <int> v{n, 2*n};

    unordered_set <int> s;
    s.insert(n);
    s.insert(2*n);
    s.insert(0);

    int temp = 0;
    int t2 = 1;

    while(true) {
        // temp++;
        // if(temp == t2) {
        //     t2 *= temp;
        //     temp = 0;
        // }
        int m = v.size();
        int a = rng() % m;
        int b = rng() % m;
        // int c = (t2 / (temp + 1) > 2 ? 1 : 0);
        int c = rng() % 5;
        int x;
        if(c == 0) {
            // ans.push_back({v[a], v[b], 0});
            x = v[a] ^ v[b];
        } else {
            // ans.push_back({v[a], v[b], 1});
            x = v[a] + v[b];
        }
        if(s.find(x) == s.end()) {
            v.push_back(x);
            ans.push_back({v[a], v[b], min(c, 1ll)});
            s.insert(x);
        }
        if(__gcd(x, n) == 1) {
            break;
        }
    }
    int x = v.back();
    int m1 = -1;
    int m2 = -1;
    for(int i = 1; i < 2*n; i++) {
        if(x * i % n == 1) {
            m1 = i;
            m2 = x * i / n;
            break;
        }
    }
    assert(m1 != -1);
    int x1 = multiply(x, m1);
    int x2 = multiply(n, m2);
    if(min(x1, x2) % 2 == 1) {
        ans.push_back({n, x1, 1});
        ans.push_back({n, x2, 1});
        x1 += n;
        x2 += n;
    }
    ans.push_back({x1, x2, 0});

    cout << (int)ans.size() << '\n';
    for(auto i : ans) {
        if(i[2] == 0) {
            cout << i[0] << " ^ " << i[1] << '\n';
        } else {
            cout << i[0] << " + " << i[1] << '\n';
        }
    }
    
    return 0;
}