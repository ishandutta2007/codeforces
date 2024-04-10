#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int INF = 1e9;

int n, m;
int a[MAXN], b[MAXN];
string s, t;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	n = s.size();
	m = t.size();

	int cur = 0;
	for (int j = 0; j < m; j++){
		while (cur < n && s[cur] != t[j])	cur++;
		if (cur == n) a[j+1] = INF;
		else a[j+1] = ++cur;
	}

	cur = n-1;
	b[m] = n;
	for (int j = m-1; ~j; j--){
		while (cur >= 0 && s[cur] != t[j])	cur--;
		if (cur < 0) b[j] = -INF;
		else b[j] = cur--;
	}

	pair<int, int> mn(INF, -1);
	cur = 0;
	for (int i = 0; i <= m; i++){
		cur = max(cur, i);
		if (a[i] == INF) break;

		while (b[cur] < a[i]) cur++;
		mn = min(mn, {cur-i, i});
	}
	
	if (mn.first >= m)
		cout << "-\n";
	else{
		for (int i = 0; i < mn.second; i++) cout << t[i];
		for (int i = mn.second+mn.first; i < m; i++)	cout << t[i];
		cout << "\n";
	}
	return 0;
}