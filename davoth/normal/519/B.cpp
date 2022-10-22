#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,a=0,b=0,c=0;
    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        a+=temp;
    }
    for(int i=0; i<n-1; i++){
        int temp;
        cin >> temp;
        b+=temp;
    }
    for(int i=0; i<n-2; i++){
        int temp;
        cin >> temp;
        c+=temp;
    }
    cout << a-b << ' ' << b-c;
    return 0;
}