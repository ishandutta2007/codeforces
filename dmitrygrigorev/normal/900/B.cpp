#include <bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int x, int y){
    if (y == 0) return x;
    return gcd(y, x%y);
}
signed main(){
    //freopen("input.txt", "r", stdin);
    int a, b, pos;
    cin >> a >> b >> pos;
    for (int i=0; i < 2e6; i++){
        int symb;
        for (int j=0; j <= 9; j++){
            if (10*a >= j*b) symb = j;
        }
        if (symb == pos){
            cout << i+1 << endl;
            return 0;
        }
        int A = 10*a - b*symb;
        int B = 10*b;
        A *= 10;
        int g = gcd(A, B);
        A /= g;
        B /= g;
        a=A, b=B;
    }
    cout << -1 << endl;
    return 0;
}