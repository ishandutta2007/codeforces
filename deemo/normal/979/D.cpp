#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const int SQ = 120;
const int LOG = 17;
const int XX = 4e7 + 10000;//XXX

int q;
bool mark[MAXN];
vector<int> vec[MAXN];
int tr[XX][2];
int mn[XX];
int sz = SQ;

void insert(int d, int x){
	int cur = d;
	for (int w = LOG-1; ~w; w--){
		int dig = (x>>w&1);
		if (!tr[cur][dig])
			tr[cur][dig] = ++sz;

		cur = tr[cur][dig];
		mn[cur] = min(mn[cur], x);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i < SQ; i++)
		for (int j = i; j < MAXN; j += i)
			vec[j].push_back(i);

	memset(mn, 63, sizeof(mn));
	cin >> q;
	while (q--){
		int type; cin >> type;
		if (type == 1){
			int u; cin >> u;
			if (!mark[u])
				for (int x:vec[u])
					insert(x, u);
			mark[u] = 1;
		}
		else{
			int x, k, s; cin >> x >> k >> s;
			if (x % k){
				cout << "-1\n";
				continue;
			}
			if (k >= SQ){
				int ans = -1;
				for (int j = k; j + x <= s; j += k)
					if (mark[j])
						if (ans == -1 || (ans^x) < (j^x))
							ans = j;
				cout << ans << "\n";
			}
			else{
				int cur = k, ans = -1;
				for (int w = LOG-1; ~w; w--){
					int dig = (x>>w&1);
					if (tr[cur][!dig] && mn[tr[cur][!dig]] + x <= s)
						cur = tr[cur][!dig];
					else if (tr[cur][dig] && mn[tr[cur][dig]] + x <= s)
						cur = tr[cur][dig];
					else {
						cur = -1;
						break;
					}
				}
				if (~cur)
					ans = mn[cur];
				cout << ans << "\n";
			}
		}
	}
	return 0;
}