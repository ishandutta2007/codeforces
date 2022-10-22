//I don't see what the big deal is anyway

#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 20;
const int MOD = 1e9 + 7;
const int BASE[2] = {701, 721};

int n;
bool sec[MAXN];
ll ss[2][MAXN];
ll hh[2][4 * MAXN], revh[2][4 * MAXN];

void sprout(int v, int b, int e, int mid){
	for (int i = 0; i < 1; i++){
		hh[i][v] = (hh[i][v<<1] * ss[i][e - mid] + hh[i][v<<1^1]) % MOD;
		revh[i][v] = (revh[i][v<<1^1] * ss[i][mid - b] + revh[i][v<<1]) % MOD;
	}
}

void init(){
	ss[0][0] = ss[1][0] = 1;
	for (int w = 0; w < 1; w++)
		for (int i = 1; i < MAXN; i++)
			ss[w][i] = (ss[w][i - 1] * BASE[w]) % MOD;
}

void water(int v, int b, int e, int x){
	if (e - b == 1){
		sec[b] = 1;
		for (int i = 0; i < 1; i++)
			hh[i][v] = revh[i][v] = sec[b];
		return;
	}

	int mid = (b + e)/ 2;
	if (x < mid)
		water(v<<1, b, mid, x);
	else
		water(v<<1^1, mid, e, x);
	sprout(v, b, e, mid);
}

pair<int, int>	get(int v, int b, int e, int l, int r, int type){
	if (l <= b && e <= r){
		if (type == 0)
			return	{hh[0][v], hh[1][v]};
		return	{revh[0][v], revh[1][v]};
	}
	if (r <= b || e <= l)	return	{0, 0};

	int mid = (b + e)/ 2;
	pair<int, int>	a = get(v<<1, b, mid, l, r, type), bb = get(v<<1^1, mid, e, l, r, type);
	if (type == 0){
		a.first = (a.first * ss[0][max(0, min(r - mid, e - mid))] + bb.first) % MOD;
	//	a.second = (a.second * ss[1][max(0, min(r - mid, e - mid))] + bb.second) % MOD;
	}
	else{
		a.first = (bb.first * ss[0][max(0, min(mid - b, mid - l))] + a.first) % MOD;
		//a.second = (bb.second * ss[1][max(0, min(mid - b, mid - l))] + a.second) % MOD;
	}
	return	a;
}

int main(){
	init();
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int x;	scanf("%d", &x);	x--;
		int sz = min(x, n - (x + 1));
		if (get(1, 0, n, x - sz, x, 0) != get(1, 0, n, x + 1, x + 1 + sz, 1)){
			printf("YES\n");
			return	0;
		}
		water(1, 0, n, x);
		//if (n > 100 && i == 2e5)	break;
	}
	printf("NO\n");
	return	0;	
}