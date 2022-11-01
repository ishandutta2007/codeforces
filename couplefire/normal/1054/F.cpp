#include <bits/stdc++.h>
 
using namespace std;

const int M = 1010;

int n;
vector<pair<int, int> > pt;
vector<int> vx, vy;
vector<int> gx[M], gy[M];
vector<tuple<int, int, int> > sh, sv;
int pa[M], pb[M], ln, lm;
vector<int> v[M];
bool used[M], used1[M];
vector<int> dx[M], dy[M];

bool dfs(int p)
{
	used[p] = true;
	for (int i : v[p])
	{
		if (pb[i] == -1 || (!used[pb[i]] && dfs(pb[i])))
		{
			pa[p] = i;
			pb[i] = p;
			return true;
		}
	}
	return false;
}

void dfs_set(int p)
{
	used[p] = true;
	for (int i : v[p])
	{
		used1[i] = true;
		if (pb[i] != -1 && !used[pb[i]])
			dfs_set(pb[i]);
	}
}


void kuhn()
{
	memset(pa, -1, sizeof(pa));
	memset(pb, -1, sizeof(pb));
	for (int i = 0; i < ln; i++)
	{
		memset(used, 0, sizeof(used));
		if (dfs(i)) continue;
	}
	memset(used, 0, sizeof(used));
	memset(used1, 0, sizeof(used1));
	for (int i = 0; i < ln; i++)
		if (pa[i] == -1) 
			dfs_set(i);
	for (int i = 0; i < ln; i++)
		used[i] = (!used[i]);	
}

int main()
{
	ios::sync_with_stdio(0);
        cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		vx.push_back(x);
		vy.push_back(y);
		pt.push_back(make_pair(x, y));
	}
	sort(vx.begin(), vx.end());
	vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
	sort(vy.begin(), vy.end());
	vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
	for (int i = 0; i < n; i++)
	{
		pt[i].first = lower_bound(vx.begin(), vx.end(), pt[i].first) - vx.begin();
		pt[i].second = lower_bound(vy.begin(), vy.end(), pt[i].second) - vy.begin();
	}
	for (int i = 0; i < n; i++)
	{
		gx[pt[i].first].push_back(pt[i].second);
		gy[pt[i].second].push_back(pt[i].first);
	}	
	for (int i = 0; i < n; i++)
		sort(gx[i].begin(), gx[i].end());
	for (int i = 0; i < n; i++)
		sort(gy[i].begin(), gy[i].end());
	for (int y = 0; y < n; y++)
		if ((int)gy[y].size() > 1)
			for (int i = 0; i < (int)gy[y].size() - 1; i++)
				sh.push_back(make_tuple(gy[y][i], gy[y][i + 1], y));
	for (int x = 0; x < n; x++)
		if ((int)gx[x].size() > 1)
			for (int i = 0; i < (int)gx[x].size() - 1; i++)
				sv.push_back(make_tuple(gx[x][i], gx[x][i + 1], x)); 
	sort(sh.begin(), sh.end());
	sort(sv.begin(), sv.end());
	ln = sh.size();
	lm = sv.size();                  
	for (int i = 0; i < ln; i++)
		for (int j = 0; j < lm; j++)
		{               
			if (!(get<0>(sh[i]) < get<2>(sv[j]) && get<2>(sv[j]) < get<1>(sh[i]))) continue;
			if (!(get<0>(sv[j]) < get<2>(sh[i]) && get<2>(sh[i]) < get<1>(sv[j]))) continue;
			v[i].push_back(j);
		}			
	kuhn();
	for (int y = 0; y < n; y++)
		if ((int)gy[y].size() >= 1)
			dy[y].push_back(gy[y][0]);
	for (int x = 0; x < n; x++)
		if ((int)gx[x].size() >= 1)
			dx[x].push_back(gx[x][0]);
	for (int i = 0; i < ln; i++)
		if (used[i])
		{
			dy[get<2>(sh[i])].push_back(get<0>(sh[i]));
			dy[get<2>(sh[i])].push_back(get<1>(sh[i]));
		}
	for (int i = 0; i < lm; i++)
		if (used1[i])
		{
			dx[get<2>(sv[i])].push_back(get<0>(sv[i]));
			dx[get<2>(sv[i])].push_back(get<1>(sv[i]));
		}
	for (int y = 0; y < n; y++)
		if ((int)gy[y].size() >= 1)
			dy[y].push_back(gy[y].back());
	for (int x = 0; x < n; x++)
		if ((int)gx[x].size() >= 1)
			dx[x].push_back(gx[x].back());
	int ans = 0;
	for (int y = 0; y < n; y++)
		ans += (int)dy[y].size();
	ans /= 2;
	cout << ans << "\n";	
	for (int y = 0; y < n; y++)
		for (int i = 0; i < (int)dy[y].size(); i += 2)                                                  
			cout << vx[dy[y][i]] << " " << vy[y] << " " << vx[dy[y][i + 1]] << " " << vy[y] << "\n";
	ans = 0;
	for (int x = 0; x < n; x++)
		ans += (int)dx[x].size();
	ans /= 2;
	cout << ans << "\n";	
	for (int x = 0; x < n; x++)
		for (int i = 0; i < (int)dx[x].size(); i += 2)                                                  
			cout << vx[x] << " " << vy[dx[x][i]] << " " << vx[x] << " " << vy[dx[x][i + 1]] << "\n";
	return 0;
}