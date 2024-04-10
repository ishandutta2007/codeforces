#include<bits/stdc++.h>

using namespace std;

typedef long double ld;
ld EPS = 1e-12;
const int N = 100043;
int a[N];
ld la[N];
int n;
ld dp[N][11];
int p[N][11];
int p2[N][11];
int d;

int main()
{
    cin >> n >> d;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        la[i] = logl(a[i]);
    }
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= 10; j++)
        {
            dp[i][j] = -1e12;
            p[i][j] = -1;
        }
    dp[0][10] = 0;
    p[0][10] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= 10; j++)
        {
            if(p[i][j] == -1) continue;
            int k = (j == 10 ? 1 : j);
            int nw = j;
            ld v = dp[i][j];
            if(v > dp[i + 1][nw] + EPS)
            {
                dp[i + 1][nw] = v;
                p[i + 1][nw] = 0;
                p2[i + 1][nw] = j;
            }
            nw = (k * (a[i] % 10)) % 10;
            v = dp[i][j] + la[i];
            if(v > dp[i + 1][nw] + EPS)
            {
                dp[i + 1][nw] = v;
                p[i + 1][nw] = 1;
                p2[i + 1][nw] = j;
            }
        }
    if(p[n][d] == -1)
        cout << -1 << endl;
    else
    {
        vector<int> ans;
        int cur = d;
        for(int i = n; i > 0; i--)
        {
            if(p[i][cur])
                ans.push_back(a[i - 1]);
            cur = p2[i][cur];
        }
        printf("%d\n", ans.size());
        for(auto x : ans) printf("%d ", x);
        puts("");
    }
}