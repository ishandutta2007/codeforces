#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 1000000007;
vector<int> fact;
int fpow(int a, int b){
    int ans = 1;
    int st = a;
    for (int i=0; i < 40; i++){
        int ba = (1LL << i) & b;
        if (ba != 0){
            ans *= st;
            ans %= MOD;
        }
        st*=st;
        st%=MOD;
    }
    return ans;
}
int C(int n, int k){
    int A = fact[n];
    int B = (fact[n-k] * fact[k]) % MOD;
    return (fpow(B, MOD-2) * A) % MOD;
}
signed main() {
    ios_base::sync_with_stdio(false);
    string n;
    int k;
    cin >> n >> k;
    int ans[2000];
    ans[1] = 0;
    fact.push_back(1);
    for (int i=1; i <= 5000; i++){
        fact.push_back((fact.back() * i) % MOD);
    }
    for (int i=2; i < 2000; i++){
        int b = 0;
        for (int j=0; j < 20; j++){
            int ba = (1LL << j) & i;
            if (ba != 0) b++;
        }
        ans[i] = ans[b]+1;
    }
    vector<int> cb(2000);
    fill(cb.begin(), cb.end(), 0);
    if (k == 0){
        cout << 1 << endl;
        return 0;
    }
    int b = 0;
    for (int i=0; i < n.size()-1; i++){
        if (n[i] == '0') continue;
        int ost = n.size() - i - 1;
        for (int j=0; j <= ost; j++){
            int H = C(ost, j);
            cb[j+b] += H;
            cb[j+b] %= MOD;
        }
        b++;
    }
    cb[b]++;
    if (n[n.size() - 1] == '1'){
        cb[b+1]++;
    }
    int answ = 0;
    for (int i=1;i < 2000; i++){
        int tro = 1 + ans[i];
        //cout << tro << " " << cb[i] << endl;
        if (tro == k){
            answ += cb[i];
            answ %= MOD;
        }
    }
    if (k == 1) answ--;
    cout << answ << endl;
    return 0;
}