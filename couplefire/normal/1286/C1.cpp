#include <bits/stdc++.h>
 
using namespace std;
using Freq=array<int,26>;
map<Freq, int> mp[111];
 
Freq f(string s){
    Freq a = {};
    for (char x: s)a[x-'a']++;
    return a;
}
void solve() {
    int n; cin >> n;
    cout << "? 1 " << n << endl;
    string s;
    for (int _ = 0; _ < (n)*(n+1)/2; _++) {
        cin >> s;
        mp[s.size()][f(s)]++;
    }
    if (n == 1) {
        cout << "! "<< s; return;
    }
    cout << "? 2 " << n << endl;
    for (int _ = 0; _ < (n)*(n-1)/2; _++) {
        cin >> s;
        auto it = mp[s.size()].find(f(s));
        it->second--;
        if (it->second == 0) {
            mp[s.size()].erase(it);
        } 
    }
    string res(n, '#');
    for (int i = 1; i <= n; i++) {
        auto cnt = mp[i].begin()->first;
        for (int k = 0; k < i-1; k++) {
            cnt[res[k]-'a']--;
        }
        for (int x = 0; x < 26; x++) {
            if (cnt[x]) {
                res[i-1] = 'a'+x;
                break;
            }
        }
    }
    cout << "! " << res;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    cout << endl;
}