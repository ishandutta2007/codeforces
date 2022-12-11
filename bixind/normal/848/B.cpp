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
#include <cstring>

using namespace std;

typedef long long ll;

typedef complex<double> cd;

const int inf = 1000000000;
const long long longinf = 1000000000000000000;
const double PI = 3.141592653589793;


void solve() {
    int n;
    cin >> n;
    vector<int> pos(n);
    vector<int> ans(n);
    vector<int> tp(n);
    vector<tuple<int, int, int, int> > srt;
    int wt, ht;
    cin >> wt >> ht;
    for (int i = 0; i < n; ++i) {
        int g, p, t;
        cin >> g >> p >> t;
        pos[i] = p;
        if (g == 2) {
//            h.push_back({p, t});
            srt.push_back({-t + p, p, 0, i});
            ans[i] = i;
            tp[i] = 0;
        }
        else {
//            v.push_back({p, t});
            srt.push_back({p - t, -t, 1, i});
            ans[i] = i;
            tp[i] = 1;
        }
    }
    sort(srt.begin(), srt.end());
    for (int i = 0; i < srt.size();) {
        int rh = get<0>(srt[i]);
        vector<int> buf1, buf2;
        while (i < srt.size() && get<0>(srt[i]) == rh) {
            if (get<2>(srt[i]) == 0) {
                buf1.push_back(get<3>(srt[i]));
            } else {
                buf2.push_back(get<3>(srt[i]));
            }
//            cout << get<3>(srt[i]) << endl;
            ++i;
        }
//        cout << endl;
        vector<int> buf3;
        buf3.reserve(buf1.size() + buf2.size());
        for (int i = 0; i < buf2.size(); ++i) {
            buf3.push_back(buf2[i]);
        }
        for (int i = 0; i < buf1.size(); ++i) {
            buf3.push_back(buf1[i]);
        }
        for (int i = 0; i < buf1.size(); ++i) {
            ans[buf3[i]] = buf1[i];
        }
        for (int i = 0; i < buf2.size(); ++i) {
            ans[buf3[buf1.size() + i]] = buf2[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (tp[ans[i]] == 0) {
            cout << wt << ' ' << pos[ans[i]] << "\n";
        } else {
            cout << pos[ans[i]] << ' ' << ht << "\n";
        }
    }
}

int main() {
    cout.precision(20);
    cin.tie(0);
//    srand(time(0));
    iostream::sync_with_stdio(false);
    solve();
    return 0;
}