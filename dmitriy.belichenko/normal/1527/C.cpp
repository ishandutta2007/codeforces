

#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3,unroll-loops")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <numeric>
#include <set>
#include <queue>
#include <deque>
#include <array>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <map>
#include <functional>
#include <bitset>
#include <complex>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define mp make_pair
#define ll long long
using namespace std;
const int P = 1e5;
int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int, vector<int>> cnt;
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            cnt[p].push_back(i + 1);
        }
        ll ans = 0;
        for (auto x : cnt) {
            ll cur = 1LL * n * x.second.size() + x.second.size();
            for (auto p : x.second) {
                cur -= p;
            }
            for (auto p : x.second) {
                cur -= n + 1;
                cur += p;
                ans += p * (cur);
            }
        }
        cout << ans << "\n";

    }
   
}