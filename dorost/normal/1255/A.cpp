#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int q, a, b, n;
    cin >> q;
    while(q--){
        cin >> a >> b;
        int n = abs(a - b);
        if (n % 5 == 0){
            cout << n / 5;
        }else if(n % 5 < 3){
            cout << n / 5 + 1;
        }else {
            cout << n / 5 + 2;
        }
        cout << endl;
    }
}