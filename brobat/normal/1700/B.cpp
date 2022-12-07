#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        deque <int> t;
        for(auto i : s) {
            int x = i - '0';
            t.push_back(9 - x);
        }
        if(t[0] == 0) {
            for(int i = 0; i < n; i++) t[i]++;
            t[n - 1]++;
            int carry = 0;
            for(int i = n - 1; i >= 0; i--) {
                t[i] += carry;
                carry = 0;
                if(t[i] >= 10) {
                    t[i] -= 10;
                    carry += 1;
                }
            }
            if(carry) {
                t.push_front(carry);
            }
        }
        for(auto i : t) cout << i;
        cout << '\n';
    }
    
    return 0;
}

// 9 8 7 9
// 1 
// 10001 - 9000 = OK
// 11111 - 9000 = OK.
// 11111 - 9999 = OK.
// goal is to make 11111
// 111 - 99 = 
// How about ---> I make 999, then add whatever
// 999 + 112 --->
// 9999 + 1112 --> 1000 + 1111 --> 1111