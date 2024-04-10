#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, i, j, a, b;
    cin >> n >> m >> i >> j >> a >> b;
    int ans = -1;
    if ((i - 1) % a == 0 && (j - 1) % b == 0) {
        int ma = (i - 1) / a;
        int mb = (j - 1) / b;
        if (ma == mb) 
            ans = ma;
        else if (ma < mb) {
            if (1 + a <= n && ma % 2 == mb % 2)
                ans = mb;
        } else {
            if (1 + b <= m && ma % 2 == mb % 2)
                ans = ma;
        }
    }
    if ((i - 1) % a == 0 && (m - j) % b == 0) {
        int ma = (i - 1) / a;
        int mb = (m - j) / b;
        if (ma == mb) {
            if (ans == -1 || ma < ans)
                ans = ma;
        } else if (ma < mb) {
            if (ma % 2 == mb % 2 && 1 + a <= n)
                if (ans == -1 || mb < ans)
                    ans = mb;
        } else {
            if (ma % 2 == mb % 2  && m - b >= 1)
                if (ans == -1 || ma < ans)
                    ans = ma;
        }
    }
    if ((n - i) % a == 0 && (j - 1) % b == 0) {
        int ma = (n - i) / a;
        int mb = (j - 1) / b;
        if (ma == mb) {
            if (ans == -1 || ma < ans)
                ans = ma;
        } else if (ma < mb) {
            if (ma % 2 == mb % 2 && n - a >= 1)
                if (ans == -1 || mb < ans)
                    ans = mb;
        } else {
            if (ma % 2 == mb % 2 && 1 + b <= m)
                if (ans == -1 || ma < ans)
                    ans = ma;
        }
    }
    if ((n - i) % a == 0 && (m - j) % b == 0) {
        int ma = (n - i) / a;
        int mb = (m - j) / b;
        if (ma == mb) {
            if (ans == -1 || ma < ans)
                ans = ma;
        } else if (ma < mb) {
            if (ma % 2 == mb % 2 && n - a >= 1)
                if (ans == -1 || mb < ans)
                    ans = mb;
        } else {
            if (ma % 2 == mb % 2 && m - b >= 1)
                if (ans == -1 || ma < ans)
                    ans = ma;
        }
    }
    if (ans == -1) {
        cout << "Poor Inna and pony!" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}