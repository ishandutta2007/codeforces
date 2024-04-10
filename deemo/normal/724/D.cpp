#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m, fen[MAXN];
string s, ans;

int add(int v, int val){
	for (v++; v < MAXN; v += v&-v)
		fen[v] += val;
}

int get(int v){
	int ret = 0;
	for (; v; v-=v&-v)
		ret += fen[v];
	return ret;
}

bool check(int i){
	for (int j = 0; j < n; j++)
		if (s[j] - 'a' == i) add(j, 1);
	bool fail = 0;
	for (int j = 0; !fail && j + m <= n; j++)
		if (get(j + m) - get(j) == 0)	fail = 1;
	if (fail)	return false;
	
	for (int j = 0; j < n; j++)
		if (s[j] - 'a' == i) add(j, -1);

	int lst = -1, pc = -1;
	for (int j = 0; j + 1 < m; j++)	
		if (s[j] - 'a' == i)	lst = j;
	
	for (int j = 0; j + m <= n; j++){
		if (s[j + m - 1] - 'a' <= i)	lst = j + m - 1;
	
		if (get(j + m) - get(j) == 0 && pc < j){
			pc = lst;
			ans += s[pc];
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> s; n = s.size();
	for (int i = 0; i < 26; i++){
		if (check(i))	break;
		for (int j = 0; j < n; j++)
			if (s[j] - 'a' == i)
				ans += s[j];
	}
	cout << ans << "\n";
	return 0;
}