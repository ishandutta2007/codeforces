// just let me have a try!

#include<bits/stdc++.h>
std::vector<int> f,s;
std::vector<std::vector<int>> To;
long long ans;
void dfs(int u,int time)
{
    ans += 1ll * time * s[u];
    if(To[u].size() == 0)
    {
        f[u] = s[u];
        return;
    }
    int Mod = time % To[u].size();
    int cnt = time / To[u].size();
    std::priority_queue<int> q;
    for(int v : To[u])
    {
        dfs(v, cnt);
        q.push(f[v]);
    }
    while(Mod--)
    {
        ans += q.top();
        q.pop();
    }
    f[u] = s[u] + q.top();
}
void solve()
{
	int n,k;
    std::cin >> n >> k;
    To.clear();To.resize(n + 1);
    for(int i = 2; i <= n; i++)
    {
        int fa;
        std::cin >> fa;
        To[fa].push_back(i);
    }
    s.clear();s.resize(n + 1);
    for(int i = 1; i <= n; i++)
        std::cin >> s[i];
    f.clear();f.resize(n + 1);
    ans = 0;
    dfs(1, k);
    std::cout << ans << '\n';
}
int main()
{
	int T;
	std::cin >> T;
	while(T--)
		solve();
	return 0;
}