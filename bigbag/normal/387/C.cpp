#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int inf = 111111111;

struct very_long {
    int len;
    vector < pair<int, int> > pozs;
    bool operator < (very_long a) {
        if (len < a.len) return true;
        if (len > a.len) return false;
        for (int i = 0; i < min(pozs.size(), a.pozs.size()); ++i) {
            if (pozs[i].first != a.pozs[i].first || pozs[i].second != a.pozs[i].second) {
                if (pozs[i].first < a.pozs[i].first) {
                    return false;
                }
                if (pozs[i].first > a.pozs[i].first) {
                    return true;
                }
                 if (pozs[i].second != a.pozs[i].second)return pozs[i].second < a.pozs[i].second;
            }
        }
        if (pozs.size() < a.pozs.size()) {
            return true;
        }
        return false;
    }
    void Concat(very_long a) {
        for (int i = 0; i < a.pozs.size(); ++i) {
            pozs.push_back(make_pair(a.pozs[i].first + len, a.pozs[i].second));
        }
        len += a.len;
    }
    void write() {
        cout << len << endl;
        for (int i = 0; i < pozs.size(); ++i) {
            cout << pozs[i].first << ' ' << pozs[i].second << endl;
        }
        cout << endl;
    }
};

string s;

pair <int, very_long> next(int poz) {
    very_long x = very_long();
    x.pozs.push_back(make_pair(0, s[poz] - '0'));
    x.len = 1;
    ++poz;
    while (poz < s.length() && s[poz] == '0') {
        ++x.len;
        ++poz;
    }
    return make_pair(poz, x);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    vector <very_long> v;
    for (int i = 0; i < s.length();) {
        pair <int, very_long> x = next(i);
        v.push_back(x.second);
        i = x.first;
    }
    int ans = 0;
    very_long x = very_long();
    for (int i = 0; i + 1 < v.size(); ++i) {
        x.Concat(v[i]);
    }
    if (x < v[v.size() - 1]) {
        cout << 1 << endl;
        return 0;
    }
    x = very_long();
    x.len = 0;
    x.pozs.clear();
    for (int i = 0; i < v.size(); ++i) {
        //v[i].write();
        if (x < v[i]) {
            x.Concat(v[i]);
            ans = 1;
        } else {
            ++ans;
            x.Concat(v[i]);
        }
    }
    cout << ans << endl;
    return 0;
}