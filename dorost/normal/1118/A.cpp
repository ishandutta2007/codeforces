#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll q, n, a, b;
    cin >> q;
    while (q--){
        cin >> n >> a >> b;
        if (b < 2 * a) {
            cout << n / 2 * b + (n % 2 * a)<< endl;
        }else{
            cout <<  n * a << endl;
        }
    }
}