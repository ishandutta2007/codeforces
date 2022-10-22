#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const ll INF = 1e9;

int n, a, b, sec[MAXN], sz, ans = 1e9;
pii vec[MAXN];
vector<int> mm[MAXN];

void go(ll x, ll y, int cur = 0, int us = 0){
	if (cur == sz) return;
	if (us >= ans) return;
	
	for (int t1 = 0; t1 <= vec[cur].S; t1++){
		ll yy = y*mm[cur][vec[cur].S-t1];
		if (x >= a && yy >= b)
			ans = min(ans, us+(vec[cur].S-t1));
		else if (mm[cur][vec[cur].S-t1] < INF)
			go(x, yy, cur+1, us+(vec[cur].S-t1));

		if (x < a)
			x *= vec[cur].F, us++;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w;
	cin >> a >> b >> h >> w >> n;
	for (int i = 0; i < n; i++) cin >> sec[i];
	sort(sec, sec + n);
	reverse(sec, sec + n);
	for (int l = 0; l < n;){
		int r = l;
		while (r < n && sec[l] == sec[r]) r++;

		int t = min(r-l, 35);
		{
			mm[sz].resize(t+1);
			mm[sz][0] = 1;
			for (int i = 1; i <= t; i++)
				mm[sz][i] = min(INF, 1ll*mm[sz][i - 1]*sec[l]);
		}
		vec[sz++] = {sec[l], t};
		l = r;
	}
	
	if ((h >= a && w >= b) || (h >= b && w >= a)){
		cout << "0\n";
		return 0;
	}
	go(h, w);
	go(w, h);
	
	if (ans > 1e7)
		ans = -1;
	cout << ans << "\n";
	return 0;
}