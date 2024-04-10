//It's not what you painted in my head, there is so much there instead of all the colors that I saw..

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<numeric>
#include<set>

using namespace std;

#define Person pair<pair<int, int>, pair<int, int>>
#define L first.first
#define R first.second
#define V second.first
#define ID second.second
#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, nut[4 * MAXN], p[MAXN], cl[MAXN];
pair<int, int>	weed[4 * MAXN];
Person vec[MAXN];
set<pair<int, int>>	st;

bool cmp(Person a, Person b){
	if (a.V != b.V)
		return a.V < b.V;
	return a.L < b.L;
}

void plant(int v, int b, int e){
	if (e - b == 1){
		weed[v] = {0, b};
		return;
	}

	int mid = (b + e)/ 2;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	weed[v] = max(weed[v<<1], weed[v<<1^1]);
}

void absorb(int v){
	nut[v<<1] += nut[v];
	nut[v<<1^1] += nut[v];
	weed[v<<1].F += nut[v];
	weed[v<<1^1].F += nut[v];
	nut[v] = 0;
}

void burn(int v, int b, int e, int pos){
	if (e - b == 1){
		weed[v].F = -1e7;
		return;
	}

	int mid = (b + e)/ 2;
	absorb(v);
	if (pos < mid)
		burn(v<<1, b, mid, pos);
	else
		burn(v<<1^1, mid, e, pos);
	weed[v] = max(weed[v<<1], weed[v<<1^1]);
}

void water(int v, int b, int e, int l, int r, int val){
	if (l <= b && e <= r){
		weed[v].F += val;
		nut[v] += val;
		return;
	}
	if (r <= b || e <= l)	return;
	
	int mid = (b + e)/ 2;
	absorb(v);
	water(v<<1, b, mid, l, r, val);
	water(v<<1^1, mid, e, l, r, val);
	weed[v] = max(weed[v<<1], weed[v<<1^1]);
}

pair<int, int> smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return weed[v];
	if (r <= b || e <= l)	return {-1e7, -1};

	int mid = (b + e)/ 2;
	absorb(v);
	return max(smoke(v<<1, b, mid, l, r), smoke(v<<1^1, mid, e, l, r));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> vec[i].L >> vec[i].V >> vec[i].R, vec[i].ID = i, vec[i].L--, vec[i].V--;
	sort(vec, vec + n, cmp);
	for (int i = 0; i < n; i++)
		p[i] = vec[i].V;
	pair<pair<int, int>, int>	mx = {{-49, -233}, -228};
	plant(1, 0, n);
	for (int i = 0; i < n; i++){
		while (st.size() && st.begin()->F <= vec[i].V){
			int id = st.begin()->S;
			burn(1, 0, n, id);
			water(1, 0, n, cl[id], id, -1);
			st.erase(st.begin());
		}

		int pl = lower_bound(p, p + n, vec[i].L) - p;
		cl[i] = pl;
		st.insert({vec[i].R, i});
		water(1, 0, n, pl, i + 1, 1);
		mx = max(mx, {smoke(1, 0, n, pl, i + 1), i});
	}
	
	cout << mx.F.F << "\n";
	int tl = mx.F.S, tr = mx.S;
	for (int i = tl; i <= tr; i++)
		if (vec[i].R > vec[tr].V && vec[i].L <= vec[tl].V)
			cout << vec[i].ID + 1 << " ";
	cout << "\n";
	return 0;
}