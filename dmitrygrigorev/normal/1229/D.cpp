#include <bits/stdc++.h>
#define int long long
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int mult[120][120];

map<vector<int>, int> A;
map<int, vector<int> > B;

void gen(){
	vector<int> q;
	for (int i=0;i<5;++i) q.push_back(i);
	int ptr=0;
	do{
		A[q] = ptr;
		B[ptr] = q;
		ptr++;
	}
	while (next_permutation(q.begin(), q.end()));
}

main(){
	#ifdef LOCAL
	    freopen("H_input.txt", "r", stdin);
	    //freopen("B_output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> arr;
	gen();
	for (int i=0; i < n; ++i){
		vector<int> v;
		for (int i=0;i<k;++i){
			int x;
			cin >> x;
			x--;
			v.push_back(x);
		}
		while (v.size() < 5){
			int Q = v.size();
			v.push_back(Q);
		}
		arr.push_back(A[v]);
	}

	for (int i=0;i<120;++i) for (int j=0; j < 120;++j){
		vector<int> pa = B[i], pb = B[j];
		vector<int> go(5);
		for (int e=0; e < 5; ++e) go[e] = pb[pa[e]];
		mult[i][j] = A[go];
	}


	vector<int> closest(120, -1);

	ll ans = 0;

	set<pair<int, int> > now;


	for (int i=n-1; i >= 0; i--){
		if (now.count({closest[arr[i]], arr[i]})){
			now.erase(now.find({closest[arr[i]], arr[i]}));
		}
		closest[arr[i]] = i;
		now.insert({closest[arr[i]], arr[i]});
		vector<bool> has(120, false);
		has[0] = true;
		vector<int> cur = {0};
		int start = i;
		vector<int> base;
		for (auto it = now.begin(); it != now.end(); it++){
			pair<int, int> Q = (*it);
			int index = Q.first, perm = Q.second;
			if (has[perm]) continue;
			base.push_back(perm);
			int was = cur.size();
			while (true){
				int len = cur.size();
				for (int e=0; e < base.size(); e++){
					int P = base[e];
					for (int j=0; j < len; ++j){
						int T = mult[cur[j]][P];
						if (!has[T]){
							has[T] = true, cur.push_back(T);
						}
						T = mult[P][cur[j]];
						if (!has[T]){
							has[T] = true, cur.push_back(T);
						}
					}
				}
				if (cur.size() == len) break;
			}
			int delta = index-start;
			ans += (ll) delta * (ll) was;
			start = index;
		}
		ans += (ll) (n-start) * (ll) (cur.size());
	}

	cout << ans;

}