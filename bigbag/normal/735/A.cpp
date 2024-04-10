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

const int max_n = 1, inf = 1011111111;

int n, k, a, b;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> s;
    a = s.find('G');
    b = s.find('T');
    if (a > b) {
        swap(a, b);
    }
    for (int i = a; i <= b; i += k) {
        if (s[i] == '#') {
            break;
        } else if (i == b) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}