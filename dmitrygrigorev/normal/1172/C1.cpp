#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 998244353;
int sum(int a, int b){
    if (a+b<0) return a+b+mod;
    if (a+b >= mod) return a+b-mod;
    return a+b;
} 
int mult(int a, int b){
    return ((ll) a * (ll) b) % (ll) mod;
}
int pw(int a, int b){
    if (b==0) return 1;
    if (b==1) return a;
    if (b%2!=0) return mult(a, pw(a, b-1));
    int R = pw(a, b/2);
    return mult(R, R);
}
int rev(int a){
    return pw(a, mod-2);
}
const int K = 5000;
main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), w(n);
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> w[i];
    vector<int> prob(m+1);
    fill(prob.begin(), prob.end(), 0);
    prob[0] = 1;
    int sp=0, so=0;
    for (int i=0; i < n; i++){
        if (a[i] == 1) sp += w[i];
        else so += w[i];
    }
    vector<int> deg(2*K+1);
    for (int i=-K; i <= K; i++){
        int N = sp+so+i;
        if (N < 0 || N >= mod) continue;
        deg[i+K] = rev(N);
    }
    for (int i=0; i < m; i++){
        for (int j=i; j >= 0; j--){
            int pl = sp+j, ot = so-(i-j);
            if (ot < 0) continue;
            int M = j-(i-j);
            int R = deg[M+K];
            prob[j+1] = sum(prob[j+1], mult(prob[j], mult(pl, R)));
            prob[j] = mult(prob[j], mult(ot, R));
        }
    }
    int a1 = 0;
    int M = 1;
    for (int i=0; i <= m; i++){
        a1 = sum(a1, mult(M, prob[i]));
        M = mult(M, mult(sp+i+1, rev(sp+i)));
    }
    int a2 = 0;
    int T = 1;
    for (int i=m; i >= 0; i--){
        a2 = sum(a2, mult(T, prob[i]));
        int E = m-i;
        T = mult(T, mult(so-E-1, rev(so-E)));
        if (T==0) continue;
    }
    for (int i=0; i < n; i++){
        if (a[i] == 0){
            cout << mult(w[i], a2) << "\n";
        }
        else cout << mult(w[i], a1) << "\n";
    }
}