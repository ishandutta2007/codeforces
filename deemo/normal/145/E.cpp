#include<algorithm>
#include<cmath>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

const int max_n = 1e6 + 10;

int n, q;
char s[2][max_n];
int r4[2][4 * max_n], r7[2][4 * max_n], c4[2][4 * max_n], c7[2][4 * max_n];
bool first[4 * max_n];
bool lazy[4 * max_n];

void merge(int v, int b, int e, int mid, int t){
	int f, g, h;
	if (t == 0)
		f = first[v], g = first[v<<1], h = first[v<<1^1];
	else
		f = !first[v], g = !first[v<<1], h = !first[v<<1^1];

	c4[f][v] = c4[g][v<<1] + c4[h][v<<1^1];
	c7[f][v] = c7[g][v<<1] + c7[h][v<<1^1];
	r4[f][v] = c4[f][v];
	r7[f][v] = max(r7[g][v<<1] + c7[h][v<<1^1], r4[g][v<<1] + r7[h][v<<1^1]);
}

void build(int v, int b, int e, int t){
	if (e - b == 1){
		if (s[t][b] == '4')
			c4[t][v] = r4[t][v] = 1;
		else
			c7[t][v] = r7[t][v] = 1;
		return;
	}

	int mid = (b + e)/ 2;
	build(v<<1, b, mid, t);
	build(v<<1^1, mid, e, t);
	merge(v, b, e, mid, t);
}

void shift(int v){
	if (!lazy[v])	return;
	lazy[v] = 0;
	lazy[v<<1] = !lazy[v<<1];
	first[v<<1] = !first[v<<1];
	lazy[v<<1^1] = !lazy[v<<1^1];
	first[v<<1^1] = !first[v<<1^1];
}

void modify(int v, int b, int e, int l, int r){
	if (l <= b && e <= r){
		lazy[v] = !lazy[v];
		first[v] = !first[v];
		return;
	}
	if (r <= b || e <= l)	return;

	int mid = (b + e)/ 2;
	shift(v);
	modify(v<<1, b, mid, l, r);
	modify(v<<1^1, mid, e, l, r);
	merge(v, b, e, mid, 0);
	merge(v, b, e, mid, 1);
}

int main(){
	scanf("%d%d", &n, &q);
	scanf("%s", s[0]);
	for (int i = 0; i < n; i++)
		if (s[0][i] == '4')
			s[1][i] = '7';
		else
			s[1][i] = '4';
	build(1, 0, n, 0);
	build(1, 0, n, 1);

	while (q--){
		char type[10];
		scanf("%s", type);
		if (type[0] == 'c'){
			printf("%d\n", max(r4[first[1]][1], r7[first[1]][1]));
			continue;
		}
		int l, r;	
		scanf("%d%d", &l, &r);	l--;
		modify(1, 0, n, l, r);
	}	
	return 0;
}