//The bitter taste, the hidden face of the lost forgotten child
//The darkest need, the slowest speed, the debt unreconciled..

#include<cstdio>
#include<bitset>
#include<algorithm>
#include<vector>
#include<numeric>
#include<cstring>

using namespace std;

const int MAXN = 7e4 + 10;

int n, s, val[MAXN], sec[MAXN], c[MAXN], child[MAXN], par[MAXN];
bitset<MAXN> d[2], temp;
bool mark[MAXN];

bool cmp(int u, int v){return val[u] < val[v];}

int main(){
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++){
		scanf("%d", &val[i]);
		if (val[i] > s){
			printf("-1\n");
			return 0;
		}
	}
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);
	s -= val[sec[n - 1]];
	
	bool cur = 0;
	d[cur][0] = 1;
	for (int i = 0; i < n - 1; i++){
		d[!cur] = d[cur] | (d[cur]<<val[sec[i]]);
		temp = d[!cur] ^ d[cur];
		for (int j = temp._Find_first(); j < MAXN; j = temp._Find_next(j))
			par[j] = sec[i];
		cur = !cur;
	}

	memset(child, -1, sizeof(child));
	if (d[cur][s]){
		int z = s;
		while (z){
			mark[par[z]] = 1;
			c[par[z]] = val[par[z]];
			z -= val[par[z]];
		}
	
		z = 0;
		int lst = -1;
		for (int i = 0; i < n; i++)
			if (!mark[sec[i]]){
				c[sec[i]] = val[sec[i]] - z;
				child[sec[i]] = lst;
				z = val[sec[i]];
				lst = sec[i];
			}
		
		for (int i = 0; i < n; i++){
			printf("%d ", c[i]);
			if (~child[i])
				printf("1 %d\n", child[i] + 1);
			else
				printf("0\n");
		}
	}
	else
		printf("-1\n");
	
	return 0;
}