#define _USE_MATH_DEFINES
 
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
 
using namespace std;
 
void reverse_pref(vector<int> &ar, vector<pair<int, int>> &ans,
                  vector<int> &lens, int &mdf, int len) {
    for (int i = 0; i < len; ++i)
        ans.emplace_back(len + mdf + i, ar[i]);
    if (len != 0)
        lens.push_back(len * 2);
    mdf += len * 2;
    reverse(ar.begin(), ar.begin() + len);
}
 
void move_to_front(vector<int> &ar, vector<pair<int, int>> &ans,
                   vector<int> &lens, int &mdf, int id) {
    reverse_pref(ar, ans, lens, mdf, id);
    reverse_pref(ar, ans, lens, mdf, id + 1);
}
 
signed IlkrasTEQ1Solve(int n, vector<int> ar) {
 
    int xr = 0;
    unordered_map<int, int> cnt;
    for (auto &it : ar) {
        cnt[it]++;
    }
    for (auto &it : cnt)
        if (it.second % 2) {
            cout << "-1\n";
            return 0;
        }
    vector<int> br = ar;
    sort(br.rbegin(), br.rend());
    vector<pair<int, int>> ans;
    vector<int> lens;
    ans.reserve(n * n * 2);
    lens.reserve(n * 2);
    int mdf = 0;
    for (int i = 0; i < n; ++i) {
        int fnd = (int)(find(ar.begin() + i, ar.end(), br[i]) - ar.begin());
        move_to_front(ar, ans, lens, mdf, fnd);
    }
    for (int i = 0; i < n; ++i) {
        int lst = i;
        for (; lst < n && ar[lst] == ar[i]; ++lst) {
        }
        lens.push_back(lst - i);
        i = lst - 1;
    }
    cout << (int)ans.size() << "\n";
    for (auto &it : ans)
        cout << it.first << " " << it.second << "\n";
    cout << (int)lens.size() << "\n";
    for (auto &it : lens)
        cout << it << " ";
    cout << "\n";
    return 0;
}
 
signed main() {
    (*cin.tie(0)).sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> ar(n);
        for (auto &it : ar)
            cin >> it;
        IlkrasTEQ1Solve(n, ar);
    }
    return 0;
}