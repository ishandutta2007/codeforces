#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, k, x;
    cin >> n  >> k;
    map <int, int> mp;
    for (int i = 0; i < n; i++){
        cin >> x;
        mp[x] = i + 1;
    }
    if (mp.size() < k){
        cout << "NO";
    }else {
        cout << "YES" << endl;
        for (int i = 0; i < 101; i++){
           if (k == 0){
                break;
           }
           if(mp[i]){
                k--;
                cout << mp[i] << ' ';
           }
        }
    }
}