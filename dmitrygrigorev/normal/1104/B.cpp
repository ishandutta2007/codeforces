#include<bits/stdc++.h>
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int moves=0;
    vector<char> kek;
    for (int i=0; i < s.size(); i++){
        if (kek.size() > 0 && s[i] == kek.back()){
            moves++;
            kek.pop_back();
        }
        else kek.push_back(s[i]);
    }
    if (moves%2==0) cout << "No";
    else cout << "Yes";
}