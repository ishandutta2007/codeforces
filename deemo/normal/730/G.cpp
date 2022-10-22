#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 200 + 4;

int n, a[MAXN], b[MAXN], sec[MAXN];

bool cmp(int u, int v){return a[u] < a[v];}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		b[i] += a[i] - 1;
		bool fail = 0;
		for (int j = 0; !fail && j < i; j++){
			if (a[i] <= a[j] && b[i] >= a[j])	fail = 1;
			if (a[j] <= a[i] && b[j] >= a[i])	fail = 1;
		}

		if (fail){
			b[i] -= a[i] - 1;
			iota(sec, sec + i, 0);
			sort(sec, sec + i, cmp);
			if (a[sec[0]] > b[i])
				a[i] = 1;
			else
				for (int j = 0; j < i; j++){
					int u = sec[j];
					int z = (j + 1 == i?(int)2e9 + 3:a[sec[j + 1]]);
					if (z - b[u] - 1 >= b[i]){
						a[i] = b[u] + 1;
						b[i] += a[i] - 1;
						break;
					}
				}
		}

		cout << a[i] << " " << b[i] << "\n";
	}
	return 0;
}