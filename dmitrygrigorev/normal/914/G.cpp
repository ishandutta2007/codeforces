#include <bits/stdc++.h>
#define int long long
using namespace std;
const int K = 1<<17;
int MOD = 1000000007;
int A[K], B[K], C[K];
vector<int> hadamard(vector<int> v){
    for (int step=K; step > 1; step /= 2){
        for (int start=0; start < K; start += step){
            for (int w=0; w < step/2; w++){
                int F = v[start+w] + v[start+step/2+w];
                int S = v[start+w] - v[start+step/2+w];
                v[start + w] = F;
                v[start+step/2+w] = S;
            }
        }
    }
    return v;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i=0; i < K; i++) A[i] = 0;
    for (int i=0; i < n; i++){
        int X;
        cin >> X;
        A[X]++;
    }
    for (int i=0; i < K; i++) B[i] = 0;
    for (int i=0; i < K; i++){
        int V = i;
        while (true){
            B[i] += A[V] * A[i-V];
            if (V == 0) break;
            V = (V-1) & i;
        }
        B[i] %= MOD;
    }
    vector<int> f, g;
    for (int i=0; i < K; i++){
        f.push_back(A[i]);
        g.push_back(A[i]);
    }
    f = hadamard(f);
    g = hadamard(g);
    for (int i=0; i < K; i++) f[i] *= g[i];
    f = hadamard(f);
    for (int i=0; i < K; i++) f[i] /= K;
    for (int i=0; i < K; i++) C[i] = f[i]%MOD;
    int fib[K];
    fib[0] = 0, fib[1] = 1;
    for (int i=2; i < K; i++) fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    for (int i=0; i < K; i++){
        A[i] *= fib[i];
        A[i] %= MOD;
        B[i] *= fib[i];
        B[i] %= MOD;
        C[i] *= fib[i];
        C[i] %= MOD;
    }
    int ans[K];
    for (int i=K-1; i >= 0; i--){
        int V = K-1-i, W=K-1-i;
        int a=0, b=0, c=0;
        while (true){
            a += A[i+V];
            b += B[i+V];
            c += C[i+V];
            if (V == 0) break;
            V = (V-1) & W;
        }
        a %= MOD, b %= MOD, c %= MOD;
        a *= b;
        a %= MOD;
        a *= c;
        a %= MOD;
        V = K-i-1;
        int th = 0;
        while (V > 0){
            th += ans[i+V];
            if (th >= MOD) th -= MOD;
            V = (V-1) & W;
        }
        a -= th;
        a %= MOD;
        a += MOD;
        a %= MOD;
        ans[i] = a;
    }
    int ret = 0;
    for (int i=1; i < K; i*=2) ret += ans[i];
    cout << ret % MOD << endl;
    return 0;
}