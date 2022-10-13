#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

long long n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n; 
    if (n % 3) { cout << 0 << endl; return 0; }
    n /= 3;
    vector<long long> divs;
    for (long long d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            divs.push_back(d);
            if (d != n / d)
                divs.push_back(n / d);
        }
    }
    
    sort(divs.begin(), divs.end());

    cerr << divs.size() << endl;
    vector<tuple<long long, long long, long long>> ans;
    for (int i = 0; i < (int)divs.size(); ++i) {
        long long d1 = divs[i];
        auto pula = n / d1;
        for (int j = i; j < (int)divs.size(); ++j) {
            long long d2 = divs[j];
            if (pula % d2) continue;
            auto d3 = pula / d2;
            if (d3 < d2) break;

            if ((d1 + d2 + d3) % 2) continue;
            if (d1 + d2 <= d3) continue;


            long long a = (d1 + d2 - d3);
            long long b = (d1 - d2 + d3);
            long long c = (-d1 + d2 + d3);
            
            ans.emplace_back(a / 2, b / 2, c / 2);
            ans.emplace_back(a / 2, c / 2, b / 2);
            ans.emplace_back(b / 2, a / 2, c / 2);
            ans.emplace_back(b / 2, c / 2, a / 2);
            ans.emplace_back(c / 2, a / 2, b / 2);
            ans.emplace_back(c / 2, b / 2, a / 2);
            
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    // for (auto x : ans) cerr << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;

    cout << ans.size() << endl;

    return 0;
}