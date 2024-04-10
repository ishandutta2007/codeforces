#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 2e4 + 10;
const int MAXVAL = 1e5 + 10;

int n, k, t, vec[MAXN], sec[MAXN], cur, fen[MAXVAL], lst[MAXN];

void add(int v, int val){
	for (; v < MAXVAL; v += v & (-v))
		fen[v] += val;
}

int get(int v){
	int ret = 0;
	for (; v; v -= v & (-v))
		ret += fen[v];
	return	ret;
}

int main(){
	scanf("%d %d %d", &n, &k, &t);
	for (int i = 0; i < n; i++){
		int a, b, c;	scanf("%d:%d:%d", &a, &b, &c);
		vec[i] = c + b * 60 + a * 3600;	vec[i]++;
	}

	bool found = 0;
	for (int i = 0; i < n; i++)
		if (lower_bound(vec, vec + n, vec[i] + t) - lower_bound(vec, vec + n, vec[i]) >= k){
			found = 1;
			break;
		}
	if (!found){
		printf("No solution\n");
		return 0;
	}

	for (int i = 0; i < n; i++){
		int z = get(vec[i]) - get(max(0, vec[i] - t));
		if (z < k){
			sec[i] = ++cur;
			add(vec[i], 1);
			lst[cur] = vec[i];
		}
		else{
			sec[i] = cur;
			add(lst[cur], -1);
			lst[cur] = vec[i];
			add(lst[cur], 1);
		}
	}

	cout << cur << "\n";
	for (int i = 0; i < n; i++)
		cout << sec[i] << "\n";
	return	0;	
}