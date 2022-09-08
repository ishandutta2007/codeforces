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

const int max_n = 111111, inf = 1111111111;

string a;
char mx;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a;
    int f = 0;
    for (int i = 0; i < a.length(); ++i) {
        mx = max(mx, a[i]);
        int x = a[i] - '0';
        if (x % 2 == 0) {
            ++f;
        }
    }
    if (f == 0) {
        cout << "-1" << endl;
        return 0;
    }
    if ((a[a.length() - 1] - '0') % 2) {
        int last = 0;
        for (int i = 0; i < a.length(); ++i) {
            if ((a[i] - '0') % 2 == 0) {
                if (a[i] < a[a.length() - 1]) {
                    swap(a[i], a[a.length() - 1]);
                    cout << a << endl;
                    return 0;
                }
                last = i;
            }
        }
        swap(a[last], a[a.length() - 1]);
        cout << a << endl;
        return 0;
    }
    return 0;
}