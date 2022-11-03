#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int max_len = 20;
const int max_n = 16;
const int max_mask = (1 << max_n);

char names[max_n][max_len];
vector<vector<int> > g;
int n, m;

int get_id_from_name(char* name)
{
	for (int i = 0; i < n; ++i)
		if (strcmp(name, names[i]) == 0) 
			return i;
}

int bit(int mask, int i)
{
	return (mask >> i) & 1;
}

bool check(int mask) 
{
	for (int i = 0; i < n; ++i)
		if (bit(mask, i)) 
			for (int j = 0; j < (int) g[i].size(); ++j) 
				if (bit(mask, g[i][j])) 
					return false;
	return true;
}

int cnt_bits(int mask)
{
	 int ans = 0;
	 for (int i = 0; i < n; ++i)
		 ans += bit(mask, i);
	 return ans;
}

int main()
 {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (scanf("%d%d\n", &n, &m) != EOF) {
		for (int i = 0; i < n; ++i)
			scanf("%s\n", names[i]);
		g.clear();
		g.resize(n);
		for (int i = 0; i < m; ++i) {
			char name1[max_len];
			char name2[max_len];

			scanf("%s%s\n", name1, name2);

			int id1 = get_id_from_name(name1);
			int id2 = get_id_from_name(name2);

			g[id1].push_back(id2);
			g[id2].push_back(id1);
		}
		int ans_val = 0, 
			ans_mask = 0;
		for (int mask = 0; mask < (1 << n); ++mask) 
			if (check(mask)) {
				int val = cnt_bits(mask);
				if (val > ans_val) {
					ans_val = val;
					ans_mask = mask;
				}
			}
		printf("%d\n", ans_val);
		int c = 0;
		for (int i = 0; i < n; ++i)
			if (bit(ans_mask, i)) {
				strcpy(names[c++], names[i]);
			}
		for (int i = 0; i < c; ++i)
			for (int j = i + 1; j < c; ++j) {
				if (strcmp(names[i], names[j]) > 0) {
					for (int t = 0; t < max_len; ++t)
						swap(names[i][t], names[j][t]);
				}
			}
		for (int i = 0; i < c; ++i)
			printf("%s\n", names[i]);
	}

	return 0;
}