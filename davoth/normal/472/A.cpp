#include <bits/stdc++.h>
using namespace std;

bool prime(int n){
    for(int i=2; i<n; i++){
        if(n%i==0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for(int i=4; i<n; i+=2){
        if(!prime(n-i)){
            cout << i << ' ' << n-i;
            return 0;
        }
    }
    return 0;
}