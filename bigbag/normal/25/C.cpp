#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 333, inf = 111111111;

long long n, k, d[max_n][max_n];

void update(long long u, long long v, long long c) {
    if (d[u][v] > c) {
        d[u][v] = c;
        d[v][u] = c;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (d[i][j] > d[i][u] + d[u][v] + d[v][j]) {
                //cout << i << ' ' << j << ' ' << d[i][j] << "!" << endl;
                d[i][j] = d[i][u] + d[u][v] + d[v][j];
                d[j][i] = d[i][j];
            }
            /*if (d[i][j] > d[i][v] + d[v][u] + d[u][j]) {
                d[i][j] = d[i][v] + d[v][u] + d[u][j];
                d[j][i] = d[i][j];
            }*/
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> d[i][j];
        }
    }
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        long long u, v, c;
        cin >> u >> v >> c;
        update(u, v, c);
        update(v, u, c);
        //cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        long long sum = 0;
        for (int x = 1; x <= n; ++x) {
            for (int j = 1; j <= n; ++j) {
                //cout << d[x][j] << ' ';
                sum += d[x][j];
            }
            //cout << endl;
        }
        //cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        cout << sum / 2 << " ";
    }
    return 0;
}