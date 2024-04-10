#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, p[MAXN], a[MAXN], b[MAXN];
set<pair<pii, int>> st[3];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> p[i];
	for (int i = 0; i < n; i++)	cin >> a[i], a[i]--, st[a[i]].insert({{p[i], i}, 0});
	for (int i = 0; i < n; i++)	cin >> b[i], b[i]--, st[b[i]].insert({{p[i], i}, 1});

	int q;	cin >> q;
	while (q--){
		int x;	cin >> x, x--;
		if (st[x].empty())
			cout << "-1 ";
		else{
			auto y = *st[x].begin();
			st[x].erase(st[x].begin());
			int id = y.F.S;
			st[a[id]].erase({{p[id], id}, 0});
			st[b[id]].erase({{p[id], id}, 1});
			cout << p[id] << " ";
		}
	}
	cout << "\n";
	return 0;
}