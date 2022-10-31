#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int cnt[26];
        for(int i = 0; i<26; i++) cnt[i] = 0;
        for(int i = 0; i<n; i++){
            string s; cin >> s;
            for(int j = 0; j<s.length(); j++) cnt[s[j]-'a']++;
        }
        bool flag = true;
        for(int i = 0; i<26; i++){
            if(cnt[i]%n != 0){
                flag = false;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}