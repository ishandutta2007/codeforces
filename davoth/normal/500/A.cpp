#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,t,p=1;
    cin >> n >> t;
    int a[n-1];
    for(int i=0; i<n-1; i++){
        cin >> a[i];
    }
    while(p!=n){
        p=a[p-1]+p;
        if(p==t){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}