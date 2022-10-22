#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>

using namespace std;

const int MAXN = 23;
const int MAX = (1 << 23);

int n;
int gec[MAXN];
int	sec[MAXN * MAXN], vec[MAXN * MAXN];
int sz;
bool d[MAXN][MAX];
bool ans[MAX];

void init(){
	for (int i = 0; i < n; i++){
		sz = 0;
		for (int j = 0; j ^ n; j++)
			for (int w = 0; w ^ n; w++)
				if (gec[j] + gec[w] == gec[i])	sec[sz++] = (1 << j) | (1 << w);

		for (int m = 1; m ^ (1 << n); m++)
			for (int j = 0; !d[i][m] && j ^ sz; j++)
				if ((m & sec[j]) == sec[j])
					d[i][m] = 1;
	}
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> gec[i];
	init();
	ans[1] = 1;
	int ret = 500;
	for (int i = 2; i ^ (1 << n); i++){
		int z = n - 1;
		while (((i >> z) & 1) == 0)	z--;
		
		int y = i & ((1 << z) - 1);
		if (((y >> (z - 1)) & 1) == 0){
			y ^= (1 << (z - 1));
			if (d[z][y])	ans[i] |= ans[y];
		}
		else{
			for (int j = z - 1; !ans[i] && j >= 0; j--)
				if (((y >> j) & 1) == 0){
					int p = y ^ (1 << j);
					if (d[z][p])	ans[i] |= ans[p];
				}
			if (d[z][y])	ans[i] |= ans[y];
		}
		if (((i >> (n - 1)) & 1) && ans[i])	
			ret = min(ret, __builtin_popcount(i));
	}
	if (n == 1)
		ret = 1;

		
	if (ret == 500)	ret = - 1;
	cout << ret << endl;
	return 0;
}