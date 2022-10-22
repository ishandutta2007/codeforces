#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, cur, c[MAXN], w[MAXN];
bool mark[MAXN];
ll ans;
set<pair<int, int>> st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> cur;
	for (int i = 0; i < n; i++)	cin >> c[i];
	for (int i = 0; i < n; i++)	cin >> w[i];
	for (int i = 0; i < n; i++){
		if (c[i] % 100 == 0)	continue;
		cur -= c[i] % 100;
		st.insert({w[i]*(100-c[i]%100), i});

		while (cur < 0){
			auto it = st.begin();
			cur += 100;
			mark[it->S] = 1;
			ans += it->F;
			st.erase(it);
		}
	}

	cout << ans << "\n";
	for (int i = 0; i < n; i++)
		if (mark[i])
			cout << c[i]/100+1 << " " << "0\n";
		else
			cout << c[i]/100 << " " << c[i]%100 << "\n";
	return 0;
}