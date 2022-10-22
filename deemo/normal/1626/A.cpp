#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te; cin >> te;
    while (te--){
        string s; cin >> s;
        sort(s.begin(), s.end());
        cout << s << "\n";
    }
    return 0;
}