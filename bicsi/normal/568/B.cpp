#include <bits/stdc++.h>

using namespace std;
typedef int var;

#define MOD 1000000007

long long S[4005][4005], C[4005][4005];
long long Cicli[4005];

int init() {
    S[0][0] = 1;
    for(int n=1; n<=4000; n++) {
        C[n][0] = C[n][n] = 1;
        S[n][n] = 1;
        for(int k=1; k<n; k++) {
            S[n][k] = ((S[n-1][k] * k)%MOD + S[n-1][k-1]) % MOD;
            C[n][k] = C[n-1][k-1] + C[n-1][k];
            if(C[n][k] >= MOD) C[n][k] -= MOD;
        }
    }
    for(int n=1; n<=4000; n++) {
        for(int k=1; k<=n; k++) {
            Cicli[n] += S[n][k];
            if(Cicli[n] >= MOD)
                Cicli[n] -= MOD;
        }
    }
}

int main() {
    init();
    int n;
/*
    for(int i=1; i<=10; i++){ for(int j=1; j<=i; j++)
        cerr << S[i][j] << " ";
    cerr<<endl;}
*/
    cin>>n;

    long long ans = 1;
    for(int i=1; i<n; i++) {
        ans += C[n][i] * Cicli[i];
        ans %= MOD;
    }
    cout<<ans;

}