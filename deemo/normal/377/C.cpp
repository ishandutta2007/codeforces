#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>

using namespace std;

const int MAXN = 20 + 1;
const int MAX = 1 << MAXN;

int n, m;
int vec[200], sec[MAXN];
bool mark[MAX][MAXN];
int d[MAX][MAXN];

int get(int a, int b){
	if (b == m)
		return	0;
	if (mark[a][b])
		return	d[a][b];
	mark[a][b] = 1;

	int z = sec[b];
	int maxi = -1e9;
	if (z < 3){
		int ta = a, j = 0;
		while (((ta & 1) == 0))	ta >>= 1, j++;
		ta = vec[j];
		int x = get(a ^ (1 << j), b + 1);
		if (b != m - 1 && sec[b + 1] % 2 != sec[b] % 2)
			x *= -1;
		ta += x;
		maxi = max(maxi, ta);
	}
	else{
		int ta = a;
		for (int i = 0; ta; i++, ta >>= 1)
			if ((ta & 1)){
				int x = get(a ^ (1 << i), b + 1);
				if (b != m - 1 && sec[b + 1] % 2 != sec[b] % 2)
					x *= -1;
				maxi = max(maxi, x);
			}
		int x = get(a, b + 1);
		if (b != m - 1 && sec[b + 1] % 2 != sec[b] % 2)
			x *= -1;
		maxi = max(maxi, x);
	}
	d[a][b] = maxi;
	return	d[a][b];
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)	
		cin >> vec[i];
	sort(vec, vec + n, greater<int>());
	cin >> m;
	for (int i = 0; i < m; i++){
		char ch;	int x;	cin >> ch >> x;
		if (ch == 'p' && x == 1)	sec[i] = 1;
		if (ch == 'p' && x == 2)	sec[i] = 2;
		if (ch == 'b' && x == 1)	sec[i] = 3;
		if (ch == 'b' && x == 2)	sec[i] = 4;
	}
	int ans = get((1<<m) - 1, 0);
	if (sec[0] % 2 != 1)
		ans *= -1;
	cout << ans << endl;
	return 0;
}