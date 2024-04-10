#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;

#define F first
#define S second

const int MAXVAL = 5e6 + 50e3;
const int MAXN = 2e5 + 10;
const int MAXQ = 1e6 + 55e3;
const int INF = 1e8;

int n, q, a[MAXN];
int tl[MAXQ], tr[MAXQ], sec[MAXQ], ans[MAXQ];
bool mark[MAXVAL], mark2[MAXVAL];
int cnt[MAXVAL];
vector<int> vec[MAXVAL];
int svMask[MAXN], svMaskFirst[MAXN];

bool cmp(int q1, int q2){return tr[q1] < tr[q2];}

int seg[MAXN<<2];
int curMn[MAXN];
void upd(int v, int b, int e, int pos, int val){
	if (e - b == 1){
		seg[v] = curMn[b] = val;
		return;
	}

	int mid = b + e >> 1;
	if (pos < mid)
		upd(v<<1, b, mid, pos, val);
	else
		upd(v<<1^1, mid, e, pos, val);
	seg[v] = min(seg[v<<1], seg[v<<1^1]);
}

int get(int v, int b, int e, int l, int r){
	if (l <= b && e <= r) return seg[v];
	if (r <= b || e <= l) return INF;

	int mid = b + e >> 1;
	return min(get(v<<1, b, mid, l, r), get(v<<1^1, mid, e, l, r));
}

ull hs[MAXN];
vector<pii> mpVec[MAXVAL];

void updPosAns(int pos){
	int val = a[pos];
	int sz = vec[val].size();
	for (int mask = 0; mask < 1<<sz; mask++){
		if (mask)
			hs[mask] = hs[mask^1<<svMaskFirst[mask]]*vec[val][svMaskFirst[mask]];
		else
			hs[mask] = 1;

		int _hs = hs[mask];
		if (mpVec[_hs].size()){
			int t = sz - svMask[mask];
			auto &v = mpVec[_hs];
			for (auto x:v) 
				if (curMn[x.S] > t+x.F)
					upd(1, 0, n, x.S, t + x.F);
				//cout << val << " " << mask << "   " << t << "  " << x.F << "  " << x.S << endl;
		}
	}
}

void addPos(int pos){
	int val = a[pos];
	int sz = vec[val].size();
	for (int mask = 0; mask < 1<<sz; mask++){
		int _hs = hs[mask];
		auto &v = mpVec[_hs];
		pii cur(sz - svMask[mask], pos);

		while (v.size() && v.back().F >= cur.F) v.pop_back();
		v.push_back(cur);
	}
}

void findAns(int qu){
	ans[qu] = get(1, 0, n, tl[qu], tr[qu]);
	//cout << qu << "   " << ans[qu] << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(curMn, 63, sizeof(curMn));
	for (int i = 0; i < MAXN; i++){
		svMask[i] = __builtin_popcount(i);
		if (i){
			svMaskFirst[i] = 0;
			while (!(i>>svMaskFirst[i]&1)) svMaskFirst[i]++;
		}
	}
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i], mark2[a[i]] = true;

	for (int i = 2; i < MAXVAL; i++)
		if (!mark[i]) {
			for (int j = i; j < MAXVAL; j += i){
				mark[j] = true;
				if (!mark2[j]) continue;

				int temp = j, cur = 0;
				while (temp % i == 0){
					temp /= i;
					cur ^= 1;
				}
				if (cur)
					cnt[j]++;
			}
		}
	for (int i = 0; i < MAXVAL; i++) vec[i].resize(cnt[i]);
	memset(mark, 0, sizeof(mark));
	for (int i = 2; i < MAXVAL; i++)
		if (!mark[i]) {
			for (int j = i; j < MAXVAL; j += i){
				mark[j] = true;
				if (!mark2[j]) continue;

				int temp = j, cur = 0;
				while (temp % i == 0){
					temp /= i;
					cur ^= 1;
				}
				if (cur)
					vec[j][--cnt[j]] = i;
			}
		}

	for (int i = 0; i < q; i++) cin >> tl[i] >> tr[i], tl[i]--;
	iota(sec, sec + q, 0);
	sort(sec, sec + q, cmp);
	memset(seg, 63, sizeof(seg));
	
	int cur = 0;
	for (int i = 0; cur < q && i < n; i++){
		updPosAns(i);
		while (cur < q && tr[sec[cur]] == i+1)
			findAns(sec[cur++]);
		addPos(i);
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] << "\n";
	return 0;
}