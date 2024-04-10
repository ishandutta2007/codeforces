#include <bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int a, b;
    cin >> a >> b;
    int mn = 1e18, mx=-1;
    for (int i=0; i < k; i++){
        int d1 = i, d2 = k-i;
        if (min(d1, d2) != a) continue;
        for (int j=0; j < k; j++){
            int d3 = j, d4 = k-j;
            if (min(d3, d4) != b) continue;
            for (int e=0; e < n; e++){
                int T = j + k*e;
                int jump = (T-i)%(n*k);
                if (jump<0) jump += (n*k);
                //cout << i << " " << T << " " << jump << endl;
                int g = gcd(jump, n*k);
                int var = (n*k)/g;
                if (var > mx) mx = var;
                if (var < mn) mn = var;
            }
        }
    }
    cout << mn << " " << mx;
}