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

const int max_n = 111111, inf = 111111111;

string s;
vector <int> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    int x = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != ',') {
            x = x * 10 + s[i] - '0';
        } else {
            v.push_back(x);
            x = 0;
        }
    }
    v.push_back(x);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        if (i != 0) {
            cout << ',';
        }
        int poz = i;
        while (poz + 1 < v.size() && abs(v[poz] - v[poz + 1]) <= 1) {
            ++poz;
        }
        if (v[i] != v[poz]) {
            cout << v[i] << '-' << v[poz];
            i = poz;
        } else {
            cout << v[i];
            i = poz;
        }
    }
    return 0;
}