#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, x;
    cin >> n;
    map <int, bool> mp;
    while(n--){
        cin >> x;
        mp[x] = true;
    }
    int ans = 0;
    for (int i = 1; i < 601; i++){
        if(mp[i]){
            ans++;
        }
    }
    cout << ans;
}