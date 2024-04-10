#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int SQRT = 550;
const int MAXN = 3e5 + 20;
const int MOD = 1e9 + 9;

int n, q;
int sum[SQRT * 2], vec[MAXN], f[MAXN];
int ss[MAXN], p[MAXN];

void init(){
	f[0] = f[1] = 1;
	for (int i = 2; i < MAXN; i++)
		f[i] = (f[i - 1] + f[i - 2]) % MOD;
	for (int i = 1; i < MAXN; i++)
		p[i] = (p[i - 1] + f[i - 1]) % MOD;
}

void update(int l){
	int a = ss[l], b = ss[l + 1];
	if (a == b && b == 0)	return;

	ss[l] = ss[l + 1] = 0;
	vec[l] = (vec[l] + a) % MOD;
	vec[l + 1] = (vec[l + 1] + b) % MOD;

	for (int i = l + 2; i < l + SQRT && i < n; i++){
		int temp = (a + b) % MOD;
		a = b;
		b = temp;
		vec[i] = (vec[i] + b) % MOD;
	}
}	

void add(int l, int r){
	update(l/SQRT * SQRT);
	update(r/SQRT * SQRT);

	int i, rsq = r/SQRT;
	for (i = l; i < r && i % SQRT != 0; i++)
		vec[i] = (vec[i] + f[i - l]) % MOD, sum[i/SQRT] = (sum[i/SQRT] + f[i - l]) % MOD;

	for (int z = i/SQRT; z != rsq; z++){
		i = z * SQRT;
		ss[i] = (ss[i] + f[i - l]) % MOD;
		if (i + 1 < n)
			ss[i + 1] = (ss[i + 1] + f[i + 1 - l]) % MOD;
		
		sum[z] = (sum[z] + MOD - p[i - l]) % MOD;
		sum[z] = (sum[z] + p[min(n, i + SQRT) - l]) % MOD;
	}
	
	i = max(i, rsq * SQRT);
	for (; i < r; i++)
		vec[i] = (vec[i] + f[i - l]) % MOD, sum[rsq] = (sum[rsq] + f[i - l]) % MOD;
}

int get(int l, int r){
	update(l/SQRT * SQRT);
	update(r/SQRT * SQRT);

	int ret = 0;
	int i;
	for (i = l; i < r && i % SQRT != 0; i++)
		ret = (ret + vec[i]) % MOD;
	for (; i / SQRT != r/SQRT; i += SQRT)
		ret = (ret + sum[i/SQRT]) % MOD;
	for (; i < r; i++)
		ret = (ret + vec[i]) % MOD;
	return	ret;
}

int main(){
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++){
		scanf("%d", &vec[i]);
		sum[i/SQRT] = (sum[i/SQRT] + vec[i]) % MOD;
	}
	init();

	while (q--){
		int type, l, r;	scanf("%d %d %d", &type, &l, &r);	l--;
		if (type == 2)
			printf("%d\n", get(l, r));
		else
			add(l, r);
	}
	return	0;
}