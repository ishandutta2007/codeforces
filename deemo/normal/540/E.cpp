#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

ll ans = 0;
int q, sec[3 * MAXN], fen[3 * MAXN], t;
map<int, int>	pos, mp;

bool cmp(int u, int v){return	pos[u] < pos[v];}

int get(int v){
	int ret = 0;
	for (; v; v -= v & (-v))
		ret += fen[v];
	return	ret;
}

void add(int v, int val){
	for (v++; v < 2 * MAXN + 5; v += v & (-v))
		fen[v] += val;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> q;
	while (q--){
		int a, b;	cin >> a >> b;
		sec[t++] = a, sec[t++] = b;
		
		if (pos.count(a) == 0)	pos[a] = a;
		if (pos.count(b) == 0)	pos[b] = b;

		swap(pos[a], pos[b]);
	}
	
	sort(sec, sec + t);
	t = unique(sec, sec + t) - sec;
	for (int i = 0; i < t; i++)
		mp[sec[i]] = i;
	sort(sec, sec + t, cmp);
	for (int i = 0; i < t; i++){
		int v = sec[i];
		ans += get(2 * MAXN) - get(mp[v]);
		add(mp[v], 1);
	}
	
	sort(sec, sec + t);
	for (int i = 0; i < t; i++){
		int ps = pos[sec[i]], tt;
		if (ps > sec[i])
			tt = lower_bound(sec, sec + t, ps) - lower_bound(sec, sec + t, sec[i]);
		else
			tt = lower_bound(sec, sec + t, sec[i]) - lower_bound(sec, sec + t, ps);

		ans += abs(ps - sec[i]) - tt;
	}

	cout << ans << "\n";
	return	0;
}