#include<bits/stdc++.h>
using namespace std;
int main() {
    int T, n, x;
    cin >> T;
    while(T--) {
        cin >> n;
        int AA = 0, now = 0;
        for(int i = 1; i <= n; i++) {
            cin >> x;
            now ^= x;
            if(!now && i % 2) AA = i;
        }
        if(!AA || now) { cout << "NO\n"; continue; }
        vector<int> an;
        for(int i = 1; i + 1 < n; i += 2) {
            if(i == AA) i++;
            an.push_back(i);
        }
        cout << "YES\n" << an.size() * 2 << '\n';
        for(int x: an) cout << x << ' ';
        reverse(an.begin(), an.end());
        for(int x: an) cout << x << ' ';
        cout << '\n';
    }
}