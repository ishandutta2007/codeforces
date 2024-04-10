#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,a[10000];
    cin >> n;
    for(int i=0; i<n; i++){
        int l,r;
        cin >> l >> r;
        for(int j=l-1; j<r; j++){
            a[j]=i+1;
        }
    }
    int k;
    cin >> k;
    cout << n-a[k-1]+1;
    return 0;
}