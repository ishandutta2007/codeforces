#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    if (n % 3 == 0){
        cout << n / 3 * 2;
    }else{
        cout << n / 3 * 2 + 1;
    }
}