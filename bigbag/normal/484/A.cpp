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

int n;
long long l, r;

string two(long long x) {
    if (x == 0) {
        return "0";
    }
    string res = "";
    while (x) {
        res += x % 2 + '0';
        x /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

long long ans(long long l, long long r) {
    string a = two(l), b = two(r);
    int poz = -1;
    for (int i = 0; i < b.length(); ++i) {
        if (b[i] == '0') {
            poz = i;
            break;
        }
    }
    if (poz == -1) {
        return r;
    }
    if (a.length() < b.length()) {
        long long x = 1;
        for (int i = 1; i < b.length(); ++i) {
            x *= 2;
        }
        return x - 1;
    }
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] != b[i]) {
            //cout << i << endl;
            poz = -1;
            for (int j = i + 1; j < b.length(); ++j) {
                if (b[j] == '0') {
                    poz = j;
                    break;
                }
            }
            if (poz == -1) {
                return r;
            }
            b[i] = '0';
            for (int j = i + 1; j < b.length(); ++j) {
                b[j] = '1';
            }
            break;
        }
    }
    long long res = 0;
    //cout << b << endl;
    for (int i = 0; i < b.length(); ++i) {
        if (b[i] == '1') res += ((1LL) << (b.length() - i - 1));
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    while (n--) {
        cin >> l >> r;
        cout << ans(l, r) << endl;
    }
    return 0;
}