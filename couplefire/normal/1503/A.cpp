#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    if(s[0] == '0' || s[n-1] == '0'){
        cout << "NO" << endl;
        return;
    }
    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; i<n; i++) cnt0 += (s[i] == '0'), cnt1 += (s[i] == '1');
    if(cnt0 % 2 == 1){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int c0 = 0, c1 = 0;
    string res0 = "", res1 = "";
    for(int i = 0; i<n; i++){
        if(s[i] == '1'){
            if(c1 >= cnt1/2) res0 += ")", res1 += ")";
            else res0 += "(", res1 += "(";
            c1++;
        }
        else{
            if(c0%2 == 0) res0 += "(", res1 += ")";
            else res0 += ")", res1 += "(";
            c0++;
        }
    }
    cout << res0 << endl << res1 << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}