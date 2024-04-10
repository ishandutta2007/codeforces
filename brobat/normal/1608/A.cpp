#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cout << i + 2 << " ";
        }
        cout << endl;
    }
}