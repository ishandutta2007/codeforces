#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, L;
int a[MAXN], b[MAXN];

int distR(int x, int y){return x <= y? y-x: L - (x-y);}
int distL(int x, int y){return distR(y, x);}
int dist(int x, int y){return min(distL(x, y), distR(x, y));}

bool cmp(int y1, int y2){return distR(a[0], y1) < distR(a[0], y2);}

int prv(int x){return x == 0? n-1: x-1;}
int nxt(int x){return x+1==n? 0: x+1;}

bool ok(int lim){
	int tr = 0;
	while (tr < n && distR(a[0], b[tr]) <= lim) tr++;
	if (tr == 0) return false;

	int tl = 0;
	for (int i = 1; i < n && tl < tr; i++){
		int mt = i + tl;
		if (mt >= n) mt -= n;
		while (dist(a[i], b[mt]) > lim && tl < tr){
			tl++;
			mt = nxt(mt);
		}
	}
	for (int i = 1; i < n; i++){
		int mt = i + tl;
		if (mt >= n) mt -= n;
		if (dist(a[i], b[mt]) > lim) return false;
	}
	return tl < tr;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> L;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(b, b + n, cmp);

	int ans = 1e9;
	for (int w = 0; w < 2; w++) {
		int lo = -1, hi = L/2;
		while (hi-lo>1){
			int mid = hi+lo>>1;
			if (ok(mid))
				hi = mid;
			else
				lo = mid;
		}
		ans = min(ans, hi);

		if (!w){
			for (int i = 0; i < n; i++) a[i] = (a[i]? L - a[i]: 0);
			int temp = a[0];
			for (int i = 0; i < n; i++)
				a[i] = (a[i] - temp + L) % L;
			sort(a, a + n);
			for (int i = 0; i < n; i++) b[i] = (b[i]? L - b[i]: 0), b[i] = (b[i] - temp + L) % L;
			sort(b, b + n, cmp);
		}
	}
	cout << ans << "\n";
	return 0;
}