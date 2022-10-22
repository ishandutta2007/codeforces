#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

#define Query pair<pair<ll, ll>, ll>
#define left first.first
#define right first.second
#define id second

const ll LOG = 20;
const ll SQRT = 320;
const ll MAXN = 1e5 + 5;
const ll MAXVAL = 5e6 + 100;

ll n, m, k, vec[MAXN], sec[MAXN], cn[MAXVAL], sz = 1;
Query que[MAXN];
ll cnt, ans[MAXN];
ll ss[MAXVAL];

bool cmp(Query a, Query b){
	if (a.left/SQRT != b.left/SQRT)
		return	a.left < b.left;
	return	a.right < b.right;
}

bool fl = 0;

void insert(ll x){
	ll y = x ^ k;
	if (y < MAXVAL)
		cnt += cn[y];
	cn[x]++;
}

void erase(ll x){
	cn[x]--;
	ll y = x ^ k;
	if (y < MAXVAL)
		cnt -= cn[y];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (ll i = 0; i < n; i++){
		cin >> vec[i];
		sec[i + 1] = vec[i] ^ sec[i];
	}
	
	for (ll i = 0; i < m; i++){
		cin >> que[i].left >> que[i].right;	
		que[i].left--;	que[i].right++;
		que[i].id = i;
	}
	sort(que, que + m, cmp);

	ll l = 0, r = 0;
	for (ll i = 0; i < m; i++){
		ll tl = que[i].left, tr = que[i].right;
		if (i == 1)	fl = 1;
		while (r < tr)
			insert(sec[r++]);
		while (l > tl)
			insert(sec[--l]);
		while (r > tr)
			erase(sec[--r]);
		while (l < tl)
			erase(sec[l++]);
		ans[que[i].id] = cnt;
	}

	for (ll i = 0; i < m; i++)
		cout << ans[i] << "\n";
	return	0;
}