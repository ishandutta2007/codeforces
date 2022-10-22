#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,r=0;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i=n-1; i>=1; i-=2){
        r+=a[i]-a[i-1];
    }
    cout << r;
    return 0;
}