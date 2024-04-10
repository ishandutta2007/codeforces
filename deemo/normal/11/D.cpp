//It's time to begin, isn't it?
//I get a little bit bigger but then I'll admit I'm just the same as I was..
//Now don't you understand that I'm never changin' who I am.

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int max_n = 19 + 3;
const int MAX = 1 << 20;

int n, m;
int adj[max_n], save[MAX];
ll d[MAX][max_n];
ll ans;

void init(){
	for (int i = 1; i < (1 << n); i++){
		int t = i;
		int ret = 0;
		while (t){
			t >>= 1;
			ret++;
		}		
		save[i] = ret - 1;
	}
}

int main(){
	cin >> n >> m;
	while (m--){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a] |= 1 << b;
		adj[b] |= 1 << a;
	}
	for (int i = 0; i < n; i++)
		d[1 << i][i] = 1;
	init();

	for (int i = 1; i < (1 << n); i++){
		if (__builtin_popcount(i) == 1)	continue;
		for (int j = 0; j < n; j++){
			if (((i >> j) & 1) == 0)	continue;
			for (int w = 0; w < n; w++){
				if ((i >> w) & 1){
					if (w == j)	continue;
					if ((adj[j] >> w) & 1){
						if (j != save[i]){
							if (w != save[i] || __builtin_popcount(i) == 2)
								d[i][j] += d[i ^ (1 << j)][w];
						}
						else
							d[i][j] += d[i][w];
					}
				}
			}
		}
	}

	for (int i = 1; i < (1 << n); i++){
		if (__builtin_popcount(i) < 3)	continue;
		ans += d[i][save[i]];
	}
	ans /= 2;
	cout << ans << endl;
	return 0;
}