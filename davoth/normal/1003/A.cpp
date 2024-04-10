#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,a[100]={0},mx=0;
    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        a[temp-1]++;
        if(a[temp-1]>mx) mx=a[temp-1];
    }
    cout << mx;
    return 0;
}