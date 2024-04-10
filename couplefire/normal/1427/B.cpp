#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int numlose = 0, numwin = 0;
        int ans = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == 'W') numwin++;
            else numlose++;
        }
        char prev = 'L';
        for(int i = 0; i<s.length(); i++){
            if(s[i] == 'W' && prev == 'W') ans += 2;
            else if(s[i] == 'W') ans += 1;
            prev = s[i];
        }
        if(k == 0){
            cout << ans << endl;
            continue;
        }
        if(numwin + k >= n){
            cout << 2*n-1 << endl;
            continue;
        }
        if(numwin == 0){
            cout << max(0,2*k-1) << endl;
            continue;
        }
        int fwin, lwin;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == 'W'){
                fwin = i;
                break;
            }
        }
        for(int i = s.length()-1; i>=0; i--){
            if(s[i] == 'W'){
                lwin = i;
                break;
            }
        }
        vector<int> len;
        int curlen = 0;
        for(int i = fwin; i<=lwin; i++){
            if(s[i] == 'L') curlen++;
            else{
                if(curlen != 0) len.push_back(curlen);
                curlen = 0;
            }
        }
        sort(len.begin(), len.end());
        for(auto i : len){
            if(k >= i){
                k -= i;
                ans += 2*i+1;
            }
            else{
                ans += 2*k;
                k = 0;
                break;
            }
        }
        if(k > 0){
            ans += 2*min(fwin, k);
            k -= min(fwin, k);
        }
        if(k > 0){
            ans += 2*min(k, n-1-lwin);
        }
        cout << ans << endl;
    }
}