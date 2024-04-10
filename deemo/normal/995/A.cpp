#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second
#define next klajsdf

const int MAXN = 100 + 10;

int n, k, a[4][MAXN];
vector<pair<int, pii>> ans;

pii next(pii cur){
	if (cur.F == 1){
		if (cur.S < n-1)
			cur.S++;
		else
			cur = {2, n-1};
	}
	else{
		if (cur.S)
			cur.S--;
		else
			cur = {1, 0};
	}
	return cur;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int w = 0; w < 4; w++)
		for (int i = 0; i < n; i++)
			cin >> a[w][i];
	if (k == 2*n){
		bool ok = false;
		for (int i = 0; i < n; i++) {
			ok |= a[1][i] && a[1][i] == a[0][i];
			ok |= a[2][i] && a[2][i] == a[3][i];
		}
		if (!ok){
			cout << "-1\n";
			return 0;
		}
	}

	int rem = k;
	do{
		for (int i = 0; i < n; i++){
			if (a[1][i] && a[1][i] == a[0][i]){
				ans.push_back({a[1][i], {0, i}});
				a[1][i] = a[0][i] = 0;
				rem--;
			}
			if (a[2][i] && a[2][i] == a[3][i]){
				ans.push_back({a[2][i], {3, i}});
				a[2][i] = a[3][i] = 0;
				rem--;
			}
		}

		bool found = false;
		for (int w = 1; !found && w < 3; w++)
			for (int i = 0; !found && i < n; i++)
				if (a[w][i] == 0){
					pii cur(w, i);
					for (int t = 0; t < 2*n-1; t++){
						pii nxt = next(cur);
						if (a[nxt.F][nxt.S]){
							ans.push_back({a[nxt.F][nxt.S], {cur.F, cur.S}});
							a[cur.F][cur.S] = a[nxt.F][nxt.S];
							a[nxt.F][nxt.S] = 0;
						}
						cur = nxt;
					}
					found = true;
				}
	}while (rem);

	cout << ans.size() << "\n";
	for (auto &x:ans)
		cout << x.F << " " << x.S.F+1 << " " << x.S.S+1 << "\n";
	return 0;
}