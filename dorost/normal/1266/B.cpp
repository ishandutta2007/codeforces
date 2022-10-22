#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    ll x;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (x % 14 < 7 && x % 14 != 0 && x > 14){
            cout << "YES";
        }else {
            cout << "NO";
        }
        cout << endl;
    }
}