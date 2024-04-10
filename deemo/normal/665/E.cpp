#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;

int n, k, vec[MAXN], p[MAXN], tr[2][MAXN * 30], cc[MAXN * 30], sz;
ll ans;

void insert(int x){
	int cur = 0;
	for (int i = 30; i >= 0; i--){
		bool z = (x>>i)&1;
		if (!tr[z][cur])
			tr[z][cur] = ++sz;
		assert(tr[z][cur]);
		cc[tr[z][cur]]++;
		cur = tr[z][cur];
	}
}

void f(int x){
	int ss = 0, cur = 0;
	for (int i = 30; i >= 0; i--){
		bool z = (x >> i) & 1;
		if (ss + (1<<i) >= k){
			ans += cc[tr[!z][cur]];
			if (!tr[z][cur])	return;
			cur = tr[z][cur];
		}
		else{
			if (!tr[!z][cur])	return;
			cur = tr[!z][cur];
			ss += (1<<i);
		}
	}
}

int main(){
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)	scanf("%d", &vec[i]);
	for (int i = 0; i < n; i++)
		p[i + 1] = p[i] ^ vec[i];
	insert(0);
	for (int i = 0; i < n; i++){
		f(p[i + 1]);
		insert(p[i + 1]);
	}
	printf("%I64d\n", ans);
	return 0;
}