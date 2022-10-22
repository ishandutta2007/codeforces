#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

typedef long long ll;

const int LOG = 20;
const int MAXN = 1e5 + 20;

ll k;
int n;
int fen[MAXN][2];
int vec[MAXN], sec[MAXN];
map<int, int>	mp;

int get(int v, bool t = 0){
	int ret = 0;
	for (; v; v -= v & (-v))
		ret += fen[v][t];
	return	ret;
}

void add(int v, bool t = 0, int val = 1){
	for (v++; v < MAXN; v += v & (-v))
		fen[v][t] += val;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	copy(vec, vec + n, sec);
	sort(sec, sec + n);
	int sz = unique(sec, sec + n) - sec;
	for (int i = 0; i < sz; i++)	mp[sec[i]] = i;
	for (int i = 0; i < n; i++)	vec[i] = mp[vec[i]];

	ll cnt = 0;
	for (int i = n - 1; i > 0; i--){
		cnt += get(vec[i]);
		add(vec[i]);
	}
	int l = 1;
	ll ans = 0;
	for (int i = 0; i < n; i++){
		cnt += i - get(vec[i] + 1, 1);
		add(vec[i], 1);
		cnt += get(vec[i], 0);

		while (l < n && cnt > k){
			int x = vec[l++];
			cnt -= get(x, 0);
			cnt -= (i + 1) - get(x + 1, 1);

			add(x, 0, -1);
		}
		ans += n - l;

		if (i < n - 1 && l == i + 1){
			int x = vec[l++];
			cnt -= get(x, 0);
			cnt -= (i + 1) - get(x + 1, 1);

			add(x, 0, -1);
		}
	}
	cout << ans << endl;
	return 0;
}