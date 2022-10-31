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
        int sum = 0;
        for(int i = 0; i<n; i++) if(s[i] == '1') sum++; else sum--;
        if(((n-abs(sum))/2)%2 == 1) cout << "DA" << endl;
        else cout << "NET" << endl;
    }
}