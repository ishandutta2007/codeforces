#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB push_back
using namespace std;
const int MAX_N = 1 << 20;
int a[MAX_N];
void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    long long an = 0;
    long long base = 0;
    for(int i = 0; i <= n; i++) {
        long long now = base;
        for(int j = i; j < n && j < i + 30; j++) {
            now += (long long)a[j] >> (j - i + 1);
        }
        an = max(an, now);
        base += a[i] - k;
    }
    cout << an << '\n';
}
int main() {
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}