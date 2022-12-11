#include <cstdio>
#include <vector>
typedef long long int64;
static const int MAXDG = 19;
static const int LCM = 2520;

int64 l, r;
// f[length in decimal representation][mask of digit occurence][remainder of 2520]
int64 f[MAXDG][1 << 8][LCM] = {{{ 0 }}};
int pow10[MAXDG];
std::vector<int> div[1 << 8];

inline int digit_mask(int x) { return (x <= 1 ? 0 : (1 << (x - 2))); }

void preprocess()
{
    f[0][0][0] = 1;
    for (int i = 0; i <= 9; ++i) f[1][digit_mask(i)][i]++;
    for (int dg = 1; dg < MAXDG - 1; ++dg) {
        for (int mask = 0; mask < (1 << 8); ++mask)
            for (int lcm = 0; lcm < LCM; ++lcm)
                for (int nxt = 0; nxt <= 9; ++nxt) {
                    f[dg + 1][mask | digit_mask(nxt)][(lcm * 10 + nxt) % LCM] += f[dg][mask][lcm];
                }
    }
    pow10[0] = 1; for (int i = 1; i < MAXDG; ++i) pow10[i] = (pow10[i - 1] * 10) % LCM;
    for (int mask = 0; mask < (1 << 8); ++mask)
        for (int rmd = 0; rmd < LCM; ++rmd) {
            bool valid = true;
            for (int i = 0; i < 8; ++i)
                if ((mask & (1 << i)) && rmd % (i + 2) != 0) { valid = false; break; }
            if (valid) div[mask].push_back(rmd);
        }
}
int64 calc(int64 rg)
{
    if (rg == 0) return 0;
    static int dgs[MAXDG], tot_dg;
    tot_dg = 0; for (int64 x = rg; x > 0; x /= 10, ++tot_dg) dgs[tot_dg] = x % 10;
    int64 ans = 0;
    int pfx_lcm = 0, pfx_mask = 0;
    for (int len = tot_dg - 1; len >= 0; --len) {
        for (int y = 0; y < dgs[len]; ++y) {
            int cur_pfx_lcm = (pfx_lcm + y * pow10[len]) % LCM;
            for (int mask = 0; mask < (1 << 8); ++mask) {
                int rmask = pfx_mask | mask | digit_mask(y);
                for (std::vector<int>::iterator i = div[rmask].begin(); i != div[rmask].end(); ++i)
                    ans += f[len][mask][(*i - cur_pfx_lcm + LCM) % LCM];
            }
        }
        pfx_lcm = (pfx_lcm + dgs[len] * pow10[len]) % LCM;
        pfx_mask |= digit_mask(dgs[len]);
    }
    return ans;
}

int main()
{
    preprocess();
    int T; scanf("%d", &T);
    do {
        scanf("%I64d%I64d", &l, &r);
        printf("%I64d\n", calc(r + 1) - calc(l));
    } while (--T);
    return 0;
}