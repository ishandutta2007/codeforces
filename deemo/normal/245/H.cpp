#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>

using namespace std;

const int MAXN = 5e3 + 10;
const int MAX = MAXN * MAXN;

int n;
string s;
int f[MAXN], g[MAXN];
int ss[MAXN][MAXN];
int mark[MAXN];
char ch[MAXN];

int dev(int l, int r){
	if (l == 0)	return	1;
	if (r == n - 1)	return	1;
	if (s[--l] != s[++r])	return	1;
	return	1 + dev(l, r);
}

void init(){
	for (int i = 0; i < n; i++){
		f[i] = dev(i, i);
		if (i < n && s[i] == s[i + 1])	g[i] = dev(i, i + 1);
	}
	for (int i = 0; i < n; i++){
		memset(mark, 0, sizeof(mark));
		int cnt = 0, c = 0;
		for (int j = i; j < n; j++){
			int z = min(f[j], j - i + 1);
			mark[j] += 1;
			mark[j + z] -= 1;

			z = min(j - i + 1, g[j]);
			mark[j + 1] += 1;
			mark[j + z + 1] -= 1;

			c += mark[j];
			cnt += c;
			ss[i][j + 1] = cnt;
		}
	}
}

int main(){
	scanf("%s", ch);
	s = ch;	n = s.size();
	init();

	int q;	scanf("%d", &q);
	for (int i = 0; i < q; i++){
		int l, r;	scanf("%d%d", &l, &r);	l--;
		printf("%d\n", ss[l][r]);
	}
	return 0;
}