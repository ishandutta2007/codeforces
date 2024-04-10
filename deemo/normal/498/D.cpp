#include<iostream>

using namespace std;

const int MAXN = 1e5 + 20;
const int C = 60;

int n, vec[MAXN];
int seg[C][4 * MAXN];

void merge(int v){
	for (int i = 0; i < C; i++)
		seg[i][v] = seg[i][v<<1] + seg[(i + seg[i][v<<1]) % C][v<<1^1];
}

void build(int v, int b, int e){
	if (e - b == 1){
		for (int i = 0; i < C; i++)
			if (i == 0 || i % vec[b] == 0)
				seg[i][v] = 2;
			else
				seg[i][v] = 1;
		return;
	}

	int mid = (b + e)/ 2;
	build(v<<1, b, mid);
	build(v<<1^1, mid, e);
	merge(v);
}

void modify(int v, int b, int e, int x, int val){
	if (e - b == 1){
		vec[b] = val;
		for (int i = 0; i < C; i++)
			if (i == 0 || i % vec[b] == 0)
				seg[i][v] = 2;
			else
				seg[i][v] = 1;
		return;
	}

	int mid = (b + e)/ 2;
	if (x < mid)
		modify(v<<1, b, mid, x, val);
	else
		modify(v<<1^1, mid, e, x, val);
	merge(v);
}

int get(int v, int b, int e, int l, int r, int cur = 0){
	if (l <= b && e <= r)	return	seg[cur][v];
	if (r <= b || e <= l)	return	0;

	int mid = (b + e)/ 2;
	int a = get(v<<1, b, mid, l, r, cur);
	return	a + get(v<<1^1, mid, e, l, r, (cur + a) % C);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	build(1, 0, n);

	int q;	cin >> q;
	while (q--){
		char type;	cin >> type;	
		if (type == 'A'){
			int l, r;	cin >> l >> r;	l--, r--;
			cout << get(1, 0, n, l, r) << "\n";
		}		
		else{
			int v, val;	cin >> v >> val;	v--;
			modify(1, 0, n, v, val);
		}
	}
	return 0;
}