#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005
long long K[MAXN], B[MAXN], Y1[MAXN], Y2[MAXN], I1[MAXN], I2[MAXN];

int main() {
    long long n, x1, x2, k, b;
    cin>>n>>x1>>x2;

    for(int i=1; i<=n; i++) {
        cin>>k>>b;
        K[i] = k; B[i] = b;
        Y1[i] = k*x1 + b;
        Y2[i] = k*x2 + b;
        I1[i] = I2[i] = i;
    }

    sort(I1+1, I1+n+1, [](int a, int b) {
        if(Y1[a] == Y1[b])
            if(K[a] == K[b]) return a < b;
            else return K[a] < K[b];
        else
            return Y1[a] < Y1[b];
    });

    sort(I2+1, I2+n+1, [](int a, int b) {
        if(Y2[a] == Y2[b])
            if(K[a] == K[b]) return a < b;
            else return K[a] > K[b];
        else
            return Y2[a] < Y2[b];
    });

    for(int i=1; i<=n; i++) {
        if(I1[i] != I2[i]) {
            cout<<"YES";
            return 0;
        }
    }

    cout<<"NO";
    return 0;
}