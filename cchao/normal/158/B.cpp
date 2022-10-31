#include <bits/stdc++.h>
using namespace std;

int a[5]={}, n;

int main() {
    int n; cin >> n;
    int t; while(n--) { cin >> t; a[t]++; }
    while(a[1]&&a[3]) {
        a[1]--; a[3]--;
        a[4]++;
    }
    cout << a[4] + a[3] + (a[1] + a[2]*2 + 3) / 4 << endl;
    return 0;
}