#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 500005;

set<int> G[kMaxN], Heights[kMaxN];
int Seen[kMaxN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	if(n == 2) {
		cout << 1 << endl;
		return 0;
	}
	
	for(int i = 2; i <= n; ++i) {
		int a, b;
		cin >> a >> b;
		G[a].insert(b);
		G[b].insert(a);
	}

	deque<int> Q;
	for(int i = 1; i <= n; ++i) {
		if(G[i].size() <= 1) {
			Seen[i] = true;
			Heights[i].insert(0);
			Q.push_back(i);
		}
	}

	int last = -1, steps = 0;
	while(Q.size()) {
		if(steps == n - 1)
			break;
		++steps;

		int top = Q.front();
		Q.pop_front();
		Seen[top] = 2;


		assert(Heights[top].size() == 1);
		
		int h = *begin(Heights[top]);
		++h;

		/*cerr << "Top: " << top << endl;
		cerr << "H: " << h - 1 << endl;
		cerr << endl;*/

		if(!G[top].empty()) {
			assert(G[top].size() == 1);

			auto vec = *begin(G[top]);
			G[vec].erase(top);
			Heights[vec].insert(h);

			// cerr << vec << ": " << G[vec].size() << " " << Heights[vec].size() << " " << Seen[vec] << endl;
			if(G[vec].size() <= 1 && Heights[vec].size() == 1 && !Seen[vec]) {
				Seen[vec] = 1;
				Q.push_back(vec);
				// cerr << "Pushed: " << vec << endl;
			}
		}
	}

	if(steps == n - 1	) {
		for(last = 1; Seen[last] == 2; ++last);
		// cerr << "Last: " << last << endl;
		
		if(Heights[last].size() <= 2) {
			int ans = 0;
			for(auto h : Heights[last])
				ans += h;
			while(ans % 2 == 0) ans /= 2;
			cout << ans << endl;
		} else {
			cout << -1 << endl;
		}
	} else {
		cout << -1 << endl;
	}


	return 0;
}