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

long long a, b;

long long read() {
    long long n, o, pw = 1, res = 0;
    cin >> n >> o;
    for (int i = 1; i < n; ++i) {
        pw *= o;
    }
    while (n--) {
        long long x;
        cin >> x;
        res += x * pw;
        pw /= o;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    a = read();
    b = read();
    if (a < b) {
        cout << "<";
    } else if (a > b) {
        cout << ">";
    } else {
        cout << "=";
    }
    cout << endl;
    return 0;
}