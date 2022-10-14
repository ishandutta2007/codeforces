#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX_V = 1000;
void solve() {
    vector<int> ma(MAX_V + 1);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ma[x] = max(ma[x], i);
    }
    int an = -1;
    for(int i = 1;i <= MAX_V; i++) {
        for(int j = i; j <= MAX_V; j++) {
            if(__gcd(i, j) == 1 && ma[i] && ma[j]) {
                an = max(an, ma[i] + ma[j]);
            }
        }
    }
    cout << an << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}