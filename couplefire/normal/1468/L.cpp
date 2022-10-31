#include <bits/stdc++.h>
using namespace std;

const int Np = 1000000 + 150;
int prime[Np], cntp;
bool not_prime[Np];
void find_prime(int n){
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i < n; ++i){
        if (!not_prime[i]) prime[++cntp] = i;
        for (int j = 1, p = prime[j]; j <= cntp && i * p <= n; p = prime[++j]){
            not_prime[i * p] = true; if (i % p == 0) break;
        }
    }
}

long long fastmul(long long x, long long y, long long M){
    long long res = 0;
    for (x %= M; y; y >>= 1){
        if (y & 1) res = (res + x) % M;
        x = (x + x) % M;
    }
    return res;
}

long long fastpow(long long x, long long n, long long M){
    long long res = M != 1;
    for (x %= M; n; n >>= 1){
        if (n & 1) res = fastmul(res, x, M);
        x = fastmul(x, x, M);
    }
    return res;
}

long long fastpow2(long long x, long long n, long long M){
    long long res = M != 1;
    for (x %= M; n; n >>= 1){
        if (n & 1) res = res * x % M;
        x = x * x % M;
    }
    return res;
}

struct MR{
    const long long b[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    bool operator()(long long n){
        if (~n & 1) return n == 2;
        long long t = n - 1; int s = 0; while (~t & 1){ t >>= 1; ++s; }
        for (int i = 0, j; i < 7; ++i){
            if (b[i] % n == 0) return true;
            long long tmp = fastpow(b[i], t, n); if (tmp == 1) continue;
            for (j = 0; j < s; ++j){ if (tmp == n - 1 ) break; tmp = fastmul(tmp, tmp, n); }
            if (j == s) return false;
        }
        return true;
    }
} mr;

const int N = 1000 + 9;
const int N2 = 1000000;
const __int128 inf = LLONG_MAX;

long long x[N];

unordered_map<long long, long long> mp;
unordered_map<long long, vector<long long>> mp2;

struct Cmp{
    bool operator()(const long long &a, const long long &b) const{
        return mp2[a].size() > mp2[b].size();
    }
};

int main(){
    find_prime(N2);
    int n, k;
    scanf("%d %d", &n, &k);
    if (k == 1){
        printf("0\n");
        return 0;
    }
    for (int i = 1; i <= n; ++i){
        scanf("%lld", x + i);
    }
    for (int i = 1; i <= n; ++i){
        mp[x[i]] = 0;
        if (x[i] > N2){
            if (mr(x[i])) mp[x[i]] = x[i];
            else {
                long long t = sqrt(x[i] + 0.5);
                if (t * t == x[i] && mr(t)) mp[x[i]] = t;
            }
        }
    }
    for (int i = 1, p = prime[i]; i <= cntp; p = prime[++i]){
        for (__int128 t = p; t < inf; t *= p){
            auto re = mp.find(t);
            if (re != mp.end()) re->second = p;
        }
    }
    for (auto &it : mp){
        mp2[it.second].push_back(it.first);
    }
    vector<long long> vc;
    for (auto &it : mp2){
        if (it.first && it.second.size() >= 2) vc.push_back(it.first);
    }
    sort(vc.begin(), vc.end(), Cmp());
    int cnt = 0;
    vector<long long> ans;
    for (long long p : vc){
        if (k - cnt < 2) break;
        ans.push_back(mp2[p][0]);
        ans.push_back(mp2[p][1]);
        cnt += 2;
    }
    if (k - cnt == 0){
        ;
    }
    else if (k - cnt == 1 && (int)vc.size() * 2 > k){
        if (mp2[vc[0]].size() >= 3){
            ans.push_back(mp2[vc[0]][2]);
        }
        else {
            bool f = false;
            for (long long x : mp2[0]){
                long long _x = x;
                int cnt = 0;
                for (long long p : vc){
                    if (_x % p == 0){
                        while (_x % p == 0) _x /= p;
                        ++cnt;
                    }
                }
                if (_x != 1) continue;
                if (cnt * 2 + 1 <= k){
                    ans.clear();
                    ans.push_back(x);
                    int _cnt = (k - cnt * 2 - 1) / 2;
                    for (long long p : vc){
                        if (x % p == 0){
                            ans.push_back(mp2[p][0]);
                            ans.push_back(mp2[p][1]);
                        }
                        else if (_cnt){
                            ans.push_back(mp2[p][0]);
                            ans.push_back(mp2[p][1]);
                            --_cnt;
                        }
                    }
                    f = true;
                    break;
                }
            }
            if (!f){
                printf("0\n");
                return 0;
            }
        }
    }
    else {
        for (long long p : vc){
            auto &it = mp2[p];
            int sz = it.size();
            for (int i = 2; i < sz; ++i){
                ans.push_back(it[i]);
                ++cnt;
                if (cnt == k) break;
            }
            if (cnt == k) break;
        }
        if (cnt < k) for (long long x : mp2[0]){
            long long _x = x;
            for (long long p : vc){
                if (_x % p == 0){
                    while (_x % p == 0) _x /= p;
                }
            }
            if (_x != 1) continue;
            ans.push_back(x);
            ++cnt;
            if (cnt == k) break;
        }
        if (cnt < k){
            printf("0\n");
            return 0;
        }
    }
    for (long long it : ans){
        printf("%lld ", it);
    }
    printf("\n");
    return 0;
}