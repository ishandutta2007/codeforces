#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, v, t[MAXN], val[MAXN], sec[MAXN], gec[MAXN], sz, sz2, p1[MAXN], p2[MAXN];

bool cmp(int u, int v){return val[u] > val[v];}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> v;
	for (int i = 0; i < n; i++){
		cin >> t[i] >> val[i];
		if (t[i]-1)
			gec[sz2++] = i;
		else
			sec[sz++] = i;
	}
	sort(sec, sec + sz, cmp);
	sort(gec, gec + sz2, cmp);

	for (int i = 0; i < sz; i++)
		p1[i + 1] = p1[i] + val[sec[i]];
	for (int i = 0; i < sz2; i++)
		p2[i + 1] = p2[i] + val[gec[i]];

	int mx = 0;
	for (int i = 0; i <= sz && i <= v; i++)
		mx = max(mx, p1[i] + p2[min(sz2, v-i>>1)]);
	cout << mx << "\n";
	for (int i = 0; i <= sz && i <= v; i++)
		if (mx == p1[i] + p2[min(sz2, v-i>>1)]){
			for (int j = 0; j < i; j++)
				cout << sec[j] + 1 << " ";
			for (int j = 0; j < min(sz2, v-i>>1); j++)
				cout << gec[j] + 1 << " ";
			cout << "\n";
			break;
		}
	return 0;
}