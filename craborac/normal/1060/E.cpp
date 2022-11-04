#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long long cnt[(int)2e5 + 10][2], sum[(int)2e5 + 10][2];
int used[(int)2e5 + 10];
long long ans, ans2;
vector<int> mas[(int)2e5 + 10];

void dfs(int v)
{
    used[v] = 1;
    cnt[v][0] = 1;
    cnt[v][1] = 0;
    sum[v][0] = 0;
    sum[v][1] = 1;
    for (int u: mas[v])
    {
        if (used[u] == 0)
        {
            dfs(u);
            cnt[v][0] += cnt[u][1];
            cnt[v][1] += cnt[u][0];
            sum[v][0] += sum[v][1] + cnt[u][1];
            sum[v][1] += sum[u][0] + cnt[u][0];
        }
    }
}

void dfs2(int v, long long cnt0 = 0, long long cnt1 = 0, long long sum0 = 0, long long sum1 = 0)
{
    cnt[v][0] += cnt0;
    cnt[v][1] += cnt1;
    sum[v][0] += sum0;
    sum[v][1] += sum1;
    used[v] = 0;
    for (int u: mas[v])
    {
        if (used[u] == 1)
        {
            cnt[v][0] -= cnt[u][1];
            cnt[v][1] -= cnt[u][0];
            sum[v][0] -= sum[v][1] + cnt[u][1];
            sum[v][1] -= sum[u][0] + cnt[u][0];
            ans += cnt[u][0] * cnt[v][0];
            ans2 += cnt[u][0] * cnt[v][1] + cnt[u][1] * cnt[v][0];
            dfs2(u, cnt[v][1], cnt[v][0], sum[v][1] + cnt[v][1], sum[v][0] + cnt[v][0]);
            cnt[v][0] += cnt[u][1];
            cnt[v][1] += cnt[u][0];
            sum[v][0] += sum[v][1] + cnt[u][1];
            sum[v][1] += sum[u][0] + cnt[u][0];
        }
    }
    cnt[v][0] -= cnt0;
    cnt[v][1] -= cnt1;
    sum[v][0] -= sum0;
    sum[v][1] -= sum1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        mas[a].push_back(b);
        mas[b].push_back(a);
    }
    ans = 0;
    ans2 = 0;
    dfs(0);
    dfs2(0);
    cout << ans + ans2 / 2 << endl;
	return 0;
}