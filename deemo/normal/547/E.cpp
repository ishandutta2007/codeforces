//I will wander 'til the end of time, torn away from you..

#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 2e5 + 50;
const int LOG = 20;

int n, q, ss[MAXN], p[MAXN], mx[MAXN], adr[MAXN];
int tt[LOG][MAXN], lc[LOG][MAXN], weed[LOG + 2][MAXN];
pair<pair<int, int>, int>	vec[MAXN];
char ch[MAXN];
string s[MAXN];

int lcp(int a, int b){
	int ta = a, tb = b;
	for (int i = LOG - 1; i >= 0 && a < mx[ta] && b < mx[tb]; i--)
		if (a + (1 << i) <= mx[a] && b + (1<<i) <= mx[b] && tt[i][a] == tt[i][b])
			a += (1<<i), b += (1<<i);
	return	a - ta;
}

void plant(int v, int b, int e, int de = 0){
	if (e - b == 1){
		weed[de][b] = adr[ss[b]];
		return;
	}

	int mid = (b + e)/ 2;
	plant(v<<1, b, mid, de + 1);
	plant(v<<1^1, mid, e, de + 1);
	merge(weed[de + 1] + b, weed[de + 1] + mid, weed[de + 1] + mid, weed[de + 1] + e, weed[de] + b);
}

int smoke(int v, int b, int e, int l, int r, int lo, int hi, int de = 0){
	if (l <= b && e <= r)
		return	lower_bound(weed[de] + b, weed[de] + e, hi) - lower_bound(weed[de] + b, weed[de] + e, lo);
	if (r <= b || e <= l)	return 0;

	int mid = (b + e)/ 2;
	return	smoke(v<<1, b, mid, l, r, lo, hi, de + 1) + smoke(v<<1^1, mid, e, l, r, lo, hi, de + 1);
}

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++){
		scanf("%s", ch);
		s[i] = ch;
		if (i)
			p[i] = p[i - 1] + (int)s[i - 1].size();
	}
	p[n] = p[n - 1] + (int)s[n - 1].size();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < (int)s[i].size(); j++)
			tt[0][p[i] + j] = s[i][j];

	for (int w = 1; w < LOG; w++){
		for (int i = 0; i < n; i++)
			for (int j = 0; j < (int)s[i].size(); j++)
				if (j + (1 << (w - 1)) >= (int)s[i].size())
					vec[p[i] + j] = {{tt[w - 1][p[i] + j], -1}, p[i] + j};
				else
					vec[p[i] + j] = {{tt[w - 1][p[i] + j], tt[w - 1][p[i] + j + (1 << (w - 1))]}, p[i] + j};

		sort(vec, vec + p[n]);
		for (int i = 1; i < p[n]; i++)
			if (vec[i].first == vec[i - 1].first)
				tt[w][vec[i].second] = tt[w][vec[i - 1].second];
			else
				tt[w][vec[i].second] = i;
	}
	for (int i = 0; i < p[n]; i++)	ss[i] = vec[i].second;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < (int)s[i].size(); j++)	mx[p[i] + j] = p[i + 1];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < (int)s[i].size(); j++)	adr[p[i] + j] = i;
	for (int i = 0; i < p[n] - 1; i++)	lc[0][i] = lcp(ss[i], ss[i + 1]);
	for (int i = 1; i < LOG; i++)
		for (int j = 0; j < p[n] - 1; j++)
			if (j + (1 << (i - 1)) >= p[n] - 1)
				lc[i][j] = lc[i - 1][j];
			else
				lc[i][j] = min(lc[i - 1][j], lc[i - 1][j + (1 << (i - 1))]);
	plant(1, 0, p[n]);

	while (q--){
		int l, r, k;	scanf("%d %d %d", &l, &r, &k);	l--, k--;
		int tl = tt[LOG - 1][p[k]], tr = tl, sz = (int)s[k].size();
		for (int i = LOG - 1; i >= 0; i--)
			if (tr + (1<<i) < p[n] && lc[i][tr] >= sz) tr += (1<<i);
		tr++;
		
		for (int i = LOG - 1; i >= 0; i--)
			if (tl - (1<<i) >= 0 && lc[i][tl - (1<<i)] >= sz)	tl -= (1<<i);
		printf("%d\n", smoke(1, 0, p[n], tl, tr, l, r));
	}
	return	0;
}