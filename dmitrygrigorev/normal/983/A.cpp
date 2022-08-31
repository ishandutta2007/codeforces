#include <bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i < n; i++){
        int p, q, b;
        cin >> p >> q >> b;
        int x = gcd(p, q);
        q /= x;
        int f = b;
        while (q != 1){
            int g = gcd(f, q);
            if (g==1) break;
            q /= g;
            f = g;
        }
        if (q==1) cout << "Finite" << "\n";
        else cout << "Infinite" << "\n";
    }
}