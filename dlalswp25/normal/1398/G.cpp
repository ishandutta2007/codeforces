#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll P = 998244353, R = 3;

int N = 524288;

ll pw(ll x, ll y) {
    ll ret = 1;
    while(y) {
        if(y & 1) ret = ret * x % P;
        x = x * x % P;
        y >>= 1;
    }
    return ret;
}

void fft(int N, vector<ll>& a, bool f) {
    ll i, j, k, x, y, z;
    j = 0;
    for(i = 1; i < N; i++) {
        for(k = N >> 1; j >= k; k >>= 1) j -= k;
        j += k;
        if(i < j) {
            k = a[i];
            a[i] = a[j];
            a[j] = k;
        }
    }
    for(i = 1; i < N; i <<= 1) {
        x = pw(f ? pw(R, P - 2) : R, P / i >> 1);
        for(j = 0; j < N; j += i << 1) {
            y = 1;
            for(k = 0; k < i; k++) {
                z = a[i | j | k] * y % P;
                a[i | j | k] = a[j | k] - z;
                if(a[i | j | k] < 0) a[i | j | k] += P;
                a[j | k] += z;
                if(a[j | k] >= P) a[j | k] -= P;
                y = y * x % P;
            }
        }
    }
    if(f) {
        j = pw(N, P - 2);
        for(i = 0; i < N; i++) a[i] = a[i] * j % P;
    }
}

void multiply(int N, vector<ll>& X, vector<ll>& Y) {
    fft(N, X, false);
    fft(N, Y, false);
    for(int i = 0; i < N; i++) X[i] = X[i] * Y[i] % P;
    fft(N, X, true);
}

vector<ll> A(N), B(N);
int M, XX, YY;
int ans[505050];
int Q;

int main() {
    scanf("%d%d%d", &M, &XX, &YY);
    M++;
    for(int i = 1; i <= M; i++) {
        int a; scanf("%d", &a);
        A[a] = 1;
        B[N / 2 - a - 1] = 1;
    }

    multiply(N, A, B);
    // for(int i = 0; i < N; i++) printf("%d ", A[i]); puts("");
    for(int i = 1; i <= XX; i++) {
        if(!A[N / 2 - 1 - i]) continue;
        int t = i + YY;
        for(int j = 1; j * t <= 500000; j++) ans[j * t] = 2 * t;
    } 

    // for(int i = 0; i < 10; i++) printf("%d ", V[1][i]); puts("");

    scanf("%d", &Q);
    while(Q--) {
        int l; scanf("%d", &l);
        l /= 2;
        printf("%d ", ans[l] ? ans[l] : -1);
    }
    puts("");
    
    return 0;
}