#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
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

const int max_v = 1e6 + 100;

int v;
pii a[10];
int ans[max_v];

bool cmp(const pii& a, const pii& b) {
    return (a.first < b.first || 
        a.first == b.first && a.second > b.second);
}

int main() {
    cin >> v;
    for (int i = 0; i < 9; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + 9, cmp);
    int n = v / a[0].first;
    v %= a[0].first;
    int N = n; 
    if (n == 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < N; ++i)
        ans[i] = a[0].second;
    for (int i = 9; i > a[0].second; --i) {
        int j = 1;
        while (a[j].second != i) ++j;
        int cnt = v / (a[j].first - a[0].first);
        for (int k = n - 1; k >= n - cnt; --k)
            ans[k] = i;
        v %= (a[j].first - a[0].first);
        n -= cnt;
    }
    for (int i = N - 1; i >= 0; --i)
        cout << ans[i];
    cout << endl;

    return 0;
}