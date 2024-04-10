#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
char S[100050];
char T[100050];
bool chk[100050];
vector <int> chk_pos;

ll dp[100050];
ll dp_sum[100050];
ll dp_sum_sum[100050];

int bin_search(int x) {
    int st = 0, en = chk_pos.size()-1, mi, ans = -1;
    while(st <= en) {
        mi = (st+en)/2;
        if(chk_pos[mi] <= x) {
            ans = chk_pos[mi];
            st = mi+1;
        }
        else en = mi-1;
    }
    return ans;
}

int main() {
    int L, L_S, i;
    scanf("%s %s", &S[1], &T[1]);
    for(L_S = 1; S[L_S] != 0; L_S++);
    // hashing check
    ll h1 = 0, h2 = 0, h3 = 0, pow_31 = 1, pow_37 = 1, pow_43 = 1;
    for(L = 1; T[L] != 0; L++) {
        h1 = (31*h1+T[L])%MOD;
        h2 = (37*h2+T[L])%MOD;
        h3 = (43*h3+T[L])%MOD;
    }
    if(L_S < L) {
        printf("0");
        return 0;
    }
    L--;
    L_S--;
    for(i = 1; i < L; i++) {
        pow_31 = (pow_31*31)%MOD;
        pow_37 = (pow_37*37)%MOD;
        pow_43 = (pow_43*43)%MOD;
    }

    ll t1 = 0, t2 = 0, t3 = 0;
    for(i = 1; i <= L; i++) {
        t1 = (31*t1+S[i])%MOD;
        t2 = (37*t2+S[i])%MOD;
        t3 = (43*t3+S[i])%MOD;
    }
    if(h1 == t1 && h2 == t2 && h3 == t3) {
        chk[1] = true;
        chk_pos.push_back(1);
    }
    for(i = 2; i <= L_S-L+1; i++) {
        t1 -= (pow_31*S[i-1])%MOD;
        if(t1 < 0) t1 += MOD;
        t1 = (31*t1+S[i+L-1])%MOD;
        t2 -= (pow_37*S[i-1])%MOD;
        if(t2 < 0) t2 += MOD;
        t2 = (37*t2+S[i+L-1])%MOD;
        t3 -= (pow_43*S[i-1])%MOD;
        if(t3 < 0) t3 += MOD;
        t3 = (43*t3+S[i+L-1])%MOD;
        if(t1 == h1 && t2 == h2 && t3 == h3) {
            chk[i] = true;
            chk_pos.push_back(i);
        }
    }
    if(chk_pos.empty()) {
        printf("0");
        return 0;
    }
    // Get ANS (dp)
    dp[0] = 1, dp_sum[0] = 1, dp_sum_sum[0] = 1;
    for(i = 1; i < L; i++) {
        dp[i] = 0;
        dp_sum[i] = 1;
        dp_sum_sum[i] = i+1;
    }
    for(i = L; i <= L_S; i++) {
        int tmp = bin_search(i-L+1);
        if(tmp == -1) {
            dp[i] = 0;
            dp_sum[i] = dp_sum[i-1];
            dp_sum_sum[i] = dp_sum_sum[i-1]+dp_sum[i];
            dp_sum_sum[i] %= MOD;
            continue;
        }
        dp[i] = dp_sum_sum[tmp-1];
        dp_sum[i] = dp_sum[i-1]+dp[i];
        dp_sum[i] %= MOD;
        dp_sum_sum[i] = dp_sum_sum[i-1]+dp_sum[i];
        dp_sum_sum[i] %= MOD;
    }

    printf("%lld", (dp_sum[L_S]+MOD-1)%MOD);
    return 0;
}