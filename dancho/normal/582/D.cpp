#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MOD = 1000000007;

typedef vector<int> lnum;
const int base = 1000*1000*1000;

// reading:
lnum read_num(char s[]) {
    lnum a;
    for (int i=(int)strlen(s); i>0; i-=9) {
        s[i] = 0;
        a.push_back (atoi (i>=9 ? s+i-9 : s));
    }
    return a;
}


//lnum div short
void div(lnum &a, int b) {
    int carry = 0;
    for (int i=(int)a.size()-1; i>=0; --i) {
        long long cur = a[i] + carry * 1ll * base;
        a[i] = int (cur / b);
        carry = int (cur % b);
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
}

int mod(const lnum &a, int b) {
    long long res = 0;
    long long bmod = 1;
    for (int i = 0; i < (int) a.size(); ++i) {
        res = (res + bmod * a[i]) % b;
        bmod = bmod * base % b;
    }
    return res;
}

int p, al;
char buf[1024];

vector<int> d;

int dp[2][2][4000][4000];

int go(int eq, int ca, int po, int ag) {
    if (dp[eq][ca][po][ag] != -1) {
        // printf("sDP %d %d %d %d -> %d\n",
                // eq, ca, po, ag, dp[eq][ca][po][ag]);
        return dp[eq][ca][po][ag];
    }
    if (po >= (int) d.size()) {
        if (ag >= al && !ca) {
            // printf("ONE %d %d %d %d [%d]\n", eq, ca, po, ag, al);
            return 1;
        }
        return 0;
    }

    long long sl = 0;
    if (eq) {
        // I can put the same as d[po] and remain eq.
        if (!ca) {
            // first, try no carry next step either.
            int x = d[po];
            sl += (long long) (x + 1) * go(eq, 0, po + 1, ag);
            if (sl >= MOD) {
                sl %= MOD;
            }

            // some carry next step
            sl += (long long) x * (go(eq, 1, po + 1, ag + 1));
            if (sl >= MOD) {
                sl %= MOD;
            }
        } else {
            int x = d[po];
            sl += (long long) (p - x - 1) * go(eq, 0, po + 1, ag);
            if (sl >= MOD) {
                sl %= MOD;
            }

            sl += (long long) (p - x) * go(eq, 1, po + 1, ag + 1);
            if (sl >= MOD) {
                sl %= MOD;
            }
        }
        

        // Or I can put < d[po] and get !eq
        if (!ca) {
            long long q = d[po];
            long long num = q * (q + 1) / 2;
            if (num >= MOD) {
                num %= MOD;
            }
            sl += num * go(0, 0, po + 1, ag);
            if (sl >= MOD) {
                sl %= MOD;
            }

            q = d[po] - 1;
            num = q * (q + 1) / 2;
            if (num >= MOD) {
                num %= MOD;
            }
            sl += num * go(0, 1, po + 1, ag + 1);
            if (sl >= MOD) {
                sl %= MOD;
            }
        } else {
            long long q = d[po];
            long long num = q * (q + 1) / 2 + q * (p - q - 1);
            if (num >= MOD) {
                num %= MOD;
            }
            sl += num * go(0, 0, po + 1, ag);
            if (sl >= MOD) {
                sl %= MOD;
            }
            
            num = q * (q + 1) / 2 + q * (p - q);
            if (num >= MOD) {
                num %= MOD;
            }
            sl += num * go(0, 1, po + 1, ag + 1);
            if (sl >= MOD) {
                sl %= MOD;
            }
        }
    } else {
        // Already < d. Put anything.
        if (!ca) {
            long long num = (long long) p * (p + 1) / 2;
            if (num >= MOD) {
                num %= MOD;
            }
            sl += num * go(0, 0, po + 1, ag);
            if (sl >= MOD) {
                sl %= MOD;
            }

            num = (long long) p * (p - 1) / 2;
            if (num >= MOD) {
                num %= MOD;
            }
            sl += num * go(0, 1, po + 1, ag + 1);
            if (sl >= MOD) {
                sl %= MOD;
            }
        } else {
            long long num = (long long) p * p - (long long) p * (p + 1) / 2;
            if (num >= MOD) {
                num %= MOD;
            }
            sl += num * go(0, 0, po + 1, ag);
            if (sl >= MOD) {
                sl %= MOD;
            }

            num = (long long) p * p - (long long) p * (p - 1) / 2;
            if (num >= MOD) {
                num %= MOD;
            }
            sl += num * go(0, 1, po + 1, ag + 1);
            if (sl >= MOD) {
                sl %= MOD;
            }
        }
    }

    // printf("DP %d %d %d %d -> %lld\n", eq, ca, po, ag, sl);
    return (dp[eq][ca][po][ag] = sl);
}

int main() {
    scanf("%d %d", &p, &al);
    scanf("%s", buf);
    lnum a = read_num(buf);
    while (a.size() >= 1 && a.back() != 0) {
        d.push_back(mod(a, p));
        div(a, p);
    }
    reverse(d.begin(), d.end());
    memset(dp, -1, sizeof(dp));
    long long ans = 0;
    ans = go(1, 0, 0, 0);
    printf("%d\n", (int) ans);
    return 0;
}