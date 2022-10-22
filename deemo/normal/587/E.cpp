//You're uninvited....
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 2e5 + 10;
const int C = 30 + 1;

int n, a[MAXN], fen[MAXN];
vector<int>	weed[4 * MAXN], nl;

void xr(int v, int x){for (v++; v<MAXN; v+=v&-v) fen[v]^=x;}
int getVal(int v){int ret = 0; for (; v; v-=v&-v) ret^=fen[v]; return ret;}
int getA(int v){return a[v]^getVal(v+1);}

void mix(vector<int> &vec){
	int sz = vec.size();
	int cur = 0;
	for (int i = C-1; ~i && cur < sz; i--){
		int ind = max_element(vec.begin()+cur, vec.end()) - vec.begin();
		swap(vec[cur], vec[ind]);
		if (vec[cur]>>i&1){
			for (int j = 0; j < sz; j++)
				if (j^cur && vec[j]>>i&1)
					vec[j]^=vec[cur];
			cur++;
		}
	}
	while (vec.size() && !vec.back())	vec.pop_back();
}

vector<int>	sprout(vector<int> a, vector<int> b){
	vector<int>	ret;
	ret.reserve(a.size() + b.size());
	for (auto x:a)	ret.push_back(x);
	for (auto x:b)	ret.push_back(x);
	mix(ret);
	return ret;
}

void plant(int v, int b, int e){
	if (e - b == 1){
		if (b)
			weed[v].push_back(a[b]^a[b-1]);
		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	weed[v] = sprout(weed[v<<1], weed[v<<1^1]);
}

void water(int v, int b, int e, int pos, int val){
	if (e-b==1){
		weed[v].clear();
		weed[v].push_back(val);
		return;
	}

	int mid = b + e >> 1;
	if (pos < mid)
		water(v<<1, b, mid, pos, val);
	else
		water(v<<1^1, mid, e, pos, val);
	weed[v] = sprout(weed[v<<1], weed[v<<1^1]);
}

vector<int>	smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return weed[v];
	if (r <= b || e <= l)	return nl;

	int mid = b+e>>1;
	return sprout(smoke(v<<1, b, mid, l, r), smoke(v<<1^1, mid, e, l, r));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;	cin >> n >> q;
	for (int i = 0; i < n; i++)	cin >> a[i];
	plant(1, 0, n);

	while (q--){
		int type;	cin >> type;
		if (type - 1){
			int l, r;	cin >> l >> r, l--;
			vector<int>	vec = smoke(1, 0, n, l+1, r);
			vec.push_back(getA(l));
			mix(vec);
			cout << (1<<(int)vec.size()) << "\n";
		}
		else{
			int l, r, x;	cin >> l >> r >> x, l--;
			xr(l, x), xr(r, x);
			if (l)
				water(1, 0, n, l, getA(l-1)^getA(l));
			if (r<n)
				water(1, 0, n, r, getA(r-1)^getA(r));
		}
	}
	return 0;
}