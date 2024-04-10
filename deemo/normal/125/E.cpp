#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<cstring>
#include<ctime>
#include<iomanip>
#include<cassert>

using namespace std;

typedef long long ll;
typedef double ld;

const int MAXN = 5e3 + 10;
const int MAXE = 1e5 + 10;

int n, m, k;
int a[MAXE], b[MAXE], c[MAXE], ed[MAXE];
int par[MAXN];
bool pic[MAXE];
ld cc[MAXE];

bool cmp(int e1, int e2){return cc[e1] < cc[e2];}
int get_par(int v){return par[v]==v?v:par[v]=get_par(par[v]);}

int get(ld mid){
	for (int i = 0; i < m; i++){
		cc[i] = c[i];
		if (min(a[i], b[i]) == 0)	cc[i] += mid;
	}

	int cnt = 0, ret = 0;
	iota(ed, ed + m, 0);
	sort(ed, ed + m, cmp);
	iota(par, par + n, 0);
	memset(pic, 0, sizeof(pic));
	for (int i = 0; i < m; i++){
		int u = a[ed[i]], v = b[ed[i]];
		int pu = get_par(u), pv = get_par(v);
		if (pu == pv)	continue;

		if (min(u, v) == 0)	ret++;
		cnt++;
		par[pu] = pv;
		pic[ed[i]] = 1;
	}

	if (cnt < n - 1){
		cout << "-1\n";
		exit(0);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)	cin >> a[i] >> b[i] >> c[i], a[i]--, b[i]--;
	iota(ed, ed + m, 0);

	ld l = -1e9, r = 1e9;
	//while (clock() < CLOCKS_PER_SEC * 3){
	for (int i = 0; i < 100; i++){
		ld mid = (l+r)/2.;
		int x = get(mid);
		if (x == k){
			l = r = mid;
			break;
		}

		if (x < k)
			r = mid;
		else
			l = mid;
	}

	if (get(l) != k && get(r) != k){
		cout << "-1\n";
		return 0;
	}
	ll ans = 0;
	for (int i = 0; i < m; i++)
		if (pic[i])	ans++;
	cout << ans << "\n";
	for (int i = 0; i < m; i++)
		if (pic[i])
			cout << i + 1 << " ";
	cout << "\n";
	return 0;
}