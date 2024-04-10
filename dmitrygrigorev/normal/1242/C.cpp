#include <bits/stdc++.h>
#define db long double
#define int long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1e18;

int can[1<<15];
int relax[1<<15];
vector<bool> used;
map<int, int> tet;

vector<pair<int, int> > res;

void dfs(int mask, map<int, int> &kek, int sum, vector<int> &sums, int n){
	if (can[mask] == -INF){
		dfs(relax[mask], kek, sum, sums, n);
		dfs(mask^relax[mask], kek, sum, sums, n);
		return;
	}
	if (can[mask] < -INF){
		//cout << "!!! " << can[mask]+INF;
		int T = -(can[mask] + INF) - 1;
		//cout << T << endl;
		//exit(0);
		res[T] = {tet[T], T};
		return;
	}
	int val = can[mask], start = kek[can[mask]];
	used.assign(n, false);
	used[start] = true;
	bool good = true;
	int cur = start, cval = val;
	while (true){
		int need = sum - (sums[cur] - cval);
		if (!kek.count(need)){
			break;
		}
		int A = kek[need];
		if (!used[A]){
			res[A] = {need, cur};
			cur = A, cval = need;
			used[A] = true;
			continue;
		}
		else{
			res[A] = {need, cur};
			break;
		}
	}

}

main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i=0; i < (1<<n); ++i){
		can[i] = -INF;
		relax[i] = -1;
	}

	vector<vector<int> > v(n);

	map<int, int> kek;
	int sum = 0;
	vector<int> sums(n, 0);

	for (int i=0; i < n; ++i){
		int x;
		cin >> x;
		for (int j=0; j < x; ++j){
			int t;
			cin >> t;
			kek[t] = i;
			sums[i] += t;
			sum += t;
			tet[i] = t;
		}
	}

	if (sum % n != 0){
		cout << "No";
		exit(0);
	}

	sum /= n;


	for (auto it = kek.begin(); it != kek.end(); it++){
		int val = (*it).first, start = (*it).second;
		used.assign(n, false);
		used[start] = true;
		bool good = true;
		int cur = start, cval = val;
		while (true){
			int need = sum - (sums[cur] - cval);
			if (!kek.count(need)){
				good = false;
				break;
			}
			int A = kek[need];
			if (A==cur){
				good = false;
				break;
			}
			if (!used[A]){
				cur = A, cval = need;
				used[A] = true;
				continue;
			}
			else{
				if (need != val){
					good = false;
				}
				break;
			}
		}
		if (good){
			int mask=0;
			for (int i=0;i<n;++i) if (used[i]) mask ^= (1<<i);
			can[mask] = val;
		}
	}

	for (int i=0; i < n; ++i){
		if (sums[i] == sum){
			can[1<<i] = -INF-i-1;
		}
	}



	for (int mask=0; mask < (1<<n); ++mask){
		if (can[mask] != -INF){
			relax[mask] = mask;
			continue;
		}
		int s = mask;
		while (s > 0) {
			if (relax[s]!=-1 && relax[mask^s]!=-1){
				relax[mask] = s;
				break;
			}
			s = (s-1) & mask;
		}
	}

	if (relax[(1<<n)-1] == -1){
		cout << "No";
		exit(0);
	}

	cout << "Yes\n";

	res.assign(n, {-1, -1});
	dfs((1<<n)-1, kek, sum, sums, n);

	for (int i=0;i<n;++i){
		cout << res[i].first << " " << res[i].second+1 << endl;
	}


}