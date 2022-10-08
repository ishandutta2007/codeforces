/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--) {
		int n;
		cin >> n;
		struct Human {
			int w, h, id;
			bool operator < (Human it) const {
				return w < it.w;
			}
		};
		vector<Human> a;
		forn(i, n) {
			int w, h;
			cin >> w >> h;
			a.push_back({w, h, i});
			a.push_back({h, w, i});
		}
		sort(all(a));

		vector<int> id(n, -1);
		int j = 0;
		Human min_h;
		forn(i, a.size()) {
			for (; a[j].w < a[i].w; j++) 
				if (j == 0 || min_h.h > a[j].h)
					min_h = a[j];
			if (j && min_h.h < a[i].h)
				id[a[i].id] = min_h.id + 1;
		}

		forn(i, n)
			cout << id[i] << " ";
		cout << "\n";
	}
}