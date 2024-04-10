#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    int k;
    cin >> n >> k;
    while(k--){
        if(!(n%10)) n/=10;
        else n--;
    }
    cout << n;
    return 0;
}