#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 1011111111;

int k, x, a[max_n];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> k >> s;
    for (int i = 0; i < s.length(); ++i) {
        a[i] = 9 - (s[i] - '0');
        x += s[i] - '0';
    }
    sort(a, a + s.length());
    reverse(a, a + s.length());
    int i = 0;
    while (x < k) {
        x += a[i];
        ++i;
    }
    cout << i << endl;
    return 0;
}