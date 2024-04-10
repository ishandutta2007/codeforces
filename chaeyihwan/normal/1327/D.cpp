#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int p[200002], c[200002], v[200002];
int col[200002], n;

int divide(int now, int j, int cnt)
{
    for(int k=0;k<j;k++)
    {
        col[k] = c[now];
        now = p[now];
    }
    for(int k=j;k<cnt;k++)
    {
        if(col[k%j] != c[now]) col[k%j] = 0;
        now = p[now];
    }
    for(int k=0;k<j;k++) if(col[k]) return 1;
    return 0;
}

int func(int i)
{
    int cnt = 1, j = i;
    while(p[j] != i)
    {
        v[j] = true;
        j = p[j];
        cnt++;
    }
    v[j] = true;

    int ret = cnt;
    for(j=1;j*j<=cnt;j++)
    {
        if(cnt%j) continue;
        if(divide(i, j, cnt)) ret = min(ret, j);
        if(divide(i, cnt/j, cnt)) ret = min(ret, cnt/j);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1;i<=n;i++) cin >> p[i];
        for(int i=1;i<=n;i++) cin >> c[i];
        for(int i=1;i<=n;i++) v[i] = 0;

        int ans = n;
        for(int i=1;i<=n;i++)
        {
            if(v[i]) continue;
            ans = min(ans, func(i));
        }

        cout << ans << "\n";
    }
}