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

const int max_l = 111111, max_n = 11, inf = 1111111111;

int n;
string s;
vector<int> v[max_l];
multiset<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s >> n;
    for (int i = 0; i < n; ++i) {
        string b;
        cin >> b;
        for (int j = 0; j + b.length() <= s.length(); ++j) {
            if (s.substr(j, b.length()) == b) {
                v[j].push_back(b.length());
            }
        }
    }
    for (int i = 0; i < s.length(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            q.insert(i + v[i][j] - 1);
        }
    }
    q.insert(s.length());
    //cout << endl;
    int len = 0, poz = 0;
    for (int i = 0; i < s.length(); ++i) {
        int x = *q.lower_bound(i);
        //cout << i << ' ' << x << endl;
        if (len < x - i) {
            len = x - i;
            poz = i;
        }
        for (int j = 0; j < v[i].size(); ++j) {
            q.erase(q.find(i + v[i][j] - 1));
        }
    }
    cout << len << ' ' << poz << endl;
    return 0;
}