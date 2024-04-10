#include <bits/stdc++.h>
using namespace std;

void solve(){
    int s, n; cin >> s >> n;
    vector<int> digits, res(n);
    int og = s;
    while(s) digits.push_back(s%10), s/=10;
    s = og;
    for(int i = digits.size()-1, x = 0; i>=0; --i){
        int pw = 1;
        for(int j = 0; j<i; ++j) pw *= 10;
        s -= digits[i]*pw;
        while(digits[i]+s<n-x) --digits[i], s += pw, digits[i-1] += 10;
        for(int j = 0; digits[i] && x<n; ++j, ++x)
            res[x] += pw, --digits[i];
        res[n-1] += pw*digits[i]; digits[i] = 0;
    }
    for(int i = 0; i<n; ++i)
        cout << res[i] << ' ';
    cout << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}