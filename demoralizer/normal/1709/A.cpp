#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x,a[3];
    cin >> x;
    for(int i = 0; i < 3; i++){
        cin >> a[i];
    }
    if(x && a[x - 1] && a[a[x - 1] - 1]){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}