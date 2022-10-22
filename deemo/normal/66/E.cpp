#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 1e5 + 40;
const int INF = 1e9 + 5;

int n, vec[3 * MAXN], sec[3 * MAXN], gec[3 * MAXN], p[3 * MAXN];
int weed[10 * MAXN], nut[10 * MAXN];
bool ans[3 * MAXN];

void plant(int v, int b, int e){
	if (e - b == 1){
		weed[v] = p[b];
		return;
	}	

	int mid = (b + e)/ 2;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	weed[v] = min(weed[v<<1], weed[v<<1^1]);
}	

void absorb(int v){
	weed[v<<1] += nut[v];
	weed[v<<1^1] += nut[v];
	nut[v<<1] += nut[v];
	nut[v<<1^1] += nut[v];
	nut[v] = 0;
}	

void water(int v, int b, int e, int l, int r, int val){
	if (l <= b && e <= r){
		weed[v] += val;
		nut[v] += val;
		return;
	}
	if (r <= b || e <= l)	return;

	int mid = (b + e)/ 2;
	absorb(v);
	water(v<<1, b, mid, l, r, val);
	water(v<<1^1, mid, e, l, r, val);
	weed[v] = min(weed[v<<1], weed[v<<1^1]);
}	

void put(int v, int b, int e, int x, int val){
	if (e - b == 1){
		weed[v] = val;
		return;
	}

	int mid = (b + e)/ 2;
	absorb(v);
	if (x < mid)
		put(v<<1, b, mid, x, val);
	else
		put(v<<1^1, mid, e, x, val);
	weed[v] = min(weed[v<<1], weed[v<<1^1]);
}

int smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return	weed[v];
	if (r <= b || e <= l)	return	INF;

	int mid = (b + e)/ 2;
	absorb(v);
	return	min(smoke(v<<1, b, mid, l, r), smoke(v<<1^1, mid, e, l, r));
}

void solve(bool fl = 0){
	memset(p, 0, sizeof(p));
	memset(weed, 0, sizeof(weed));
	memset(nut, 0, sizeof(nut));
	for (int i = 0; i < n; i++){
		if (i)	p[i] = p[i - 1];
		p[i] += vec[i] - sec[i];
	}
	plant(1, 0, 2 * n);
	for (int i = 0; i < n; i++){
		if (fl && i)
			ans[n - i] |= (smoke(1, 0, 2 * n, i, i + n) >= 0);
		else
			ans[i] |= (smoke(1, 0, 2 * n, i, i + n) >= 0);

		int z = vec[i] - sec[i];
		water(1, 0, 2 * n, i, i + n, -z);
		put(1, 0, 2 * n, i + n, smoke(1, 0, 2 * n, i + n - 1, i + n) + z);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	for (int i = 0; i < n; i++)	cin >> sec[i];
	solve();

	memcpy(gec, sec, sizeof(sec));
	for (int i = 0; i < n; i++)
		sec[i] = gec[(i + n - 1) % n];
	reverse(sec + 1, sec + n);
	reverse(vec + 1, vec + n);
	solve(1);

	int tt = 0;
	for (int i = 0; i < n; i++)
		if (ans[i])	tt++;
	cout << tt << "\n";
	for (int i = 0; i < n; i++)
		if (ans[i])	cout << i + 1 << " ";
	cout << "\n";
	return	0;
}