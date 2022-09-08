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

const int max_n = 1111, inf = 1111111111;

int n, a[max_n];
vector<int> v;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    v.push_back(1);
    while (cin >> s) {
        if (s == "=") {
            cin >> s;
            n = atoi(s.c_str());
            break;
        }
        if (s == "+") {
            v.push_back(1);
        }
        if (s == "-") {
            v.push_back(-1);
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 1) {
            a[i] = n;
        } else {
            a[i] = 1;
        }
    }
    int sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += a[i] * v[i];
    }
    if (sum < n) {
        cout << "Impossible" << endl;
        return 0;
    }
    for (int i = 0; i < v.size(); ++i) {
        int x = min(n - 1, sum - n);
        if (v[i] == 1) {
            a[i] -= x;
        } else {
            a[i] += x;
        }
        sum -= x;
    }
    if (sum > n) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << a[i];
        if (i + 1 < v.size()) {
            if (v[i + 1] == 1) {
                cout << " + ";
            } else {
                cout << " - ";
            }
        } else {
            cout << " = " << n << endl;
        }
    }
    return 0;
}