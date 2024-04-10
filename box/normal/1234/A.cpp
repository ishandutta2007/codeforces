#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        long long tot = 0; int n = 0;
        cin >> n; int q = n;
        while(n--) {
            int v; cin >> v; tot += v;
        }
        cout << (1+(tot-1)/q) << endl;
    }
}