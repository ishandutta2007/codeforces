#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<fstream>

using namespace std;

const int max_n = 1e5 + 100;
const int C = 30;

int n, q;
string s;
int save[C];
int sum[4 * max_n][C], lazy[4 * max_n][C];

void build(int v, int b, int e){
	for (int i = 0; i < 26; i++)
		lazy[v][i] = -1;
	if (e - b == 1)	return;
	int mid = (b + e)/ 2;
	build(v<<1, b, mid);
	build(v<<1^1, mid, e);
}

void shift(int v, int b, int e, int mid, int id){
	if (lazy[v][id] == -1)	return;
	lazy[v<<1][id] = lazy[v<<1^1][id] = lazy[v][id];
	sum[v<<1][id] = (mid - b) * lazy[v][id];
	sum[v<<1^1][id] = (e - mid) * lazy[v][id];
	lazy[v][id] = -1;
}

void modify(int v, int b, int e, int l, int r, int id, int val){
	if (l <= b && e <= r){
		lazy[v][id] = val;
		sum[v][id] = (e - b) * val;
		return;
	}
	if (r <= b || e <= l)	return;

	int mid = (b + e)/ 2;
	shift(v, b, e, mid, id);
	modify(v<<1, b, mid, l, r, id, val);
	modify(v<<1^1, mid, e, l, r, id, val);
	sum[v][id] = sum[v<<1][id] + sum[v<<1^1][id];
}

void init(){
	build(1, 0, n);
	for (int i = 0; i < n; i++)
		modify(1, 0, n, i, i + 1, s[i] - 97, 1);
}

int get(int v, int b, int e, int l, int r, int id){
	if (l <= b && e <= r)	return	sum[v][id];
	if (r <= b || e <= l)	return	0;
	
	int mid = (b + e)/ 2;
	shift(v, b, e, mid, id);
	return	get(v<<1, b, mid, l, r, id) + get(v<<1^1, mid, e, l, r, id);
}

void get_Ans(){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 26; j++)
			if (get(1, 0, n, i, i + 1, j))	
				s[i] = j + 97;
}

int main(){
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin >> n >> q >> s;
	init();

	while (q--){
		int l, r;	fin >> l >> r;	l--;
		int cnt = 0, ind = -1;
		for (int i = 0; i < 26; i++){
			save[i] = get(1, 0, n, l, r, i);
			if (save[i] % 2 == 1)	cnt++, ind = i;
		}
		if ((r - l) % 2 != cnt)	continue;
		
		for (int i = 0; i < 26; i++)
			modify(1, 0, n, l, r, i, 0);
		if ((r - l) % 2)	modify(1, 0, n, (r + l) / 2, (r + l) / 2 + 1, ind, 1);
		int t = 0;
		for (int i = 0; i < 26; i++){
			if (save[i] / 2){
				modify(1, 0, n, l + t, l + t + save[i]/2, i, 1);
				modify(1, 0, n, r - t - save[i]/2 , r - t, i, 1);
			}
			t += save[i]/2;
		}
	}
	get_Ans();
	fout << s << endl;
	return 0;
}