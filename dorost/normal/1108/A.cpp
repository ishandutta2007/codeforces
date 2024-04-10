#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int q, l, r, a, b;
    cin >> q;
    while (q--){
        cin >> l >> r >> a >> b;
        if(l == a){
            if (r > b) {
                cout << l + 1 << ' ' << a  << endl;
            }else {
                cout << l << ' ' << a + 1 << endl;
            }
        }else {
            cout << l << ' ' << a << endl;
        }
    }
}