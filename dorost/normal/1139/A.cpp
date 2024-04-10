#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    string s;
    cin >> n >> s;
    ll ans = 0;
    for (int i = 0; i < n; i++){
        if (s[i] % 2 == 0){
            ans += i + 1;
        }
    }
    cout << ans;
}