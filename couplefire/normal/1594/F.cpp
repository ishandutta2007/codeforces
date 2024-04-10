#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        ll s, n, k;
        cin >> s >> n >> k;
        cout << ((s==k || s<(n/k)*k+n)?"YES":"NO") << '\n';
    }
}