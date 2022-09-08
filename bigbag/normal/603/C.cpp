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

int n, k, a, res;

int grr(int x) {
    if (k % 2 == 1) {
        if (x == 1 || x == 3) {
            return 1;
        }
        if (x == 2) {
            return 0;
        }
        if (x % 2 == 1) {
            return 0;
        }
        int cnt = 0;
        while (x % 2 == 0) {
            ++cnt;
            x /= 2;
        }
        if (x == 3) {
            if (cnt % 2 == 0) {
                return 1;
            }
            return 2;
        }
        if (cnt % 2 == 1) {
            return 1;
        }
        return 2;
    }
    if (x == 1) {
        return 1;
    }
    if (x == 2) {
        return 2;
    }
    return (x % 2) ^ 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    while (n--) {
        scanf("%d", &a);
        res ^= grr(a);
    }
    if (res) {
        printf("Kevin\n");
    } else {
        printf("Nicky\n");
    }
    return 0;
}