#include<bits/stdc++.h>
using namespace std;
const int N = 1000000 + 10;
const long double PI = acos(-1.0);
int n, k;
struct Point{
	long double x, y, ang, dis;
}p[N];
long double t[2 * N];
struct Node{
	long double pos;
	int op;
}no[N];
inline bool check(long double R){
	int m = 0;
	for(int i = 1; i <= n; i++){
		if(p[i].dis >= 2 * R) continue;
		else{
			long double the = acos(0.5 * p[i].dis / R);
			long double l = -the + p[i].ang, r = the + p[i].ang;
			if(-PI <= l && r <= PI){
				no[++m] = {l, 1};
				no[++m] = {r, -1};
			}
			else if(l < -PI){
				
				no[++m] = {-PI, 1};
				no[++m] = {r, -1};
				no[++m] = {l + 2 * PI, 1};
				no[++m] = {PI, -1};
			}
			else{
				no[++m] = {l, 1};
				no[++m] = {PI, -1};
				no[++m] = {-PI, 1};
				no[++m] = {r - 2 * PI, -1};
			}
		}
	}
	sort(no + 1, no + m + 1, [&](const Node &a, const Node &b){
		return a.pos < b.pos;
	});
	int sum = 0;
	for(int i = 1; i <= m; i++){
		sum += no[i].op;
		if(sum >= k) return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	int ncnt = 0;
	for(int i = 1; i <= n; i++){
		int x, y; cin >> x >> y;
		if(x == 0 && y == 0) k--;
		else{
			ncnt++;
			p[ncnt].x = x; p[ncnt].y = y;
			p[ncnt].ang = atan2(p[ncnt].y, p[ncnt].x);
			p[ncnt].dis = hypot(p[ncnt].x, p[ncnt].y);
		}
	}
	n = ncnt;
	if(k <= 0){
		cout << "0.000000000\n";
		return 0;
	}
	long double l = 0, r = 200000, mid;
	while(r - l >= 1e-8){
		mid = 0.5 * (l + r);
		if(check(mid)) r = mid;
		else l = mid;
	}
	cout << fixed << setprecision(14) << l << '\n';
	return 0;
}