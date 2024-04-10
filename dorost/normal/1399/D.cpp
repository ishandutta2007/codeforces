/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int s[N], an[N];

int32_t main(){
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		string t;
		cin >> t;
		set <int> st[2];
		for (int i = 0; i < n; i++){
			st[int(t[i] - '0')].insert(i);
		}
		for (int i = 0; i < n; i++)
			s[i] = (t[i] - '0');
		int ch, ans = 0;
		while (true) {
			int i;
			if (st[0].size() && (st[1].size() == 0 || *st[0].begin() < *st[1].begin())) {
				ch = 0;
				i = *st[0].begin();
				an[i] = ans + 1;
				st[ch].erase(i);
			}else{
				ch = 1;
				i = *st[1].begin();
				an[i] = ans + 1;
				st[ch].erase(i);
			}
			while (st[1 - ch].size()) {
				auto it = st[1 - ch].lower_bound(i);
				if (it == st[1 - ch].end())
					break;
				int x = *it;
				an[x] = ans + 1;
				st[1 - ch].erase(x);
				i = x;
				ch = 1 - ch;
			}
			if (st[0].size() + st[1].size() == 0)
				break;
			ans = (ans * 2 / 2) + 1;
		}
		printf("%d", ans + 1);
		printf("\n");
		for (int i = 0; i < n; i++)
			printf("%d ", an[i]);
		printf("\n");
	}
}