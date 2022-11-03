#include <bits/stdc++.h>
using namespace std;

bool Check(const string& from, const string& to)
{
    int max_suff = 0;
    int max_pref = 0;
    while (max_pref < (int) to.length() && 
           from[max_pref] == to[max_pref]) {
        ++max_pref;
    }
    while (max_suff < (int) to.length() && 
           from[from.length() - max_suff - 1] == 
           to[to.length() - max_suff - 1]) {
        ++max_suff;
    }
    for (int i = 0; i < (int) from.length(); ++i) {
        int cur_pref = i;
        int cur_suff = from.length() - i - 1;
        if (max_pref >= cur_pref && max_suff >= cur_suff) {
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    
    int diff_pos;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            diff_pos = i;
            break;
        }
    }
    
    int ans = 0;
    string w = s.substr(0, diff_pos) + t[diff_pos] + s.substr(diff_pos);
    if (Check(w, s) && Check(w, t)) {
        ++ans;
    }
    w = t.substr(0, diff_pos) + s[diff_pos] + t.substr(diff_pos);
    if (Check(w, s) && Check(w, t)) {
        ++ans;
    }
    
    cout << ans << endl;
    
    return 0;
}