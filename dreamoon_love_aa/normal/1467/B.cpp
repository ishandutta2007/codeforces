#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
int a[300003];
int n;
bool bad(int x) {
    if(x == 1 || x == n) { return 0; }
    if(a[x] > a[x - 1] && a[x] > a[x + 1]) { return 1; }
    if(a[x] < a[x - 1] && a[x] < a[x + 1]) { return 1; }
    return 0;
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int num = 0;
    for(int i = 2; i < n; i++) {
        if(bad(i)) { num++; }
    }
    int an = num;
    for(int i = 2; i < n; i++) {
        int tmp = a[i];
        for(int j = i - 1; j <= i + 1; j += 2) {
            int tmp2 = num;
            for(int k = i - 1; k <= i + 1; k++) {
                num -= bad(k);
            }
            a[i] = a[j];
            for(int k = i - 1; k <= i + 1; k++) {
                num += bad(k);
            }
            an = min(an, num);
            num = tmp2;
            a[i] = tmp;
        }
    }
    cout << an << endl;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}