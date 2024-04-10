#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int q, n, k;
    cin >> q;
    while (q--){
        cin >> n >> k;
        for (int i = 0; i < n; i++){
            cout << char('a' + i % k);
        }
        cout << endl;
    }
}