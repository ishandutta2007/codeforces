#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    if (n % 10 > 5){
        cout << (n + 9) / 10 * 10;
    }else {
        cout << n / 10 * 10;
    }
}