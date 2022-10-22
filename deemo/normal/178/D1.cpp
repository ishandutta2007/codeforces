#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>

using namespace std;

typedef long long ll;

const int MAXN = 4 + 1;

int n, m, sum, vec[MAXN * MAXN];
int d[MAXN][MAXN], sec[MAXN * MAXN];
bool mark[MAXN * MAXN], fl;

void gen(int ind){
	if (ind == m){
		int c = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++, c++)
				d[i][j] = sec[c];

		if (n == 1)	fl = 1;
		if (fl)	return;
		if ((d[0][0] + d[0][1] + d[0][2]) * n == sum && (d[1][0] + d[1][1] + d[1][2]) * n == sum)
			if ((d[0][0] + d[1][0] + d[2][0]) * n == sum && (d[0][1] + d[1][1] + d[2][1]) * n == sum)
				if ((d[0][0] + d[1][1] + d[2][2]) * n == sum){
					int z = 0;
					for (int i = n - 1; i >= 0; i--)
						z += d[i][(n - 1) - i];
					if (z * n == sum)	fl = 1;
				}
		return;
	}

	for (int i = 0; i < m; i++){
		if (mark[i])	continue;
		mark[i] = 1;
		sec[ind] = vec[i];
		gen(ind + 1);
		mark[i] = 0;
		if (fl)	return;
	}
}

int main(){
	cin >> n;	m = n * n;
	for (int i = 0; i < m; i++)	cin >> vec[i], sum += vec[i];
	if (n < 4){
		gen(0);	
		assert(fl);
		cout << d[0][0] + d[0][1] + d[0][2] << endl;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++)
				cout << d[i][j] << " ";
			cout << endl;
		}
		return	0;
	}
	return	0;
}