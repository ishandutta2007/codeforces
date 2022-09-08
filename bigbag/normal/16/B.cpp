#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 111111111;

long long n, m;
pair <long long, long long> k[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        k[i].first = b;
        k[i].second = a;
    }
    sort(k, k + m);
    long long x = 0, sum = 0;
    for (int i = m - 1; i >= 0; --i) {
        if (x + k[i].second > n) {
            k[i].second = n - x;
        }
        x += k[i].second;
        sum += k[i].second * k[i].first;
        if (x >= n) {
            break;
        }
    }
    cout << sum;
    return 0;
}