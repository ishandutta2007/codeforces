#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
string A, B, C;
void solve()
{
    cin >> n >> m >> A >> B;
    C = A.substr(n - m);
    if(C == B) printf("YES\n");
    else {
        bool hv = false;
        rep(i, n - m) if(A[i] != A[n - m]) hv = true;
        C[0] ^= 1;
        if(hv && C == B) printf("YES\n");
        else printf("NO\n");
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}