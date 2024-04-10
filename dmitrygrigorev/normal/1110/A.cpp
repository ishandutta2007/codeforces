#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int b, k;
    cin >> b >> k;
    bool g = true;
    for (int i=0; i < k; i++){
        int x;
        cin >> x;
        if (x % 2 == 0 || (b % 2 == 0 && i != k-1)){
            continue;
        }
        g ^= 1;
    }
    if (g) cout << "even";
    else cout << "odd";
}