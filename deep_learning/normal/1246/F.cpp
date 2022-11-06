#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
constexpr int sigma = 26;
using ll = long long;
std::vector<int> vec[35];
int pre[100005], nxt[100005], cur_l[100005], cur_r[100005];
int left[25][100005], right[25][100005], ext[100005], app[35];
ll sum_l[25][100005], sum_r[25][100005], ans;
char str[100005];
int main()
{
	// freopen("1246F.in", "r", stdin);
	scanf("%s", str);
	int n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		vec[str[i] - 'a'].push_back(i);
		cur_l[i] = cur_r[i] = i;
	}
	for (int c = 0; c < sigma; c++)
	{
		for (int i = 0; i < vec[c].size(); i++)
		{
			pre[vec[c][i]] = i ? vec[c][i - 1] : 0;
			nxt[vec[c][i]] = i + 1 == vec[c].size() ? n - 1 : vec[c][i + 1];
		}
	}
	for (int lim = 1; lim <= sigma; lim++)
	{
		std::multiset<int> se_l, se_r;
		for (int l = 0, r = 0, cur = 0; l < n; l++)
		{
			while (r < n && cur + !app[str[r] - 'a'] <= lim)
			{
				se_l.insert(pre[r]);
				se_r.insert(nxt[r]);
				right[0][r] = *--se_r.end();
				cur += !app[str[r++] - 'a']++;
			}
			ext[l] = r;
			left[0][l] = *se_l.begin();
			sum_l[0][l] = l;
			sum_r[0][l] = n - l - 1;
			cur -= !--app[str[l] - 'a'];
			se_l.erase(se_l.find(pre[l]));
			se_r.erase(se_r.find(nxt[l]));
		}
		for (int i = 1; i < 20; i++)
		{
			for (int j = 0; j < n; j++)
			{
				left[i][j] = left[i - 1][left[i - 1][j]];
				right[i][j] = right[i - 1][right[i - 1][j]];
				sum_l[i][j] = sum_l[i - 1][j] + sum_l[i - 1][left[i - 1][j]];
				sum_r[i][j] = sum_r[i - 1][j] + sum_r[i - 1][right[i - 1][j]];
			}
		}
		for (int i = 0; i < n; i++)
		{
			auto jump = [&] (int t)
			{
				ans += sum_r[t][cur_r[i]] + sum_l[t][cur_l[i]];
				cur_l[i] = left[t][cur_l[i]];
				cur_r[i] = right[t][cur_r[i]];
			};
			for (int j = 19; j >= 0; j--)
			{
				if (right[j][cur_r[i]] < ext[left[j][cur_l[i]]])
					jump(j);
			}
			if (cur_r[i] < ext[cur_l[i]])
				jump(0);
		}
	}
	printf("%lld\n", ans);
	return 0;
}