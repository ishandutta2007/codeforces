#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MN = 100010;

int N, C, D;
vector<int> V[MN];
int psum[MN];
ll dp[MN];

int main() {
    scanf("%d %d %d", &N, &C, &D);

    int cnt = 0;
    char la = ' ';
    for(int i = 0; i < N; i++) {
        int t; char c; scanf("%d %c", &t, &c);

        if(!i || la != c) {
            V[cnt++].push_back(t);
            la = c;
        }
        else V[cnt - 1].push_back(t);
    }
    int t; scanf("%d", &t);
    V[cnt].push_back(t);

    for(int i = 0; i < cnt; i++) {
        psum[i] = V[i].size();
        if(i) psum[i] += psum[i - 1];
    }

    for(int i = 0; i < V[0].size(); i++) {
        dp[0] += min(1LL * D, 1LL * C * (V[1][0] - V[0][i]));
    }

    for(int i = 1; i < cnt; i++) {
        ll tmp1 = D;
        for(int j = 1; j < V[i].size(); j++) {
            tmp1 += min(1LL * D, 1LL * C * (V[i + 1][0] - V[i][j]));
        }
        tmp1 += 1LL * psum[i - 1] * D;

        ll tmp2 = 1LL * C * (V[i + 1][0] - V[i][0]);
        for(int j = 1; j < V[i].size(); j++) {
            tmp2 += min(1LL * D, 1LL * C * (V[i + 1][0] - V[i][j]));
        }
        tmp2 += dp[i - 1];

        dp[i] = min(tmp1, tmp2);
    }

    printf("%lld", dp[cnt - 1]);
}