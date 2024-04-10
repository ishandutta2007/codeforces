#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <string>
#include <cstring>
#include <functional>
#include <numeric>
#include <random>
#include <cassert>
#include <cmath>
#include <ctime>
#include <queue>
#include <deque>

#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

template<class iterator> void output(iterator begin, iterator end, ostream &out = cerr) {
    while (begin != end) {
        out << (*begin) << " ";
        begin++;
    }
    out << endl;
}

template<class T> void output(T &x, ostream& out = cerr) {
    output(x.begin(), x.end(), out);
}

template<class T> int chkmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T> int chkmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return 1;
    }
    return 0;
}

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector<int> pref_func(string &s) {
    int n = s.size();
    vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        p[i] = p[i - 1];
        while (p[i] > 0 && s[i] != s[p[i]]) {
            p[i] = p[p[i] - 1];
        }
        if (s[i] == s[p[i]]) {
            p[i]++;
        }
    }
    return p;
}

string s, t;
int n, m, n0, m0, n1, m1, s0, s1;
vector<int> p;

int main() {
    fast_io();
    cin >> s >> t;
    n = s.size();
    m = t.size();
    p = pref_func(t);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            n0++;
        }
        else {
            n1++;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (t[i] == '0') {
            m0++;
        }
        else {
            m1++;
        }
    }
    for (int i = p[m - 1]; i < m; ++i) {
        if (t[i] == '0') {
            s0++;
        }
        else {
            s1++;
        }
    }
    string ans;
    if (n0 < m0 || n1 < m1) {
        ans = s;
    }
    else {
        n0 -= m0;
        n1 -= m1;
        ans = t;
        while (n0 >= s0 && n1 >= s1) {
            ans += t.substr(p[m - 1], m - p[m - 1]);
            n0 -= s0;
            n1 -= s1;
        }
        for (int i = 0; i < n0; ++i) {
            ans.push_back('0');
        }
        for (int i = 0; i < n1; ++i) {
            ans.push_back('1');
        }
    }
    cout << ans << endl;
}