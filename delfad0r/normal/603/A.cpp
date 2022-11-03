#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    int flip = 0, ans = 0;
    char last_b = '$';
    auto do_flip = [](char c) {
        return (c == '0') ? ('1') : ('0');
    };
    while(N--) {
        char b;
        cin >> b;
        if(flip & 1) {
            b = do_flip(b);
        }
        if(last_b == b and flip < 2) {
            ++flip;
            b = do_flip(b);
            ++ans;
        } else if(last_b != b) {
            ++ans;
        }
        last_b = b;
    }
    cout << ans << '\n';
}