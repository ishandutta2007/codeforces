#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_n = 1e5 + 100;

int n;
int a[max_n];
int b[max_n];
int d[max_n];

void relax(int i, int j) {
    for (int k = a[j] - i; k > 0; k -= i)
        if (b[k]) {
            d[j] = max(d[j], d[b[k]] + 1);
            break;
        }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[a[i]] = i;
    }
    d[1] = 1;
    for (int i = 2; i <= n; ++i) {
        d[i] = 1;
        int k = a[i];
        for (int j = 2; j * j <= k; ++j)
            if (k % j == 0) {
                relax(j, i);
                while (k % j == 0) k /= j;
            }
        if (k > 1)
            relax(k, i);
    }
    int ans = 1;
    for (int i = 2; i <= n; ++i)
        if (d[i] > d[ans])
            ans = i;
    cout << d[ans] << endl;

    return 0;
}