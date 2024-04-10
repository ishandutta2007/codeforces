#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 30;

int n;
int a[MAXN];
short mark[MAXN];
ll ans[MAXN];
int sec[MAXN], sz = 0;

ll	dfs(int v){
	if (v < 1 || v > n)	return	0;
	if (mark[v]){
		if (mark[v] == 1)	return	-1;
		return	ans[v];
	}

	mark[v] = 1;
	int cur = v;
	ll ret = 0;
	ret += a[cur], cur += a[cur];
	if (cur > n || cur < 1){
		ans[v] = ret;
		sec[sz++] = v;
		return	ret;
	}
	
	ret += a[cur], cur -= a[cur];
	ll	temp = dfs(cur);
	if (temp == -1)
		ans[v] = -1;
	else
		ans[v] = temp + ret;
	
	sec[sz++] = v;
	return	ans[v];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 2; i <= n; i++)	cin >> a[i];
	mark[1] = 1;

	for (int i = 2; i <= n; i++){
		if (mark[i] == 0)	dfs(i);
		for (int j = 0; j < sz; j++)
			mark[sec[j]] = 2;
		sz = 0;
	}

	for (int i = 1; i < n; i++){
		int cur = 1;
		ll ret = 0;
		cur += i, ret += i;
		ret += a[cur], cur -= a[cur];

		if (cur == 1)
			cout << -1 << "\n";
		else if (cur < 1)
			cout << ret << "\n";
		else{
			if (ans[cur] == -1)
				cout << -1 << "\n";
			else
				cout << ret + ans[cur] << "\n";
		}
	}
	return 0;
}