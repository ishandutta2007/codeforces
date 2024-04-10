#include <map>
#include <set>
#include <stack>
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

const int max_n = 1111111, inf = 1111111111;

int n;
vector<pair<int, int> > v;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    int a = p1.first + p1.second;
    int b = p2.first + p2.second;
    if (a != b) {
        return a < b;
    }
    return p1.first > p2.first;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i * 7 <= n; ++i) {
        int x = n - i * 7;
        if (x % 4 == 0) {
            v.push_back(make_pair(x / 4, i));
        }
    }
    if (v.size() == 0) {
        cout << -1 << endl;
        return 0;
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v[0].first; ++i) {
        printf("4");
    }
    for (int i = 0; i < v[0].second; ++i) {
        printf("7");
    }
    return 0;
}