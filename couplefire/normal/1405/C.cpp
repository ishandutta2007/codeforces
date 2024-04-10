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
        char arr[k];
        if(n < k){
            cout << "YES" << endl;
            continue;
        }
        bool f1 = true;
        for(int i = 0; i<k; i++){
            char cur = '?';
            for(int j = i; j<n; j+=k){
                if(cur != '?' && s[j] != '?' && s[j] != cur){
                    cur = 'b';
                    break;
                }
                else if(s[j] == '1' || s[j] == '0') cur = s[j];
            }
            if(cur == 'b'){
                cout << "NO" << endl;
                f1 = false;
                break;
            }
            arr[i] = cur;
        }
        if(!f1){
            continue;
        }
        int mi0 = 0, ma0 = 0;
        for(int i = 0; i<k; i++){
            if(arr[i] == '0'){
                mi0++;
                ma0++;
            }
            else if(arr[i] == '?') ma0++;
        }
        if(mi0 <= k/2 && ma0 >= k/2){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}