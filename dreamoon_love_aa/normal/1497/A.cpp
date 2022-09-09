#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> d(101);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            d[x]++;
        }
        for(int i = 0; i < 101; i++) {
            if(d[i]) {
                cout << i << " ";
                d[i]--;
            }
        }
        for(int i = 0; i < 101; i++) {
            while(d[i]) {
                cout << i << " ";
                d[i]--;
            }
        }
    }
    return 0;
}