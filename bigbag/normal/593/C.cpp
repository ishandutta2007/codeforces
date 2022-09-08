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

const int max_n = 52, inf = 1111111111;

int n, x[2][max_n], r[max_n];

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

string f(int num, int poz) {
    string res = "(";
    res += int_to_str(x[num][poz] / 2) + "*";
    res += "abs((abs((abs(((t-";
    res += int_to_str(poz) + ")-1))-abs(((t-";
    res += int_to_str(poz) + ")+1))))-2)))";
    if (poz + 1 == n) {
        return res;
    }
    return "(" + res + "+" + f(num, poz + 1) + ")";
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[0][i] >> x[1][i] >> r[i];
    }
    cout << f(0, 0) << endl;
    cout << f(1, 0) << endl;
    return 0;
}