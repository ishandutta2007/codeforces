#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;


const int kMod = 1e9 + 7;

struct ModInt {
  long long n;
  
  ModInt(long long n = 0) : n(n % kMod) {}
  ModInt operator+(const ModInt& oth) { return n + oth.n; }
  ModInt operator-(const ModInt& oth) { return n - oth.n; }
  ModInt operator*(const ModInt& oth) { return n * oth.n; }
  long long get() { return n < 0 ? n + kMod : n; }
};

ModInt lgpow(ModInt b, int e) {
  ModInt r;
  for (r = 1; e; e /= 2, b = b * b)
    if (e % 2) r = r * b;
  return r;
}
ModInt inv(ModInt x) { return lgpow(x, kMod - 2); }

vector<ModInt> CalcProbs(int n, int k) {
    map<pair<int, int>, vector<ModInt>> mem;

    if (mem.count(make_pair(n, k))) 
        return mem[make_pair(n, k)];

    vector<ModInt> ret(n + 1, 0);
    ret[n] = 1;
    
    vector<ModInt> invs(n + 3, 1);
    for (int i = 1; i <= n + 2; ++i)
        invs[i] = inv(i);

    for (int i = 0; i < k; ++i) {
        vector<ModInt> new_ret(n + 1, 0);
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= j; ++k) {
                new_ret[k] = new_ret[k] + ret[j] * invs[j + 1];
            }
        }
        swap(ret, new_ret);
    }

    return mem[make_pair(n, k)] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<pair<long long, int>> v;    

    long long n; cin >> n;
    int k; cin >> k;

    for (long long d = 2; d * d <= n; ++d) {
        int e = 0;
        while (n % d == 0) {
            ++e;
            n /= d;
        }
        if (e) v.emplace_back(d, e);
    }
    
    if (n > 1) {
        v.emplace_back(n, 1);
    }

    vector<pair<long long, ModInt>> ret;
    ret.emplace_back(1LL, ModInt(1));
    
    for (auto p : v) {
//        cerr << p.first << "^" << p.second << endl;
        auto probs = CalcProbs(p.second, k);
//        for (auto x : probs) cerr << x.get() << " "; cerr << endl;

        vector<pair<long long, ModInt>> new_ret;    
        for (auto x : ret) {
            long long pw = 1;
            for (int i = 0; i <= p.second; ++i) {
                new_ret.emplace_back(x.first * pw, 
                        x.second * probs[i]);
                pw *= p.first;
            }
        }
        swap(ret, new_ret);
    }

    ModInt ans = 0;
    for (auto p : ret)
        ans = ans + p.second * p.first;
    cout << ans.get() << endl;

    return 0;
}