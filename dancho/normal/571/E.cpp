#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std;

long long qpow(long long v, long long st, long long mod) {
    long long res = 1;
    while (st) {
        if (st & 1) {
            res = res * v;
            if (res >= mod) {
                res %= mod;
            }
        }
        v = v * v;
        if (v >= mod) {
            v %= mod;
        }
        st = st / 2;
    }
    return res;
}

const int mod = 1000000007;

int n;
long long a[128], b[128];

// Middle of solution values.
long long l[128][128], t[128][128];

set<int> primes;

void push_primes(long long x) {
    for (long long i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            primes.insert(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        primes.insert(x);
    }
}

inline int maxpow(long long n, long long d) {
    int res = 0;
    while (n % d == 0) {
        n /= d;
        ++res;
    }
    return res;
}

bool trySol(int i, long long k) {
    long long sol[128];
    memset(sol, -1, sizeof(sol));
    for (set<int>::iterator it = primes.begin(); it != primes.end(); ++it) {
        long long p = *it;
        long long at, bt;
        at = maxpow(a[i], p);
        bt = maxpow(b[i], p);
        // printf("WTF %lld %lld\n", at, bt);
        long long tar = at + k * bt;
        // printf("PRT %d %lld\n", *it, tar);
        for (int j = 0; j < n; ++j) {
            long long ap = maxpow(a[j], p);
            long long bp = maxpow(b[j], p);
            // printf("OP %d %lld %lld\n", j, ap, bp);
            // printf("TR %lld\n", tar);
            if (ap > tar) {
                printf("-1\n");
                return 0;
            }
            if (bp == 0) {
                if (ap != tar) {
                    printf("-1\n");
                    return 0;
                }
            } else {
                // printf("RM %lld\n", (tar - ap) % bp);
                if (ap > tar || (tar - ap) % bp != 0) {
                    printf("-1\n");
                    return 0;
                }
                if (sol[j] == -1) {
                    sol[j] = (tar - ap) / bp;
                }
                if (sol[j] != (tar - ap) / bp) {
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }
    printf("%lld\n", (a[i] * qpow(b[i], k, mod)) % mod);
    return 0;
}

long long gcdex(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcdex(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

// Gets the inverse of a modulo m
bool getInv(long long a, long long m, long long *res) {
    long long x, y;
    long long g = gcdex(a, m, x, y);
    // printf("GCDEX %lld %lld -> %lld ; %lld %lld\n", a, m, g, x, y);
    if (g != 1) {
        return 0;
    } else {
        x = (x % m + m) % m;
        *res = x;
        return 1;
    }
}

long long r[128][128];
long long x[128];

bool CRT(int cnt, long long as[], long long bs[], long long *minval, long long *period) {
    map<long long, long long> mp;
    for (int i = 0; i < cnt; ++i) {
        // Hope this factorisation doesn't blow up.
        long long v = bs[i];
        for (long long j = 2; j * j <= v; ++j) {
            if (v % j == 0) {
                // Need just max degree in map.
                long long d = 1;
                while (v % j == 0) {
                    d = d * j;
                    v = v / j;
                }
                vector<map<long long, long long>::iterator> torm;
                bool strong = false;
                for (map<long long, long long>::iterator it = mp.begin(); it != mp.end(); ++it) {
                    // printf("mod %lld %lld\n", v, it->first);
                    if (it->first % d == 0) {
                        // stronger
                        strong = true;
                        if (as[i] % d != it->second % d) {
                            printf("-1\n");
                            return 0;
                        }
                    }
                    else if (d % it->first == 0) {
                        // weaker
                        torm.push_back(it);
                        if (as[i] % it->first != it->second % it->first) {
                            printf("-1\n");
                            return 0;
                        }
                    }
                }
                for (int j = 0; j < (int) torm.size(); ++j) {
                    mp.erase(torm[j]);
                }
                if (!strong) {
                    mp[d] = as[i] % d;
                }
            }
            // printf("FIN\n");
        }
        if (v != 1) {
            long long d = v;
                // COPIED
                bool strong = false;
                vector<map<long long, long long>::iterator> torm;
                for (map<long long, long long>::iterator it = mp.begin(); it != mp.end(); ++it) {
                    // printf("mod %lld %lld\n", v, it->first);
                    if (it->first % d == 0) {
                        // stronger
                        strong = true;
                        if (as[i] % d != it->second % d) {
                            printf("-1\n");
                            return 0;
                        }
                    }
                    else if (d % it->first == 0) {
                        // weaker
                        torm.push_back(it);
                        if (as[i] % it->first != it->second % it->first) {
                            printf("-1\n");
                            return 0;
                        }
                    }
                }
                for (int j = 0; j < (int) torm.size(); ++j) {
                    mp.erase(torm[j]);
                }
                if (!strong) {
                    mp[d] = as[i] % d;
                }
        }
    }
    for (map<long long, long long>::iterator it = mp.begin(); it != mp.end(); ++it) {
        // printf("MP %lld %lld\n", it->first, it->second);
    }

    int i, j;
    i = j = 0;
    long long mx = 0;
    for (map<long long, long long>::iterator it = mp.begin(); it != mp.end(); ++it, ++i) {
        if (it->first > mx) {
            mx = it->first;
        }
        j = 0;
        for (map<long long, long long>::iterator jt = mp.begin(); jt != mp.end(); ++jt, ++j) {
            if (i != j) {
                int res = getInv(it->first, jt->first, &r[i][j]);
                // printf("GET INV OF %lld %lld -> %lld\n", it->first, jt->first, r[i][j]);
                if (!res) {
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }
    if (mx > 32) {
        printf("WTF MAX %lld\n", mx);
    }
    i = 0;
    for (map<long long, long long>::iterator it = mp.begin(); it != mp.end(); ++it, ++i) {
        x[i] = it->second;
        j = 0;
        for (map<long long, long long>::iterator jt = mp.begin(); jt != mp.end() && j < i; ++jt, ++j) {
            // This multiplication might overflow! Can be fixed
            long long ss = x[i] - x[j];
            x[i] = r[j][i] * ss;
            // if (x[i] / ss != r[j][i]) {
            //     printf("OVERFLOW %lld %lld %lld\n", r[j][i], ss, x[i]);
            //     printf("-1\n");
            //     return 0;
            // }
            // x[i] = r[j][i] * (x[i] - x[j]);
            x[i] = x[i] % it->first;
            if (x[i] < 0) x[i] += it->first;
        }
    }
    long long a;
    long long pref = 1;
    a = x[0];
    i = 0;
    for (map<long long, long long>::iterator it = mp.begin(); it != mp.end() && i + 1 < (int) mp.size(); ++it, ++i) {
        pref = pref * it->first;
        a = a + pref * x[i + 1];
    }
    long long lcm = 1;
    for (map<long long, long long>::iterator it = mp.begin(); it != mp.end(); ++it) {
        lcm *= it->first;
    }
    for (int i = 0; i < cnt; ++i) {
        while (a < as[i]) {
            a += lcm;
        }
    }
    *minval = a;
    *period = lcm;
    return 1;
}

bool solve_prime(int p, int id) {
    long long apow[128], bpow[128];
    int unmove = -1;
    int move = -1;
    int samea = -1;
    for (int i = 0; i < n; ++i) {
        apow[i] = maxpow(a[i], p);
        bpow[i] = maxpow(b[i], p);
        // printf("WW %d %d %d\n", i, (int) apow[i], (int) bpow[i]);
        if (bpow[i] > 0) {
            move = i;
        }
        if (bpow[i] == 0) {
            unmove = i;
        }
        if (samea == -1) {
            samea = apow[i];
        }
        if (apow[i] != samea) {
            samea = -2;
        }
    }
    
    // printf("OP %d %d %d\n", unmove, move, samea);
    if (unmove != -1) {
        if (move == -1 && samea == -2) {
            printf("-1\n");
            return 0;
        }
        for (int i = 0; i < n; ++i) {
            if (bpow[i] == 0 && apow[i] != apow[unmove]) {
                printf("-1\n");
                return 0;
            }
            if (bpow[i] != 0) {
                long long k = apow[unmove] - apow[i];
                if (k < 0 || k % bpow[i] != 0) {
                    printf("-1\n");
                    return 0;
                }
                k = k / bpow[i];
                // printf("TRYING SOL %d %d\n", i, (int) k);
                return trySol(i, k);
            }
        }
        // Doesn't depend on that value.
        for (int i = 0; i < n; ++i) {
            l[id][i] = 0;
            t[id][i] = 1;
        }
        return 1;
    }

    // Everything moves. Do CRT
    long long minval, period;
    int ret = CRT(n, apow, bpow, &minval, &period);
    // printf("CRTed %lld %lld\n", minval, period);
    for (int i = 0; i < n; ++i) {
        // printf("DEL BY %d %lld\n", i, bpow[i]);
        if ((minval - apow[i]) % bpow[i] != 0 || minval < apow[i]) {
            if (ret) {
                printf("ERROR DOING CRT %lld %lld %lld\n", minval, apow[i], bpow[i]);
            }
        }
        l[id][i] = (minval - apow[i]) / bpow[i];
        if (period % bpow[i] != 0) {
            if (ret) {
                printf("ERROR2 DOING CRT %lld %lld %lld\n", period, apow[i], bpow[i]);
            }
        }
        t[id][i] = period / bpow[i];
        // if (l[id][i] * bpow[i] == minval - apow[i]) {
        //     if (t[id][i] * bpow[i] == period) {
        //         if ((int) primes.size() == 1) {
        //             printf("%lld\n", (a[i] * qpow(b[i], l[id][i], mod)) % mod);
        //             return 0;
        //         }
        //     }
        // }
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &a[i], &b[i]);
        push_primes(a[i]);
        push_primes(b[i]);
    }


    int realp = 0;
    int la = 0;
    for (set<int>::iterator it = primes.begin(); it != primes.end(); ++it) {
        // printf("SOLVING FOR PRIME %d\n", *it);
        if (!solve_prime(*it, la)) {
            return 0;
        }

        bool fake = true;
        for (int j = 0; j < n; ++j) {
            // printf("SOL %d -> %lld %lld\n", *it, l[la][j], t[la][j]);
            if (l[la][j] != 0 || t[la][j] != 0) {
                fake = false;
            }
        }
        if (!fake) {
            ++realp;
        }
        ++la;
    }
    if ((int) primes.size() == 1) {
        // printf("ONE PRIME\n");
        printf("%lld\n", (a[0] * qpow(b[0], l[0][0], mod)) % mod);
        return 0;
    }
    int numvars = n * realp;
    if (numvars == 0) {
        printf("%lld\n", a[0]);
        return 0;
    }

    for (int p = 0; p < la; ++p) {
        for (int q = p + 1; q < la; ++q) {
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    // l[p][i] + t[p][i] * a = l[q][i] + t[q][i] * b
                    // l[p][j] + t[p][j] * a = l[q][j] + t[q][j] * b
                    long long mb = t[q][i] * t[p][j] - t[q][j] * t[p][i];
                    long long eq = (l[p][i] - l[q][i]) * t[p][j] - (l[p][j] - l[q][j]) * t[p][i];
                    if (mb == 0) {
                        if (eq != 0) {
                            printf("-1\n");
                            return 0;
                        }
                    } else {
                        if (eq % mb != 0) {
                            printf("-1\n");
                            return 0;
                        }
                        long long b = eq / mb;
                        trySol(i, l[q][i] + t[q][i] * b);
                        return 0;
                    }
                }
            }
        }
    }
    // printf("DOTUK?\n");
    // No solutions like that. Just solve one row.
    for (int i = 0; i < n; ++i) {
        bool good = false;
        for (int p = 0; p < la; ++p) {
            if (l[p][i] != 0 || t[p][i] != 0) {
                good = true;
            }
        }
        if (good) {
            // Everything moves. Do CRT
            long long minval, period;
            long long ap[32], bp[32];
            int fi = 0;
            for (int p = 0; p < la; ++p) {
                ap[p] = l[p][i];
                bp[p] = t[p][i];
            }
            int ret = CRT(la, ap, bp, &minval, &period);
            // printf("TRYING SOL %d %lld\n", i, minval);
            trySol(i, minval);
            return 0;
        }
    }

    return 0;
}