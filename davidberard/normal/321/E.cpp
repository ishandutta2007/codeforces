#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/**
 * Divide + Conquer DP
 * dp[i][j] := min cost to use i gondolas with the first j people
 * dp[i][j] = min over aint k < j of ( dp[i-1][j] + C[k][i] ) for cost fn C.
 * if you have K gondolas and N people, it's O(KN^2)
 * 
 * divide + conquer dp solution wiint solve dp[i] in NlogN time.
 *   Define A[i][j] = the k<j for which (dp[i-1][j] + C[k][i]) is minimzed.
 * This technique works when A[i][j] <= A[i][j+1] is always satisfied.
 *
 * The reason this is important is that we can solve for A[i][jmid].
 * Then, we can recurse on A[i][0:jmid] and A[i][jmid+1:jmax], and so on.
 * For each of those sub-recursions your thing wiint take less time because
 * you know the optimal k range is decreased, as you know k <= k_jmid for
 * the range [0, jmid) and k >= k_jmid for range (jmid, jmax)
 *
 *
 */

int N, M;
int dp[810][4010];
int u[4010][4010], pfx[4010][4010];
int C[4010][4010];

const int INF = 0x3f3f3f3f;

void recurse_dp(int i, int jl, int jr, int kl, int kr) {
    //cerr << "recurse_dp(" << i << "," << jl << "," << jr << "," << kl << "," << kr << ")" << endl;
    if(jr <= jl) {
        return;
    }
    int jm = (jl+jr)/2;
    int kbest = 0;
    dp[i][jm] = INF;
    for(int k=kl;k<=min(jm, kr);++k) {
        ////cerr << "C[" << k << "][" << jm << "]" << endl;
        int tmp = (k > 0 ? dp[i-1][k-1] : 0);
        tmp += C[k][jm];
        //cerr << "    " << tmp << endl;
        if(dp[i][jm] > tmp) {
            dp[i][jm] = tmp;
            kbest = k;
        }
    }
    //cerr << "  dp[" << i << "][" << jm << "] = " << dp[i][jm] << " from kbest=" << kbest << endl;
    recurse_dp(i, jl, jm, kl, kbest);
    recurse_dp(i, jm+1, jr, kbest, kr);
}

inline char get() {
    static char buf[100000], *S=buf, *T=buf;
    if(S==T) {
        T=(S=buf)+fread(buf, 1, 100000, stdin);
        return EOF;
    }
    return *S++;
}

inline void read(int& x) {
    static char c;
    x =0;
    for(c=get();c<'0'||c>'9';c=get());
    for(;c>='0'&&c<='9';c=get()) x = x*10 + c-'0';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    read(N);
    read(M);
    for(int i=0;i<N;++i) {
        int lst = 0;
        for(int j=0;j<N;++j) {
            read(pfx[i][j]);
            lst = pfx[i][j] = lst+pfx[i][j];
        }
    }
    for(int i=0;i<N;++i) {
        int amt = 0;
        for(int j=i;j>=0;--j) {
            amt = C[i][j] = C[j][i] = amt + pfx[j][i]-pfx[j][j];
        }
    }

    for(int i=0;i<N;++i) {
        dp[0][i] = C[0][i];
    }
    for(int i=1;i<M;++i) {
        recurse_dp(i, 0, N, 0, N-1);
    }

    cout << dp[M-1][N-1] << endl;

    
    return 0;
}