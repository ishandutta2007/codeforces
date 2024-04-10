#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 100005;
int n;
int a[maxn], b[maxn], p[maxn], pp[maxn];
int tx[maxn], ty[maxn], tz[maxn];

int out(int i, int j){
	printf("? %d %d\n", i, j);
	fflush(stdout);
	static int res;
	scanf("%d", &res);
	return res;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		a[i] = out(0, i);
	
	for(int i = 0; i < n; ++i){
		tx[i] = i, ty[i] = 0, tz[i] = out(tx[i], ty[i]);
	}

	int cnt = 0;
	for(int x = 0; x < n; ++x){
		bool flag = 1;
		for(int i = 0; i < n; ++i){
			b[i] = x ^ a[i];
			if(b[i] >= n) flag = 0;
			p[b[i]] = i;
		}
		
		if(p[0] != x) continue;

		for(int i = 0; i < n; ++i)
			if((p[tx[i]] ^ b[ty[i]]) != tz[i]) flag = 0;

		if(!flag) continue;
		
		
		/*
		printf("%d\n", x);
		for(int i = 0; i < n; ++i)
			printf("%d ", b[i]); printf("\n");
		for(int i = 0; i < n; ++i)
			printf("%d ", p[i]); printf("\n");
		fflush(stdout);
		*/
		

		memcpy(pp, p, sizeof(p));
		++cnt;
	}
	
	printf("!\n");
	printf("%d\n", cnt);
	for(int i = 0; i < n; ++i)
		printf("%d ", pp[i]);
	fflush(stdout);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}