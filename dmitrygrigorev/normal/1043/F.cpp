#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> MODS = {1000000007, 1000000009, 27644437};
const int K = 300010;
int dp[K][10][3];
int cc[K][11][3];
int del[300010];
int fact[K][3];
int pw(int a, int b, int MD){
    if (b==1) return a%MD;
    if (b%2==1){
        int res = pw(a, b-1, MD);
        return (res*a)%MD;
    }
    int res = pw(a, b/2, MD);
    return (res*res)%MD;
}
int C(int n, int k, int ind){
    int A = fact[n][ind] % MODS[ind];
    int B = (fact[k][ind] * fact[n-k][ind]) % MODS[ind];
    return (A * pw(B, MODS[ind]-2, MODS[ind])) % MODS[ind];
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i=0; i < 3; i++) fact[0][i] = 1;
    for (int i=1; i < K; i++) for (int j=0; j < 3; j++) fact[i][j] = (fact[i-1][j] * i) % MODS[j];
    for (int i=0; i < K; i++){
        for (int j=0; j <= 10; j++){
            for (int e=0;e<3;e++){
                if (j > i) continue;
                if (j == 0 || j == i){
                    cc[i][j][e]=1;
                    continue;
                }
                cc[i][j][e] = (cc[i-1][j][e] + cc[i-1][j-1][e]) % MODS[e];
            }
        }
    }
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    for (int i=0; i < n; i++) del[v[i]]++;
    for (int i=1; i < K; i++){
        for (int j=i+i; j < K; j+=i) del[i] += del[j];
    }
    for (int i=K-1; i >= 1; i--){
        for (int j=1; j <= 10; j++){
            if (del[i] < j){
                for (int e=0;e<3;e++) dp[i][j-1][e] = 0;
                break;
            }
            //out << i << " " << j << endl;
            for (int a=0; a < 3; a++){
                //cout << del[i] << " " << j << endl;
                int how = cc[del[i]][j][a];
                for (int p=i+i;p<K;p+=i) how -= dp[p][j-1][a];
                how %= MODS[a];
                if (how < 0) how += MODS[a];
                dp[i][j-1][a] = how;
            }
        }
    }
    for (int j=1; j <= 10; j++){
        bool can = false;
        for (int p=0; p <= 2; p++) if (dp[1][j-1][p]) can = true;
        if (can){
            cout << j;
            return 0;
        }
    }
    cout << -1;





}