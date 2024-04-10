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

const int max_n = 11, inf = 1111111111;

int n;
char a[max_n];
string s;

string int_to_str(int x) {
    string ret = "";
    if (x == 0) {
        ret = "0";
    }
    while (x != 0) {
        ret += x % 10 + '0';
        x /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; s.length() < n; ++i) {
        s += int_to_str(i);
    }
    cout << s[n - 1] << endl;
    return 0;
}