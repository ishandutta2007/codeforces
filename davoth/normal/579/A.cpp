#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,cnt=0;
    cin >> n;
    while(n){
        cnt+=n%2;
        n/=2;
    }
    cout << cnt;
    return 0;
}