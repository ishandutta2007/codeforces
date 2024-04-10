#include <bits/stdc++.h>
using namespace std;
const int si=1e5+10;
int main() {
    int a[4],mx=0;
    for(int & i : a){
        cin >> i;
        if (i>mx) mx=i;
    }
    for(int i=0; i<4; i++) {
        if (a[i] != mx) cout << mx-a[i] << ' ';
    }
    return 0;
}