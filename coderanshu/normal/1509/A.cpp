#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &i:a) {
            cin >> i;
        }
        sort(a.begin(),a.end(),[&](int x, int y) {
            return x % 2 < y % 2;
        });
        for(auto i:a) {
            cout << i << '\n';
        }
    }
    return 0;
}