#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 3e5 + 10;

int n, x[2], c[MAXN], sec[MAXN];

bool ok(int a, int b, int y){
	return a <= 1ll*y*b;
}

bool cmp(int u, int v){return c[u] > c[v];}

void go(int ind){
	int t = 1;
	while (t < n && !ok(x[ind], t, c[sec[t-1]])) t++;
	if (t == n) return;

	int t2 = 1;
	while (t + t2 <= n && !ok(x[ind^1], t2, c[sec[t+t2 - 1]])) t2++;
	if (t + t2 > n) return;

	cout << "Yes\n";
	if (!ind)
		cout << t << " " << t2 << "\n";
	else
		cout << t2 << " " << t << "\n";
	
	if (!ind){
		for (int i = 0; i < t; i++)
			cout << sec[i]+1 << " ";
		cout << "\n";
		for (int i = t; i < t+t2; i++)
			cout << sec[i]+1 << " ";
		cout << "\n";
	}
	else{
		for (int i = t; i < t+t2; i++)
			cout << sec[i]+1 << " ";
		cout << "\n";
		for (int i = 0; i < t; i++)
			cout << sec[i]+1 << " ";
		cout << "\n";
	}
	exit(0);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> x[0] >> x[1];
	for (int i = 0; i < n; i++) cin >> c[i];
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);
	go(0);
	go(1);
	cout << "No\n";
	return 0;
}