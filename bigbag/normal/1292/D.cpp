#include <bits/stdc++.h>

using namespace std;

const int max_n = 5003;
const long long inf = 1000111222000111222LL;

int used[max_n];
vector<int> pw;

void get_all_primes() {
    for (int i = 2; i < max_n; ++i) {
        if (used[i] == 0) {
            pw.push_back(i);
            for (int j = i * i; j < max_n; j += i) {
                used[j] = 1;
            }
        }
    }
}

const int max_pw = 700;

int n, cnt[max_n], first[max_n], neq[max_n];
int a[max_n][max_pw], sum[max_n][max_pw];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_primes();
    scanf("%d", &n);
    while (n--) {
        int x;
        scanf("%d", &x);
        x = max(x, 1);
        ++cnt[x];
    }
    for (int i = 0; i < max_n; ++i) {
        for (int j = 0; j < pw.size(); ++j) {
            int cur = i / pw[j];
            while (cur) {
                a[i][j] += cur;
                cur /= pw[j];
            }
            sum[i][j] = a[i][j];
            if (j) {
                sum[i][j] += sum[i][j - 1];
            }
        }
    }
    long long ans = inf, OP = 0;
    for (int i = 1; i < max_n; ++i) {
        if (i == 1) {
            first[i] = pw.size() - 1;
        } else {
            for (int j = pw.size() - 1; j >= 0; --j) {
                if (a[i][j] != a[i - 1][j]) {
                    first[i] = j;
                    break;
                }
            }
        }
    }
    for (int i = 1; i < max_n; ++i) {
        long long add = 0, S = 0;
        int cs = 0;
        int pos = first[i];
        for (int j = i; j > 1; --j) {
            pos = max(pos, first[j]);
            neq[j - 1] = pos;
        }
        pos = 0;
        for (int j = i + 1; j < max_n; ++j) {
            pos = max(pos, first[j]);
            neq[j] = pos;
        }
        pos = max_n - 1;
        int lpos = 1;
        for (int j = first[i]; j >= 0; --j) {
            while (lpos < i && neq[lpos] > j) {
                long long x = abs(a[i][neq[lpos]] - a[lpos][neq[lpos]]);
                if (neq[lpos]) {
                    x += sum[lpos][neq[lpos] - 1];
                    S += 1LL * cnt[lpos] * sum[i][neq[lpos] - 1];
                    cs += cnt[lpos];
                }
                add += x * cnt[lpos];
                ++lpos;
            }
            while (pos > i && neq[pos] > j) {
                long long x = abs(a[i][neq[pos]] - a[pos][neq[pos]]);
                if (neq[pos]) {
                    x += sum[pos][neq[pos] - 1];
                    S += 1LL * cnt[pos] * sum[i][neq[pos] - 1];
                    cs += cnt[pos];
                }
                add += x * cnt[pos];
                --pos;
            }
            long long res = add;
            int tot = cs;
            for (int k = lpos; k <= pos; ++k) {
                tot += cnt[k];
            }
            int need = tot / 2;
            int val = 0;
            tot = cs;
            if (tot > need) {
                val = 0;
            } else {
                for (int k = lpos; k <= pos; ++k) {
                    ++OP;
                    if (tot + cnt[k] > need) {
                        val = a[k][j];
                        break;
                    }
                    tot += cnt[k];
                }
            }
            for (int k = lpos; k <= pos; ++k) {
                long long x = abs(val - a[k][j]);
                if (j) {
                    x += sum[k][j - 1];
                }
                res += x * cnt[k];
            }
            res += S - cs * sum[i][j] + cs * val;
            ans = min(ans, res);
        }
    }
    printf("%I64d\n", ans);
    return 0;
}