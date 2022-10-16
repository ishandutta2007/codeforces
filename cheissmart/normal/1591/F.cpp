#include <bits/stdc++.h>
#define IO_OP ios::sync_with_stdio(0), cin.tie(0)
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7, M = 998244353;

void add(int& a, int b) {
    a += b;
    if(a >= M)
        a -= M;
}

int mul(int a, int b) {
    return 1LL * a * b % M;
}

int a[N], dp[N];

signed main()
{
    IO_OP;

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    dp[0] = (n & 1 ? M-1 : 1);
    int sum = 0;
    
    V<pi> stk;

    for(int i = 1; i <= n; i++) {
        pi tt = {a[i], dp[i - 1]};
        while(stk.size() && stk.back().F > tt.F) {
            pi bk = stk.back(); stk.pop_back();
            add(sum, M - mul(bk.F, bk.S));
            add(tt.S, bk.S);
        }
        stk.PB(tt);
        add(sum, mul(tt.F, tt.S));
        dp[i] = sum ? M - sum : 0;
    }
    cout << dp[n] << '\n';

}