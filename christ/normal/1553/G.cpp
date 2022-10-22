#include <bits/stdc++.h>
using namespace std;
const int MN = 3e5 + 5, MM = 1e6 + 5;
int a[MN], sp[MM], par[MM];
int find (int n) {return par[n] == n ? n : par[n] = find(par[n]);}
void merge (int a, int b) {
	par[find(a)] = find(b);
}
int main () {
	int n,q; scanf ("%d %d",&n,&q);
	for (int i = 1; i < MM; i++) par[i] = i;
	for (int i = 2; i < MM; i++) if (!sp[i]) {
		sp[i] = i;
		if ((long long)i * i < MM) {
			for (int j = i * i; j < MM; j += i) if (!sp[j])
				sp[j] = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&a[i]);
		int cur = a[i], lst = -1;
		while (cur > 1) {
			int p = sp[cur];
			if (lst != -1) {
				merge(p,lst);
			}
			lst = p;
			cur /= p;
		}
	}
	vector<bool> poss(q);
	vector<array<int,2>> queries(q);
	map<pair<int, int>, vector<int>> mp;
	for (int id = 0; id < q; id++) {
		auto &[i,j] = queries[id];
		scanf ("%d %d",&i,&j);
		i = find(sp[a[i]]);
		j = find(sp[a[j]]);
		mp[{i,j}].push_back(id);
	}
	for (int i = 1; i <= n; i++) {
		int cur = a[i] + 1;
		vector<int> go = {find(sp[a[i]])};
		while (cur > 1) {
			go.push_back(find(sp[cur]));
			cur /= sp[cur];
		}
		sort(go.begin(),go.end());
		go.erase(unique(go.begin(),go.end()),go.end());
		for (int i : go)
			for (int j : go)
				if (mp.count({i,j})) {
					for (int id : mp[{i,j}]) poss[id] = true;
					mp.erase({i,j});
				}
	}
	for (int id = 0; id < q; id++) {
		auto &[i,j] = queries[id];
		if (find(i) == find(j)) printf ("0\n");
		else if (poss[id]) printf ("1\n");
		else printf ("2\n");
	}
	return 0;
}