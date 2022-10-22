#include <bits/stdc++.h>
using namespace std;
const int si=1e5+10;
int main() {
    int n,h;
    cin >> n >> h;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        int hp=h;
        sort(a,a+i);
        for(int j=i-1; j>=0; j-=2){
            hp-=a[j];
            if(hp<0){
                cout << i-1;
                return 0;
            }
        }
    }
    cout << n;
    return 0;
}