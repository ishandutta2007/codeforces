#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 100;

int n, a[MAXN], sec[MAXN], pos[MAXN], b[MAXN];

bool cmp(int u, int v){return a[u] < a[v];}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);
	for (int i = 0; i < n; i++)
		pos[sec[i]] = i;
	for (int i = 0; i < n; i++){
		int p = pos[i];
		p = (p+1)%n;
		b[i] = a[sec[p]];
	}

	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << "\n";
	return 0;
}