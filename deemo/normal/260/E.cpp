//Tell me where are you going Lord, and why in such haste!?

#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<iomanip>

using namespace std;

typedef long long ll;

const int max_n = 1e5 + 10;
const int INF = 1e9 + 5;
const int LOG = 19;

int n;
vector<int>	gec;
vector<vector<int>>	sec;
int xx[max_n], yy[max_n];
pair<int, int>	vec[max_n];
bool mark[10];
int a[10];
int x1, x2, y_1, y2;
int seg[LOG][max_n];

void gen(int rem){
	if (rem == 0){
		sec.push_back(gec);
		return;
	}

	for (int i = 0; i < 9; i++){
		if (mark[i])	continue;
		mark[i] = 1;
		gec.push_back(i);
		gen(rem - 1);
		mark[i] = 0;
		gec.pop_back();
	}
}

void input(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> vec[i].first >> vec[i].second;
		xx[i] = vec[i].first;
		yy[i] = vec[i].second;
	}
	for (int i = 0; i < 9; i++)
		cin >> a[i];
}

void init(){
	sort(xx, xx + n);
	sort(yy, yy + n);
	sort(vec, vec + n);
}

void build(int v, int b, int e, int d){
	if (e - b == 1){
		seg[d][b] = vec[b].second;
		return;
	}
	
	int mid = (b + e)/ 2;
	build(v<<1, b, mid, d + 1);
	build(v<<1^1, mid, e, d + 1);
	merge(seg[d + 1] + b, seg[d + 1] + mid, seg[d + 1] + mid, seg[d + 1] + e, seg[d] + b);
}

int fx(int v){
	v--;
	if (xx[v] == xx[v + 1])	return	INF;
	return	xx[v] + 1;
}

int fy(int v){
	v--;
	if (yy[v] == yy[v + 1])	return	INF;
	return	yy[v] + 1;
}

int get(int v, int b, int e, int l, int r, int hi, int lo, int d){
	if (l <= b && e <= r)
		return	lower_bound(seg[d] + b, seg[d] + e, hi) - lower_bound(seg[d] + b, seg[d] + e, lo);
	if (r <= b || e <= l)	return	0;
	
	int mid = (b + e)/ 2;
	return	get(v<<1, b, mid, l, r, hi, lo, d + 1) + get(v<<1^1, mid, e, l, r, hi, lo, d + 1); 
}	

int cnt(int ind){
	int xx1 = lower_bound(xx, xx + n, x1) - xx;
	int xx2 = lower_bound(xx, xx + n, x2) - xx;
	if (ind == 0)	
		return	get(1, 0, n, 0, xx1, INF, y_1, 0);
	if (ind == 1)	
		return	get(1, 0, n, xx1, xx2, INF, y_1, 0);
	if (ind == 2)	
		return	get(1, 0, n, xx2, n, INF, y_1, 0);
	if (ind == 3)	
		return	get(1, 0, n, 0, xx1, y_1, y2, 0);
	if (ind == 4)	
		return	get(1, 0, n, xx1, xx2, y_1, y2, 0);
	if (ind == 5)	
		return	get(1, 0, n, xx2, n, y_1, y2, 0);
	if (ind == 6)	
		return	get(1, 0, n, 0, xx1, y2, -INF, 0);
	if (ind == 7)	
		return	get(1, 0, n, xx1, xx2, y2, -INF, 0);
	return	get(1, 0, n, xx2, n, y2, -INF, 0);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(5);
	gen(9);
	input();
	init();
	build(1, 0, n, 0);
	
	bool fl = 0;
	for (auto q:sec){
		x1 = fx(a[q[0]] + a[q[3]] + a[q[6]]);
		x2 = fx(a[q[0]] + a[q[3]] + a[q[6]] + a[q[1]] + a[q[4]] + a[q[7]]);
		y_1 = fy(a[q[8]] + a[q[7]] + a[q[6]] + a[q[3]] + a[q[4]] + a[q[5]]);
		y2 = fy(a[q[8]] + a[q[7]] + a[q[6]]);
		if (x1 == INF || x2 == INF || y_1 == INF || y2 == INF)	continue;
		
		bool found = 1;
		for (int i = 0; i < 9; i++)
			if (cnt(i) != a[q[i]]){
				found = 0;
				break;
			}

		if (found){
			fl = 1;
			break;
		}
	}

	if (!fl){
		cout << -1 << endl;
		return 0;
	}

	cout << 0.5 + x1 - 1 << " " << 0.5 + x2 - 1 << endl;
	cout << 0.5 + y_1 - 1 << " " << 0.5 + y2 - 1 << endl;
	return 0;
}