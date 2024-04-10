#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<deque>
#include<utility>

using namespace std;

typedef long long ll;

const int INF = 1e9 + 7;
const int MAXN = 3e5 + 20;

int n, a[MAXN];
int g[4 * MAXN];
vector<int>	ans, sec;

void build(int v, int b, int e){
	if (e - b == 1){
		g[v] = a[b];
		return;
	}

	int mid = (b + e)/ 2;
	build(v<<1, b, mid);
	build(v<<1^1, mid, e);
	g[v] = __gcd(g[v<<1], g[v<<1^1]);
}

int get_g(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)
		return	g[v];
	if (r <= b || e <= l)
		return	0;

	int mid = (b + e)/ 2;
	int f = get_g(v<<1, b, mid, l, r);
	int g = get_g(v<<1^1, mid, e, l, r);
	if (f == 0)
		return	g;
	if (g == 0)
		return	f;
	return	__gcd(f, g);
}

bool ok(int x, bool t = 1){
	deque<pair<int, int>>	q;
	for (int i = 0; i < x - 1; i++){
		while (q.size() && q.back().first >= a[i])
			q.pop_back();
		q.push_back({a[i], i});
	}

	for (int i = x - 1; i < n; i++){
		while (q.size() && q.back().first >= a[i])
			q.pop_back();
		q.push_back({a[i], i});
		if (q.front().second <= i - x)	q.pop_front();
		int mini = q.front().first;
		if (get_g(1, 0, n, i - x + 1, i + 1) % mini == 0){
			if (t)
				return	true;
			else
				sec.push_back(i - x + 1);
		}
	}
	return	(int)sec.size();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	build(1, 0, n);

	for (int i = 0; i < n; i++)
		ans.push_back(i);
	int b = 1, e = n, ret = 1;
	while (b <= e){
		int mid = (b + e)/ 2;
		sec.clear();
		if (ok(mid)){
			ans.assign(sec.begin(), sec.end());
			b = mid + 1;
			ret = mid;
		}
		else	e = mid - 1;
	}
	sec.clear();
	ok(ret, 0);
	ans.assign(sec.begin(), sec.end());
	cout << (int)ans.size() << " " << ret - 1 << endl;
	for (int v:ans)
		cout << v + 1 << " ";
	cout << endl;
	return 0;
}