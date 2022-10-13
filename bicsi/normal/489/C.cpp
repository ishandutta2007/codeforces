#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    if(s == 0) {
        if(n == 1) {
            cout << "0 0\n";
        } else {
            cout << "-1 -1\n";
        }
    } else {
        int sb = s, ss = s, take;
        string small = "", big = "";
        
        for(int i = 0; i < n; ++i) {
            take = min(9, ss - (i != n - 1));
            small += take + '0';
            ss -= take;
            
            take = min(9, sb);
            big += take + '0';
            sb -= take;
        }
        reverse(small.begin(), small.end());
        
        if(ss != 0) {
            cout << "-1 -1\n";
        } else {
            cout << small << " " << big << '\n';
        }
        
    }
    return 0;
}