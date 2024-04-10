#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int d;
    if(a[0]%2+a[1]%2+a[2]%2<=1) d=1;
    else d=0;
    for(int i=0; i<n; i++){
        if(a[i]%2==d){
            cout << i+1;
            break;
        }
    }
    return 0;
}