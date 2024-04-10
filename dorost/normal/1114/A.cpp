#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    if (x > a) {
        cout << "NO";
    }else{
        a -= x;
        if (y > a + b) {
            cout << "NO";
        }else {
            b -= y;
            if (z > a + b + c) {
                cout << "NO";
            }else {
                cout << "YES";
            }
        }
    }
}