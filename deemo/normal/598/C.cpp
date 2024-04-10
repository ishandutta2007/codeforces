#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5 + 10;

int n;
ld x[MAXN], y[MAXN];
int sec[MAXN];

ld dis(ld a, ld b, ld c, ld d){
	ld ret = (a - c) * (a - c);
	ret += (b - d) * (b - d);
	return	sqrt(ret);
}

void adjust(ld &x, ld &y, ld res){
	ld d = dis(0, 0, x, y);
	x = res/d * x;
	y = res/d * y;
}	

int part(ld x, ld y){
	if (x >= 0 && y >= 0)	return	1;
	if (x <= 0 && y >= 0)	return	2;
	if (x <= 0 && y <= 0)	return	3;
	return	4;
}

bool cmp(int a, int b){
	int ta = part(x[a], y[a]);
	int tb = part(x[b], y[b]);
	if (ta != tb)	return	ta < tb;
	
	if (ta == 1)
		return	y[a] < y[b];
	if (ta == 2)
		return	x[a] > x[b];
	if (ta == 3)
		return	y[a] > y[b];
	return	x[a] < x[b];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	ld mini = 1e18;
	for (int i = 0; i < n; i++)	cin >> x[i] >> y[i], mini = min(mini, dis(0, 0, x[i], y[i]));	
	for (int i = 0; i < n; i++)	adjust(x[i], y[i], mini);
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);
	
	mini = 1e18;
	int ind = -1;
	for (int i = 0; i < n; i++){
		int a = sec[i], b = sec[(i + 1) % n];
		ld d = dis(x[a], y[a], x[b], y[b]);
		if (d < mini){
			mini = d;
			ind = i;
		}
	}
	cout << sec[ind] + 1 << " " << sec[(ind + 1) % n] + 1 << "\n";
	return	0;
}