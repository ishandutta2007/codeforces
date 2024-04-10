#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
#define mp make_pair
#define db double
#define pb push_back
#define all(a) a.begin(), a.end()
int n, m, k, q;
vector<int> leftest, rightest;
const int INF = 1e9;
int highest = -1;
vector<int> good;
int bs(int x){
	int L = -1, R = good.size();
	while (R-L>1){
		int M = (L+R)/2;
		if (good[M] >= x) R = M;
		else L = M;
	}
	return R;
}
void solve(int lvl, vector<pair<int, int> > var){
	if (leftest[lvl] == INF){
		for (int i=0; i < var.size(); i++){
			var[i].second++;
		}
		solve(lvl+1, var);
		return;
	}
	int A = 1e18, B = 1e18;
	for (int i=0; i < var.size(); i++){
		int C = var[i].first, cost = var[i].second;
		A = min(A, abs(C-rightest[lvl]) + abs(rightest[lvl] - leftest[lvl]) + cost);
		B = min(B, abs(C-leftest[lvl]) + abs(rightest[lvl] - leftest[lvl]) + cost);
	}
	if (lvl == highest){
		cout << min(A, B);
		exit(0);
	}
	vector<pair<int, int> > new_var;
	int pos = bs(leftest[lvl]);
	if (pos < q) new_var.push_back({good[pos], A + 1 + abs(good[pos] - leftest[lvl])});
	if (pos > 0) new_var.push_back({good[pos-1], A + 1 + abs(good[pos-1] - leftest[lvl])});
	pos = bs(rightest[lvl]);
	if (pos < q) new_var.push_back({good[pos], B + 1 + abs(good[pos] - rightest[lvl])});
	if (pos > 0) new_var.push_back({good[pos-1], B + 1 + abs(good[pos-1] - rightest[lvl])});
	solve(lvl+1, new_var);
}
main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k >> q;
    leftest.assign(n, INF);
    rightest.assign(n, -INF);
    for (int i=0; i < k; i++){
    	int x, y;
    	cin >> x >> y;
    	x--, y--;
    	leftest[x] = min(leftest[x], y);
    	rightest[x] = max(rightest[x], y);
    	highest = max(highest, x);
    }
    leftest[0] = 0;
    rightest[0] = max(rightest[0], 0LL);
    good.assign(q, -1);
    for (int i=0; i < q; i++){
    	cin >> good[i];
    	good[i]--;
    }
    sort(good.begin(), good.end());
    vector<pair<int, int> > t = {{0, 0}};
    solve(0, t);
}