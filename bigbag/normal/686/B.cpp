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

const int max_n = 111, inf = 1111111111;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        pair<int, int> mn = make_pair(inf, inf);
        for (int j = i; j < n; ++j) {
            mn = min(mn, make_pair(a[j], j));
        }
        for (int j = mn.second; j > i; --j) {
            cout << j << " " << j + 1 << endl;
            swap(a[j], a[j - 1]);
        }
        /*for (int j = 0; j < n; ++j) {
            cout << a[j] << " ";
        }
        cout << endl;*/
    }
    return 0;
}