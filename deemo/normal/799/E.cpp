#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, m, k, p[MAXN], mask[MAXN];
vector<int> vec[4];
ll ans = 1e18, pt[4][MAXN], ptr[4];
priority_queue<int> pqG;
priority_queue<int, vector<int>, greater<int>> pqS;

bool cmp(int u, int v){return p[u] < p[v];}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)	cin >> p[i];
	{
		int t;	cin >> t;
		while (t--){
			int x;	cin >> x, x--;
			mask[x] |= 1;
		}
	}
	{
		int t;	cin >> t;
		while (t--){
			int x;	cin >> x, x--;
			mask[x] |= 2;
		}
	}
	for (int i = 0; i < n; i++)
		vec[mask[i]].push_back(i);
	for (int i = 0; i < 4; i++){
		sort(vec[i].begin(), vec[i].end(), cmp);
		for (int j = 0; j < vec[i].size(); j++)
			pt[i][j + 1] = pt[i][j] + p[vec[i][j]];
		ptr[i] = vec[i].size();
	}
	for (int i = 0; i < vec[0].size(); i++) pqS.push(p[vec[0][i]]);

	ll sm = 0;
	for (int t = 0; t <= m && t <= vec[3].size(); t++){
		ll ret = pt[3][t];
		
		int remLike = max(0, k-t);
		for (int w = 1; w < 3; w++)
			while (ptr[w] && ptr[w] > remLike)
				pqS.push(p[vec[w][--ptr[w]]]);
		ret += pt[1][remLike] + pt[2][remLike];
		if (remLike*2 + t > m) continue;

		int rem = m - t - remLike*2;
		while (pqS.size() && pqG.size() && pqG.top() > pqS.top()){
			int x = pqS.top();
			pqS.pop();
			sm += x;
			pqG.push(x);
		}
		if (min(vec[1].size(), vec[2].size()) < remLike) continue;
		while (pqG.size() > rem){
			int x = pqG.top();
			pqG.pop();
			sm -= x;
			pqS.push(x);
		}
		while (pqG.size() < rem && pqS.size()){
			int x = pqS.top();
			pqS.pop();
			sm += x;
			pqG.push(x);
		}

		if (pqG.size() == rem)
			ans = min(ans, ret+sm);
	}
	
	if (ans > 1e17)
		cout << "-1\n";
	else
		cout << ans << "\n";
	return 0;
}