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
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 777, inf = 1111111111;

int q, n, m, a[max_n][max_n];

int dist(int x, int y) {
    int res = 0;
    for (int i = 0; i < m; ++i) {
        res += abs(a[x][i] - a[y][i]);
    }
    return res;
}

int main() {
    //freopen("sample.in", "r", stdin);
    //ofstream O("output.txt");
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        int mid = n / 2;
        if (dist(mid - 1, mid) < dist(0, n - 1)) {
            printf("NO\n");
            //O << "NO" << endl;
        } else {
            printf("YES\n");
            //O << "YES" << endl;
        }
    }
    return 0;
}