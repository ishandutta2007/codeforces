#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> c[102];
int l[102], r[102], U[102];
int idx[102];
int n, k;
void choose(int s, int e)
{
    int now = 0;
    for(int t=1;t<=e-s+1;t++)
    {
        int opt = 100000, w = -1, x = 0;
        for(int i=s;i<=e;i++)
        {
            if(U[i]) continue;
            int cnt = 0;
            for(int j=0;j<k;j++)
            {
                if(c[i][j] > now) cnt++;
                if(cnt == 2)
                {
                    if(opt > c[i][j])
                    {
                        opt = c[i][j];
                        x = j;
                        w = i;
                    }
                    break;
                }
            }
        }
        U[w] = true;
        now = opt;
        l[w] = c[w][x-1];
        r[w] = c[w][x];
    }
}

void solve()
{
    cin >> n >> k;
    for(int i=1;i<=n*k;i++)
    {
        int C;
        cin >> C;
        c[C].push_back(i);
    }
    for(int i=1;i<=n;i++) U[i] = 0;

    for(int i=1;i<=n;i=i+k-1)
    {
        choose(i, min(i+k-2, n));
    }

    for(int i=1;i<=n;i++) cout << l[i] << " " << r[i] << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; t = 1;
    while(t--) solve();
}