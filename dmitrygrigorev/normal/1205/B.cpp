#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9;
vector<int> used;
vector<vector<int> > data;
signed main() {
	#ifdef LOCAL
		freopen("H_input.txt", "r", stdin);
		//freopen("C_output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    vector<int> how(62);
	fill(how.begin(), how.end(), 0);
	for (int i=0; i < n; i++){
		for (int j=0; j < 62; j++){
			int ba = (1LL<<j)&v[i];
			if (ba != 0) how[j]++;
		}
	}
	for (int j=0; j < 62; j++) if (how[j] >= 3){
		cout << 3;
		return 0;
	}
	vector<int> real;
	for (int i=0; i< n;i++) if (v[i] != 0) real.push_back(v[i]);
	n = real.size();
	v = real;
	if (n==0){
		cout << -1;
		return 0;
	}
	int ans = INF;
	data.assign(n, {});
	for (int i=0; i < n; i++) for (int j=i+1; j < n; j++){
		int T = v[i] & v[j];
		if (T!=0){
			data[i].push_back(j);
			data[j].push_back(i);
		}
	}
	for (int i=0; i < n; i++) for (int T=0; T < data[i].size(); T++){
		int j = data[i][T];
		used.assign(n, INF);
		used[i] = 0;
		queue<int> q;
		q.push(i);
		while (q.size()){
			int V = q.front();
			q.pop();
			if (V==j){
				ans = min(ans, used[j]);
				break;
			}
			for (int e=0; e < data[V].size(); e++){
				int to = data[V][e];
				if (V==i && to==j) continue;
				if (used[to] != INF) continue;
				used[to] = used[V]+1;
				q.push(to);
			}
		}
	}
	if (ans==INF){
		cout <<-1;
		return 0;
	}
	cout << ans+1;
}