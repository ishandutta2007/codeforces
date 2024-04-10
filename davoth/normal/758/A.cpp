#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,r=0;
    cin >> n;
    int mx,a[n];
    cin >> mx;
    a[0]=mx;
    for(int i=1; i<n; i++){
        cin >> a[i];
        if(a[i]>mx) mx=a[i];
    }
    for(int i=0; i<n; i++){
        r+=mx-a[i];
    }
    cout << r;
    return 0;
}