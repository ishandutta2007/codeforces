#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    int a = x + z, b = y + z;
    if (x > b && y < a){
        cout << '+';
    }else if (x < b && y > a) {
        cout << '-';
    }else if (x == y && z == 0){
        cout << '0';
    }else {
        cout << '?';
    }
}