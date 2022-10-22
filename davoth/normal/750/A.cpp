#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    int t=240-k,r=0,i=1;
    while(r<=t-i*5 && i<=n){
        r+=i*5;
        i++;
    }
    cout << i-1;
    return 0;
}