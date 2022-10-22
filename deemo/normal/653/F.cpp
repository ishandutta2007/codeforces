#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 10;
const int LOG = 21;

pair<pair<int, int>, int>	vec[MAXN];
int n, tt[LOG][MAXN], ss[MAXN];
int weed[4 * MAXN], nut[4 * MAXN], cnt[4 * MAXN];
char ch[MAXN];
string s;
vector<int>	tm[3 * MAXN];

int lcp(int a, int b){
	int ta = a;
	for (int w = LOG - 1; w >= 0 && max(a, b) < n; w--)
		if (max(a, b) + (1<<w) <= n && tt[w][a] == tt[w][b])
			a += (1<<w), b += (1<<w);
	return a - ta;
}

void shift(int v){
	weed[v<<1] += nut[v];
	weed[v<<1^1] += nut[v];
	nut[v<<1] += nut[v];
	nut[v<<1^1] += nut[v];
	nut[v] = 0;
}

void mf(int v, int b, int e, int x){
	if (e - b == 1){
		cnt[v] = 1;
		return;
	}

	int mid = (b + e)/ 2;
	shift(v);
	if (x < mid)
		mf(v<<1, b, mid, x);
	else
		mf(v<<1^1, mid, e, x);

	cnt[v] = 0;
	if (weed[v<<1] <= weed[v<<1^1])
		cnt[v] += cnt[v<<1];
	if (weed[v<<1^1] <= weed[v<<1])
		cnt[v] += cnt[v<<1^1];
	weed[v] = min(weed[v<<1], weed[v<<1^1]);
}

void water(int v, int b, int e, int l, int r, int val){
	if (l <= b && e <= r){
		weed[v] += val;
		nut[v] += val;
		return;
	}
	if (r <= b || e <= l)	return;

	int mid = (b + e)/ 2;
	shift(v);
	water(v<<1, b, mid, l, r, val);
	water(v<<1^1, mid, e, l, r, val);

	cnt[v] = 0;
	if (weed[v<<1] <= weed[v<<1^1])
		cnt[v] += cnt[v<<1];
	if (weed[v<<1^1] <= weed[v<<1])
		cnt[v] += cnt[v<<1^1];
	weed[v] = min(weed[v<<1], weed[v<<1^1]);
}

int smoke(int v, int b, int e){
	if (e - b == 1)	return weed[v]==0?cnt[v]:0;
	if (weed[v] >= 0)
		return weed[v] == 0?cnt[v]:0;

	int mid = (b + e)/ 2;
	shift(v);
	int aa = 0, bb = 0;
	if (weed[v<<1^1] >= 0)	bb = smoke(v<<1, b, mid);
	aa = smoke(v<<1^1, mid, e);
	return	aa + bb;
}

int main(){
	scanf("%d", &n);
	scanf("%s", ch);	s = ch;
	for (int i = 0; i < n; i++)
		tt[0][i] = s[i];
	for (int w = 1; w < LOG; w++){
		for (int i = 0; i < n; i++)
			if (i + (1<<(w - 1)) >= n)	
				vec[i] = {{tt[w - 1][i], -1}, i};
			else
				vec[i] = {{tt[w - 1][i], tt[w - 1][i + (1<<(w - 1))]}, i};

		sort(vec, vec + n);
		for (int i = 1; i < n; i++)
			if (vec[i].first == vec[i - 1].first)
				tt[w][vec[i].second] = tt[w][vec[i - 1].second];
			else
				tt[w][vec[i].second] = i;
	}
	for (int i = 0; i < n; i++)	ss[tt[LOG - 1][i]] = i;
	for (int i = 0; i < n - 1; i++){
		int cc = lcp(ss[i], ss[i + 1]);
		tm[ss[i] + cc].push_back(ss[i]);
	}

	ll ans = 0;
	for (int i = 0; i < n; i++){
		for (int u:tm[i])
			mf(1, 0, n, u);
		if (s[i] == ')')
			water(1, 0, n, 0, i + 1, 1);
		else
			water(1, 0, n, 0, i + 1, -1);
		ans += smoke(1, 0, n);
	}
	printf("%I64d\n", ans);
	return	0;
}