#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main(){
    int n;
    cin >> n;
    map <int, bool> mp;
    int x, y;
    cin >> x;
    for (int i = 0; i < x; i++){
        cin >> y;
        mp[y] = true;
    }
    cin >> y;
    for (int i = 0; i < y; i++){
        cin >> x;
        mp[x] = true;
    }
    for (int i = 1; i <= n; i++){
        if (!mp[i]){
            cout << "Oh, my keyboard!";
            return 0;
        }
    }
    cout << "I become the guy.";
}