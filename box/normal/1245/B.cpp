#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, r, p, s; cin >> n >> r >> p >> s;
        int R = r, P = p, S = s;
        string t; cin >> t;
        int win = 0;
        for(char c:t) {
            if(c == 'R' && p) {
                win++;
                p--;
            }
            if(c == 'P' && s) {
                    win++;
                    s--;
            }
            if(c == 'S' && r) {
                    win++;
                    r --;
            }
        }
        if(win >= (n+1)/2) {
            string ans;
            stack<char> left;
            while(r--) left.push('R');
            while(p--) left.push('P');
            while(s--) left.push('S');
            for(char c:t) {
                if(c == 'R') {
                    if(P) {
                        P--;
                        ans += 'P';
                    } else {
                        ans += left.top();
                        left.pop();
                    }
                }
                if(c == 'P') {
                    if(S) {
                        S--;
                        ans += 'S';
                    } else {
                        ans += left.top();
                        left.pop();
                    }
                }
                if(c == 'S') {
                    if(R) {
                        R--;
                        ans += 'R';
                    } else {
                        ans += left.top();
                        left.pop();
                    }
                }
            }
            cout << "YES\n" << ans << endl;
        }else cout <<"NO" << endl;
    }
}