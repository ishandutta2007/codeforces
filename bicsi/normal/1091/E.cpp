#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define int long long 

using namespace std;

vector<int> Solve(vector<int> v) {
    int n = v.size();
    int s = 0;
    for (auto x : v) s += x;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    vector<int> psum(n, 0);
    for (int i = 0; i < n; ++i) {
        psum[i] = v[i];
        if (i > 0) psum[i] += psum[i - 1];
    }

    auto first_ltk = [&](int k) {
        int ans = -1;
        for (int step = (1 << 20); step; step /= 2) {
            if (ans + step < n && v[ans + step] > k)
                ans += step;
        }
        return ans + 1;
    };
    
    auto GET_RSUM = [&](int from, int k) {
        // sum of min(v[i], k)
        int pos = max(from, first_ltk(k));
        int rsum = psum[n - 1] - (pos == 0 ? 0 : psum[pos - 1]);
        rsum += k * (pos - from);
        return rsum;
    };

    vector<int> sum_left(n + 1), sum_right(n + 1), sum_left2(n + 1);
    
    sum_left[0] = 2e18;
    sum_left2[0] = 2e18;

    for (int at = 0; at < n; ++at) {
        int now = -psum[at];
        now += at * (at + 1);
        now += GET_RSUM(at + 1, at + 1);
        sum_left[at + 1] = min(now, sum_left[at]);
        sum_left2[at + 1] = min(now + at + 1, sum_left2[at]);
    }


    sum_right[n] = 2e18;
    for (int at = n - 1; at >= 0; --at) {
        int now = -psum[at];
        now += (at + 1) * (at + 2);
        now += GET_RSUM(at + 1, at + 2);
        sum_right[at] = min(now, sum_right[at + 1]);
    }
    
    vector<int> ans;
    int at = 0;
    for (int choose = n; choose >= 0; --choose) {
        while (at < n && v[at] >= choose) {
            ++at;
        }

        //cerr << "CHOOSE: " << choose << endl;
        //cerr << "AT: " << at << endl;
        //cerr << "LEFT: " << sum_left[at] << endl;
        //cerr << "RIGHT: " << sum_right[at] << endl;

        if (sum_left2[at] < 0) continue;
        if (sum_left[at] + choose < 0) continue;
        if (sum_right[at] - choose < 0) continue;
        
        int now = -choose;
        if (at > 0) now -= psum[at - 1];
        now += at * (at + 1);
        now += GET_RSUM(at, at + 1);
        //cerr << "SELF: " << now << endl;
        if (now < 0) continue;
        if ((s + choose) % 2) continue;
        
        ans.push_back(choose);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> Brut(vector<int> v) {
    int n = v.size();
    vector<int> sol;
    for (int d = 0; d <= n; ++d) {
        auto w = v;
        w.push_back(d);

        sort(w.rbegin(), w.rend());

        bool bad = false;
        for (int k = 0; k <= n; ++k) {
            int lhs = 0, rhs = k * (k + 1);
            for (int i = 0; i <= k; ++i)
                lhs += w[i];
            for (int i = k + 1; i <= n; ++i)
                rhs += min(w[i], k + 1);
            int now = rhs - lhs;
            if (now < 0) bad = true; 
        }
        
        int s = 0;
        for (auto x : w) s += x;

        if (!bad && s % 2 == 0) sol.push_back(d);
    }
    return sol;
}

void Test() {
    while (true) {
        int n = rand() % 4 + 10;
        vector<int> v;
        for (int i = 0; i < n; ++i)
            v.push_back(rand() % (n + 1));
        auto brut = Brut(v);
        auto solve = Solve(v);
        if (brut != solve) {
            cout << n << endl;
            for (auto x : v) cout << x << " "; cout << endl;
            cout << "BRUT: ";
            for (auto x : brut) cout << x << " "; cout << endl;
            cout << "SOLVE: ";
            for (auto x : solve) cout << x << " "; cout << endl;
            exit(-1);
        }
        cout << "OK" << endl;
    }
}

int32_t main() {
    // Test();
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int d; cin >> d;
        v.push_back(d);
    }
    
    vector<int> ans = Solve(v); 
    if (ans.empty()) cout << -1 << endl;
    else { for (auto x : ans) cout << x << " "; cout << endl; }
    
    return 0;
}