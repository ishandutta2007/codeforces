#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<int> posa;
        for(int i = 0; i<n; i++){
            if(s[i] == 'A') posa.push_back(i);
        }
        posa.push_back(n);
        int ans = 0;
        for(int i = 1; i<posa.size(); i++){
            ans = max(ans, posa[i]-posa[i-1]-1);
        }
        cout << ans << endl;
    }
}