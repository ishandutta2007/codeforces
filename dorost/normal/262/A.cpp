#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n, k, a = 0, ans = 0;
    cin >> n >> k;
    string s;
    for(int i = 0; i < n; i++){
        a = 0;
        cin >> s;
        for (int j = 0; j < s.size(); j++){
            if(s[j] == '4' || s[j] == '7'){
                a++;
            }
        }
        ans += (a <= k);
    }
    cout << ans;
}