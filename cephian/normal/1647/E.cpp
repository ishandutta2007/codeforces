#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5+5;
const int BITS = 31;
int func[N][BITS];
int fin[N];
int n;

inline int calc_no_in() {
	vector<bool> has_in(n+1, false);
	for(int i = 1; i <= n; ++i)
		has_in[func[i][0]] = true;
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += !has_in[i];
	return ans;
}

inline ll calc_iterations() {
	const int no_in = calc_no_in();
	int max_fin = 0;
	for(int i = 1; i <= n; ++i)
		max_fin = max(max_fin, fin[i]);
	return (max_fin-n)/no_in;
}

inline void fill_func() {
	for(int j = 1; j < BITS; ++j)
		for(int i = 1; i <= n; ++i)
			func[i][j] = func[func[i][j-1]][j-1];
}

int apply_func(int x, ll amt) {
	for(int i = BITS-1; i >= 0; --i) {
		if(amt&(1<<i))
			x = func[x][i];
	}
	return x;
}

int ans[N];

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> func[i][0];
	for(int i = 1; i <= n; ++i)
		cin >> fin[i];

	fill_func();
	int iter = calc_iterations();
	fill(ans, ans+n+1, -1);
	map<int, vector<int>> preimage;
	for(int i = 1; i <= n; ++i) {
		const int f_app = apply_func(i, iter);
		preimage[f_app].push_back(i);
	}

	set<int> left;
	for(int i = 1; i <= n; ++i)
		left.insert(i);

	vector<pair<int,int>> to_assign;
	set<int> pq;
	for(auto& p : preimage) {
		vector<int>& v = p.second;
		sort(v.begin(), v.end());
		ans[v[0]] = fin[p.first];
		left.erase(ans[v[0]]);
		for(int i = 1; i < v.size(); ++i)
			to_assign.emplace_back(fin[p.first], v[i]);
	}

	sort(to_assign.begin(), to_assign.end());
	int ind = 0;
	for(int x : left) {
		while(ind < to_assign.size() && to_assign[ind].first <= x) {
			pq.insert(to_assign[ind].second);
			++ind;
		}

		ans[*pq.begin()] = x;
		pq.erase(pq.begin());
	}
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	cout << endl;
}