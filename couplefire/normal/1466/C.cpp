#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.length();
        int cnt = 0;
        for(int i = 1; i<n; i++){
            if(s[i] == s[i-1] || (i > 1 && s[i] == s[i-2])){
                cnt++;
                set<int> st;
                for(int j = max(0, i-2); j<=min(n-1, i+2); j++) st.insert(s[j]-'a');
                for(int j = 0; j<26; j++){
                    if(!st.count(j)){
                        s[i] = j+'a';
                        break;
                    }
                }
            }
        }
        cout << cnt << endl;
    }
}