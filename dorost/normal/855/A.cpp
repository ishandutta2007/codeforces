#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++){
        cin >> s[i];
        bool f = false;
        for (int j = 0; j < i ;j++){
            if (s[i] == s[j]){
                f = true;
                break;
            }
        }
        if (f) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
}