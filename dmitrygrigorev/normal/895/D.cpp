#include <bits/stdc++.h>
#define int long long
#define D long double
using namespace std;
vector<int> fact, obr;
int MOD = 1000000007;
int ex(int a, int b){
    int ans = 1;
    int st = a;
    for (int i=0; i < 31; i++){
        int ba = (1LL << i) & b;
        if (ba == 0){
            st *= st;
            st %= MOD;
            continue;
        }
        ans *= st;
        ans %= MOD;
        st *= st;
        st %= MOD;
    }
    return ans;
}
int del(int a, int b){
    int num = obr[b];
    return (num*a) % MOD;
}
int z(int a, int b){
    int num = ex(b, MOD-2);
    return (num*a) % MOD;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    int v[26], cop[26];
    obr.push_back(0);
    for (int i=0; i < 26; i++) v[i] = 0;
    for (int i=0; i < a.size(); i++){
        v[a[i] - 'a']++;
    }
    for (int i=0; i < 26; i++) cop[i] = v[i];
    fact.push_back(1);
    for (int i=1; i <= 2e6; i++){
        obr.push_back(ex(i, MOD-2));
        fact.push_back((fact[i-1]*i) % MOD);
    }
    int glob = fact[a.size()];
    for (int i=0; i < 26; i++){
        if (v[i] != 0) glob = z(glob, fact[v[i]]);
    }
    int F = 0;
    int now = glob;
    for (int i=0; i < a.size(); i++){
        int has = a.size() - i;
        for (int j=0; j < 26; j++){
            if (i+1 == a.size()){
                if (j > a[i] - 'a') break;
            }
            else{
                if (j >= a[i] - 'a') break;
            }
            int var = del(now, has);
            var *= cop[j];
            F += var;
            F %= MOD;
        }
        now = del(now, has);
        now *= cop[a[i]-'a'];
        cop[a[i]-'a']--;
        now %= MOD;
    }
    int S = 0;
    now = glob;
    for (int i=0; i < b.size(); i++){
        int has = b.size() - i;
        for (int j=25; j >= 0; j--){
            if (i+1 == a.size()){
                if (j < b[i] - 'a') break;
            }
            else{
                if (j <= b[i] - 'a') break;
            }
            int var = del(now, has);
            var *= v[j];
            S += var;
            S %= MOD;
        }
        now = del(now, has);
        now *= v[b[i]-'a'];
        v[b[i]-'a']--;
        now %= MOD;
    }
    int res = glob - F - S;
    res %= MOD;
    if (res < 0) res += MOD;
    cout << res << endl;
    return 0;
}