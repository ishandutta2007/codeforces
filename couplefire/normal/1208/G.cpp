#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005

int phi[MAXN];

void phi_1_to_n(int n) {
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    if(k == 1){
        cout << 3 << endl;
        return 0;
    }
    phi_1_to_n(MAXN);
    sort(phi+2, phi+n+1);
    long long ans = 0;
    for(int i = 1; i<=k+1; i++){
        ans += 0ll+phi[i+1];
    }
    cout << ans+1 << endl;
}