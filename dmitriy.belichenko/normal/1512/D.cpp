

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
        ll sm = 0;
        vector<int> a(n + 2);
        for (auto &x : a) {
            cin >> x;
            sm += x;
        }
        sort(all(a));
        bool flag = 0;
        vector<int> ans;
        for (int i = 0; i < n + 1; i++) {
            if (sm - a[i] - a[n + 1] == a[n + 1]) {
                for (int j = 0; j < n + 1; j++) {
                    if (i == j) continue;
                    ans.push_back(a[j]);
                }
                flag = 1;
                break;
            }
        }
        
        if (flag == 0) {
            if (sm - a[n + 1] - a[n] == a[n]) {
                flag = 1;
                for (int j = 0; j < n; j++) {
                    ans.push_back(a[j]);
                }
            }
        }
        
        if (!flag) {
            cout << "-1" << "\n";
            continue;
        }
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
   
}