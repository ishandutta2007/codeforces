#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 20;
const int C = 26 + 2;

int n, q;
string s;
int cnt[C][4 * MAXN], lazy[C][4 * MAXN];

void build(int v, int b, int e, int t){
	if (e - b == 1){
		cnt[t][v] = bool(s[b] - 'a' == t);
		return;
	}

	int mid = (b + e)/ 2;
	build(v<<1, b, mid, t);
	build(v<<1^1, mid, e, t);
	cnt[t][v] = cnt[t][v<<1] + cnt[t][v<<1^1];
}

void shift(int v, int b, int e, int mid, int t){
	if (lazy[t][v] == 0)	return;
	if (lazy[t][v] == 1){
		lazy[t][v<<1] = lazy[t][v<<1^1] = 1;
		cnt[t][v<<1] = cnt[t][v<<1^1] = 0;
	}
	if (lazy[t][v] == 2){
		lazy[t][v<<1] = lazy[t][v<<1^1] = 2;
		cnt[t][v<<1] = mid - b;
		cnt[t][v<<1^1] = e - mid;
	}
	lazy[t][v] = 0;
}

void erase(int v, int b, int e, int l, int r, int t){
	if (l <= b && e <= r){
		lazy[t][v] = 1;
		cnt[t][v] = 0;
		return;
	}
	if (r <= b || e <= l)	return;

	int mid = (b + e)/ 2;
	shift(v, b, e, mid, t);
	erase(v<<1, b, mid, l, r, t);
	erase(v<<1^1, mid, e, l, r, t);
	cnt[t][v] = cnt[t][v<<1] + cnt[t][v<<1^1];
}

void insert(int v, int b, int e, int l, int r, int t){
	if (l <= b && e <= r){
		lazy[t][v] = 2;
		cnt[t][v] = e - b;
		return;
	}
	if (r <= b || e <= l)	return;

	int mid = (b + e)/ 2;
	shift(v, b, e, mid, t);
	insert(v<<1, b, mid, l, r, t);
	insert(v<<1^1, mid, e, l, r, t);
	cnt[t][v] = cnt[t][v<<1] + cnt[t][v<<1^1];
}

int get_sum(int v, int b, int e, int l, int r, int t){
	if (l <= b && e <= r)	return	cnt[t][v];
	if (r <= b || e <= l)	return	0;

	int mid = (b + e)/ 2;
	shift(v, b, e, mid, t);
	return	get_sum(v<<1, b, mid, l, r, t) + get_sum(v<<1^1, mid, e, l, r, t);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	cin >> s;
	for (int i = 0; i < C; i++)
		build(1, 0, n, i);

	while (q--){
		int l, r, type;	cin >> l >> r >> type;	l--;
		if (type){
			int cur = l;
			for (int i = 0; i < 26; i++){
				int temp = get_sum(1, 0, n, l, r, i);
				erase(1, 0, n, l, r, i);
				insert(1, 0, n, cur, cur + temp, i);
				cur += temp;
			}
		}
		else{
			int cur = l;
			for (int i = 25; i >= 0; i--){
				int temp = get_sum(1, 0, n, l, r, i);
				erase(1, 0, n, l, r, i);
				insert(1, 0, n, cur, cur + temp, i);
				cur += temp;
			}
		}
	}

	string ans = s;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 26; j++)
			if (get_sum(1, 0, n, i, i + 1, j)){
				ans[i] = j + 'a';
				break;
			}
	cout << ans << endl;
	return 0;
}