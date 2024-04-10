#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 3;

int n, a[MAXN], b[MAXN], sec[MAXN], gec[MAXN], sz, sz2;

bool cmp(int u, int v){
	return make_pair(-b[u], u) > make_pair(-b[v], v);
}

bool cmp2(int u, int v){
	return make_pair(-b[u], u) < make_pair(-b[v], v);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		if (b[i] > 0)
			sec[sz++] = i;
		else
			gec[sz2++] = i;
		b[i] += a[i];
	}
	sort(sec, sec + sz, cmp);
	sort(gec, gec + sz2, cmp2);
	copy(gec, gec + sz2, sec + sz);

	int ans = 0;
	for (int i = 0; i < n; i++){
		int v = sec[i];
		int x = 0;
		for (int j = 0; j < n; j++)
			if (a[j] > a[v] || (a[j] == a[v] && j < v))	x++;

		a[v] = b[v];
		int y = 0;
		for (int j = 0; j < n; j++)
			if (a[j] > a[v] || (a[j] == a[v] && j < v))	y++;
		ans += abs(x - y);
	}
	cout << ans << endl;
	return 0;
}