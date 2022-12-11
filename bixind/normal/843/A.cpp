#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>
#include <cstdlib>
#include <map>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <stdlib.h>
#include <assert.h>
#include <complex>

using namespace std;

typedef long long ll;

typedef complex<double> cd;

const int inf = 1000000000;
const long long longinf = 1000000000000000000;
const double PI = 3.141592653589793;

const int MAXN = 100010;


void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<pair<int, int> > srt(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        srt[i].first = v[i];
        srt[i].second = i;
    }
    sort(srt.begin(), srt.end());
    vector<int> v1(n);
    for (int i = 0; i < n; ++i) {
        v1[srt[i].second] = i;
    }
//    for (int i = 0; i < n; ++i) {
//        cout << v1[i] << ' ';
//    }
//    cout << endl;
    vector<vector<int> > cl;
    vector<bool> used(n, false);
    for (int i = 0; i <n; ++i ){
        if (!used[i]) {
            int j = i;
            vector<int> buf;
            while (!used[j]) {
                buf.push_back(j);
                used[j] = true;
                j = v1[j];
            }
            cl.push_back(buf);
        }
    }
    cout << cl.size() << "\n";
    for (auto& w: cl) {
        cout << w.size() << ' ';
        for (auto c: w) {
            cout << c + 1 << ' ';
        }
        cout << "\n";
    }
}

int main() {
    cout.precision(20);
    cin.tie(0);
    iostream::sync_with_stdio(false);
    solve();
    return 0;
}