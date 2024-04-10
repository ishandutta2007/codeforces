#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second
#define X first
#define Y second

const int MAXN = 1e5 + 10;
const ld LIM = 1e12*2.25;

int n, ans[MAXN];
pii a[MAXN];
vector<int> vec;

int getSide(pii v){
	if (v.X > 0 && v.S >= 0) return 0;
	if (v.X <= 0 && v.S > 0) return 1;
	if (v.X < 0 && v.S <= 0) return 2;
	return 3;
}

pii rev(pii v){
	return {-v.X, -v.Y};
}

pii sm(pii v1, pii v2){return {v1.X + v2.X, v1.Y + v2.Y};}

bool ok(pii p){
	return 1ll*p.X*p.X + 1ll*p.Y*p.Y < LIM;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].X >> a[i].Y, ans[i] = 1;
	pii p1(0, 0), p2(0, 0);
	for (int i = 0; i < n; i++){
		int t1 = getSide(p1), t2 = getSide(a[i]);
		if (t1%2 == t2%2){
			if (t1 == t2)
				ans[i] = -1, a[i] = rev(a[i]);
			p1 = sm(p1, a[i]);
		}
		else{
			t1 = getSide(p2);
			if (t1 == t2)
				ans[i] = -1, a[i] = rev(a[i]);
			p2 = sm(p2, a[i]);
			vec.push_back(i);
		}

		t1 = getSide(p1), t2 = getSide(p2);
		if (t1%2 == t2%2){
			if (t1 == t2){
				for (auto x:vec){
					ans[x] = -ans[x];
					a[x] = rev(a[x]);
				}
				p2 = rev(p2);
			}
			p1 = sm(p1, p2);
			p2 = {0, 0};
			vec.clear();
		}
	}
	if (!ok(sm(p1, p2))){
		for (auto x:vec){
			ans[x] = -ans[x];
			a[x] = rev(a[x]);
		}
		p2 = rev(p2);
	}
	assert(ok(sm(p1, p2)));
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}