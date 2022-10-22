#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, par[MAXN], depth[MAXN];
ll sm;

ll get(int d){
	ll cap = 1, cur = 1, ret = 0;
	for (int l = 0; l < n; cur++){
		int r = min((ll)n, l + cap);
		
		ll cnt = (r-l);
		ret += cnt*cur;

		cap *= d;

		l = r;
	}
	return ret;
}

vector<int> vec[MAXN];
int deg[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> sm;
	if (sm > 1ll*n*(n+1)/ 2)
		cout << "No\n";
	else if (sm < n + (n-1))
		cout << "No\n";
	else{
		int lo = 0, hi = n-1;
		while (hi-lo>1){
			int mid = hi+lo>>1;
			if (get(mid) <= sm)
				hi = mid;
			else
				lo = mid;
		}

		iota(par, par + n, -1);
		iota(depth, depth + n, 0);
		for (int i = 0; i < n; i++) vec[i].push_back(i);
		for (int i = 0; i < n-1; i++) deg[i] = 1;

		ll cur = 1ll*n*(n+1)/ 2;
		int h = 0;
		for (int j = n-1; j && cur > sm; j--){
			int v = vec[j].back();
			vec[j].pop_back();

			if (j - (h+1) > cur-sm)
				h = -(cur-sm-j+1);

			while (true){
				int p = vec[h].back();
				if (deg[p] == hi)
					vec[h].pop_back();
				else{
					deg[p]++;
					deg[par[v]]--;
					par[v] = p;
					vec[h+1].push_back(v);
					break;
				}
				if (vec[h].empty()) h++;
			}

			cur -= j - (h + 1);
		}

		cout << "Yes\n";
		for (int i = 1; i < n; i++)
			cout << par[i]+1 << " ";
		cout << "\n";
	}
	return 0;
}