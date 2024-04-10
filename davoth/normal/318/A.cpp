#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    if(k<=n/2+n%2){
        k=k*2-1;
    }else k=(k-n/2-n%2)*2;
    cout << k;
    return 0;
}