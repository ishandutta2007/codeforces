#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,h;
    cin >> n >> h;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int cnt=n;
    for(int i=0; i<n; i++){
        if(a[i]>h) cnt++;
    }
    cout << cnt;
    return 0;
}