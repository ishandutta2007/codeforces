#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, p[MAXN];
string s, t;
bool del[MAXN];

bool ok(int mid){
	memset(del, 0, sizeof(del));
	for (int i = 0; i < mid; i++)
		del[p[i]] = 1;

	int cur = 0;
	for (int i = 0; i < t.size(); i++){
		while (cur < n && (del[cur] || s[cur] != t[i])) cur++;
		if (cur == n) return false;
		cur++;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t; n = s.size();
	for (int i = 0; i < n; i++)	cin >> p[i], p[i]--;

	int lo = 0, hi = n;
	while (hi-lo>1){
		int mid = hi+lo>>1;
		if (ok(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << "\n";
	return 0;
}