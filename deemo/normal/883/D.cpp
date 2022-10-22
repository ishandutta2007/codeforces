
//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int MAXN = 2e6 + 10;

int n, p[MAXN], sec[MAXN], pt[MAXN];
string s;
int nxt[MAXN], prv[MAXN];
int d[MAXN][2];

bool ok(int mid, int sz){\
	memset(d, 0, sizeof(d));
	d[0][0] = d[0][1] = 1;
	for (int i = 1; i <= n; i++){
		if (s[i-1] == '.')
			d[i][0] = d[i-1][0];
		else if (s[i-1] == 'P')
			d[i][0] = d[i-1][1];
		else{
			int xx = prv[i-1];
			if (~xx && xx + mid >= i-1){
				d[i][0] |= d[xx][0];
				int temp = prv[xx];
				if (~temp && temp + mid >= i-1) {
					int t = max(0, xx - mid);
					int temp2 = 0;
					if (t && nxt[t-1] < temp)
						temp2 = 1;
					d[i][0] |= d[t][temp2];
				}
			}
		}

		int xx = nxt[i-1];
		if (xx < n){
			int temp = max(0, xx-mid);
			temp = min(temp, i);
			int temp2 = 0;
			if (temp && nxt[temp-1] < xx)
				temp2 = 1;
			d[i][1] |= d[temp][temp2];
		}
	}
	return d[n][0];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	int sz = 0, c = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == 'P')
			sec[sz++] = i;
		else if (s[i] == '*')
			c++;
	int mn = 1e9, mx = -1;
	for (int i = 0; i < n; i++) {
		p[i+1] = p[i];
		if (s[i] == '*'){
			p[i+1]++;
			mn = min(mn, i);
			mx = max(mx, i);
		}
	}
	int last = n;
	for (int i = n-1; ~i; i--){
		nxt[i] = last;
		if (s[i] == 'P')
			last = i;
	}
	last = -1;
	for (int i = 0; i < n; i++){
		prv[i] = last;
		if (s[i] == 'P')
			last = i;
	}
	memcpy(pt, p, sizeof(p));
	if (sz == 1){
		if (mn > sec[0])
			cout << c << " " << mx-sec[0] << "\n";
		else if (mx < sec[0])
			cout << c << " " << sec[0]-mn << "\n";
		else{
			if (p[sec[0]] > c - p[sec[0]])
				cout << p[sec[0]] << "  " << sec[0]-mn << "\n";
			else if (p[sec[0]] < c - p[sec[0]])
				cout << c-p[sec[0]] << " " << mx-sec[0] << "\n";
			else
				cout << p[sec[0]] << " " << min(sec[0]-mn, mx - sec[0]) << "\n";
		}
	}
	else{
		int lo = 0, hi = n-1;
		while (hi-lo>1){
			int mid = hi+lo>>1;
			if (ok(mid, sz))
				hi = mid;
			else
				lo = mid;
		}
		cout << c << " " << hi << "\n";
	}
	return 0;
}