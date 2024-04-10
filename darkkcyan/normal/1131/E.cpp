#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define clog if (0) cerr

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<string> p(n);
    for (auto& s: p) cin >> s;
    
    array<ll, 26> mx_char;
    mx_char.fill(0);
    for (auto& s: p) {
        clog << s << endl;
        for (auto i: mx_char) clog << i << ' ';
        clog << endl;
        
        int same_pref = 0, same_suff = 0;
        while (same_pref < (int)s.size() and s[same_pref] == s[0]) ++ same_pref;
        while (same_suff < (int)s.size() and s.rbegin()[same_suff] == s.back()) ++same_suff;
        
        if (same_pref == (int)s.size()) {
            mx_char[s[0] - 'a'] += 1ll * (mx_char[s[0] - 'a'] + 1) * s.size();
        } else if (s[0] == s.back()) {
            if (mx_char[s[0] - 'a']) {
                mx_char[s[0] - 'a'] = same_pref + same_suff + 1;
            }
        } else {
            if (mx_char[s[0] - 'a']) {
                mx_char[s[0] - 'a'] = same_pref + 1;
            }
            if (mx_char[s.back() - 'a']) {
                mx_char[s.back() - 'a'] = same_suff + 1;
            }
        }
        
        for (int i = 0; i < 26; ++i) {
            if (i == s[0] - 'a' or i == s.back() - 'a') continue;
            mx_char[i] = mx_char[i] > 0;
        }
        
        for (int start = 0, end = 0; end < (int)s.size(); start = end) {
            while (s[start] == s[end]) ++end;
            mx_char[s[start] - 'a'] = max<ll>(mx_char[s[start] - 'a'], end - start);
        }
    }
    
    for (auto i: mx_char) clog << i << ' ' ;
    cout << *max_element(mx_char.begin(), mx_char.end());
    
    return 0;
}