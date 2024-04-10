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

int n, m, k;
ll a[max_n];
ll b[max_n];
int l[max_n], r[max_n];
ll d[max_n];


int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> l[i] >> r[i] >> d[i];
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        ++b[x];
        --b[y + 1];
    }
    ll sum = 0;
    for (int i = 1; i <= m; ++i) {
        sum += b[i];
        d[i] *= sum;
    }
    for (int i = 0; i < max_n; ++i)
        b[i] = 0;
    for (int i = 1; i <= m; ++i) {
        b[l[i]] += d[i];
        b[r[i] + 1] -= d[i];
    }
    sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += b[i];
        cout << a[i] + sum << " ";
    }
    cout << endl;
    return 0;
}