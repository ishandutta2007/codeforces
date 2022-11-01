#include <bits/stdc++.h>
using namespace std;
struct Team {
	int id, a, d;
	Team(int id = 0, int a = 0, int d = 0) : id(id), a(a), d(d) {}
};
bool operator < (const Team &a, const Team &b) {
	if (a.a != b.a) return a.a > b.a;
	return a.id < b.id;
}
const int N = 105;
Team team[N];
int nowrank[N], newrank[N], id[N];
bool done[N];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		int a, d;
		scanf("%d%d", &a, &d);
		team[i] = Team(i, a, d);
	}
	for (int i = 1; i <= n; ++ i) id[i] = i;
	sort(id + 1, id + 1 + n, [&] (int i, int j) {
		if (team[i].a != team[j].a) return team[i].a > team[j].a;
		return team[i].id < team[j].id;
	});
	for (int i = 1; i <= n; ++ i) nowrank[id[i]] = i;
	for (int i = 1; i <= n; ++ i) id[i] = i;
	sort(id + 1, id + 1 + n, [&] (int i, int j) {
		if (team[i].a + team[i].d != team[j].a + team[j].d) return team[i].a + team[i].d > team[j].a + team[j].d;
		return team[i].id < team[j].id;
	});
	for (int i = 1; i <= n; ++ i) newrank[id[i]] = i;
	int ans = 0;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			if (team[i].d >= 0 && team[j].d < 0 && (nowrank[i] < nowrank[j]) != (newrank[i] < newrank[j])) ans ++;
		}
	}
	vector<Team> al[2];
	for (int i = 1; i <= n; ++ i) if (team[i].d >= 0) {
		al[0].push_back(team[i]);
	}
	else {
		team[i].d = -team[i].d;
		team[i].id = -team[i].id;
		team[i].a = -team[i].a;
		al[1].push_back(team[i]);
	}
	for (auto &a : al) {
		sort(a.begin(), a.end());
		//printf("-----\n");
		int n = (int) a.size();
		bool flag = 1;
		memset(done, 0, sizeof(done));
		while (flag) {
			flag = 0;
			for (int i = n - 1; i >= 0; -- i) if (!done[abs(a[i].id)]) {
				flag = 1;
				int j = i;
				done[abs(a[i].id)] = 1;
				a[i].a += a[i].d;
				while (j != 0 && a[j] < a[j - 1]) {
					swap(a[j], a[j - 1]);
					ans ++;
					-- j;
				}
				break;
			}
			//for (int i = 0; i < n; ++ i) printf("%d ", a[i]); puts("");
		}
	}
	printf("%d\n", ans);
}