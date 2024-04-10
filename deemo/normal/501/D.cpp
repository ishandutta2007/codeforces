#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<cstring>

using namespace std;

const int MAXN = 2e5 + 10;

int n, p[2][MAXN], fen[MAXN], ss[MAXN];

int get(int x){
	int ret = 0;
	for (; x; x -= x & (-x))
		ret += fen[x];
	return	ret;
}

void add(int x, int val){
	for (; x < MAXN; x += x & (-x))
		fen[x] += val;
}

void f(bool t){
	memset(fen, 0, sizeof(fen));
	for (int i = 1; i <= n; i++)	add(i, 1);
	for (int i = 0; i < n; i++){
		int x = p[t][i];
		int pos = get(x);
		ss[i] += pos - 1;
		add(x, -1);
	}
}

int gg(int ind){
	int b = 1, e = n, ret = 1;
	while (b <= e){
		int mid = (b + e)/ 2;
		if (get(mid) >= ind)
			ret = mid, e = mid - 1;
		else
			b = mid + 1;
	}
	return	ret;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &p[0][i]), p[0][i]++;
	for (int i = 0; i < n; i++)	scanf("%d", &p[1][i]), p[1][i]++;
	for (int i = 0; i < 2; i++)	f(i);
	for (int i = n - 2; i >= 0; i--){
		int x = bool(ss[i] >= (n - i));
		ss[i] %= (n - i);
		if (i)
			ss[i - 1] += x;
	}

	memset(fen, 0, sizeof(fen));
	for (int i = 1; i <= n; i++)	add(i, 1);
	for (int i = 0; i < n; i++){
		int x = gg(ss[i] + 1);
		printf("%d ", x - 1);
		add(x, -1);
	}
	printf("\n");
	return	0;
}