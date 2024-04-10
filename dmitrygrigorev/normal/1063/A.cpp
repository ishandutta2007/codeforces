#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> kek;
    for (int i=0; i < s.size(); i++) kek.push_back(s[i]);
    sort(kek.begin(), kek.end());
    for (int i=0; i < kek.size(); i++) cout << kek[i];

}