#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int K = 500007;

int cnt[K], rcnt[K];
int cl[K];

int get(int l, int r){
	if (l > r) return 0;
	return cnt[r] - cnt[l-1];
}

int pref[K];

vector<pair<int, int> > min_remainder[K];

pair<int, int> get_opt(pair<int, int> a, pair<int, int> b){
	if (a.first > b.first) return {a.first, max(a.second, b.first)};
	return {b.first, max(b.second, a.first)};
}
const int INF = -1;

main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i=0;i<K;++i){
		 cl[i] = INF;
	}
	for (int i=0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());
	int u = 0;
	for (int i=0;i<n;++i){
		cnt[v[i]]++;
		rcnt[v[i]]++;
		cl[v[i]] = v[i];
	}
	for (int i=2; i < K; ++i){
		if (cl[i] == i) continue;
		cl[i] = cl[i-1];
	}
	for (int i=2; i < K; ++i){
		vector<pair<int, int> > min_here;
		vector<int> starts;
		for (int j=i; j < K; j += i){
			starts.push_back(j);
		}
		starts.push_back(K);
		for (int j=starts.size()-2; j >= 0; j--){
			int nxt = starts[j+1];
			int el = starts[j];
			int A = cl[nxt-1];
			if (A < el) A = INF; 
			int B = INF;
			if (A!=INF) {
				if (rcnt[A] > 1) B = A;
				else{
					B = cl[A-1];
					if (B < el) B = -1;
				}
			}
			if (A!=INF) A = A%i;
			if (B!=INF) B = B%i;
			//if (i==2005) cout << A << " " << B << endl;
			if (!min_here.size()) min_here.push_back({A, B});
			else min_here.push_back(get_opt(min_here.back(), {A, B}));
		}
		reverse(min_here.begin(), min_here.end());
		min_remainder[i] = min_here;
	}


	for (int i=1; i < K; ++i) cnt[i] += cnt[i-1];
	for (int i=2; i < K; ++i){
		int ss = 0;
		for (int j=i; j < K; j += i){
			int L = j, R = min(K-1, j+i-1);
			ss += get(L, R) * (j/i);
		}
		pref[i] = ss;
	}
	int ans = 0;
	for (int take=2; take < K; ++take){
		int tut = 0;
		int L = 1, R = K;
		while (R-L>1){
			int M = (L+R)/2;
			int how = pref[M];


			int closest = ((take+M-1)/M)*M;
			//if (take==31) cout << M << endl;

			if (2*take < K){
				int closest = ((2*take+M-1)/M)*M;
				int A;
				if (closest >= K){
					closest = K-1;
					A = cl[closest-1];
					if (A < 2*take) A = INF;
					if (A!=INF) A = A%M;
				}
				else{
					A = cl[closest-1];
					if (A < 2*take) A = INF;

					if (A!=INF) A = A%M;
					pair<int, int> Q = min_remainder[M][closest/M-1];


					A = max(Q.first, A);
				}
				if (A!=INF){
					int spend = max(0ll, (2*take-A+M-1)/M);


					int e = how-spend;

					if (e >= take){
						L=M;
						continue;
					}
				}
			}

			int A, B;
			pair<int, int> Q;

			if (closest >= K){
				closest = K-1;
				A = cl[closest-1];
				if (A < take) A = INF;
				B = INF;
				if (A!=INF){
					if (rcnt[A] > 1) B = A;
					else{
						B = cl[A-1];
						if (B < take) B = INF;
					}
				}

				if (A!=INF) A = A%M;
				if (B!=INF) B = B%M;
				Q={A, B};
			}

			else{

				A = cl[closest-1];
				if (A < take) A = INF;
				B = INF;
				if (A!=INF){
					if (rcnt[A] > 1) B = A;
					else{
						B = cl[A-1];
						if (B < take) B = INF;
					}
				}


				if (A!=INF) A = A%M;
				if (B!=INF) B = B%M;


				Q = min_remainder[M][closest/M-1];
				Q = get_opt(Q, {A, B});
			}

			//if (take==31) cout << M << " " << A << " " << B << " " << Q.first << " " << Q.second << " " << how << endl;

			if (Q.second == INF){
				R = M;
				continue;
			}

			A = Q.first, B = Q.second;

			int spend = max(0LL, (take-A+M-1)/M) + max(0LL, (take-B+M-1)/M);

			//if (take==2) cout << spend << endl;

			how -= spend;

			if (how >= take) L = M;
			else R = M;
		}
		if (L > 1){
			if (L*take > ans){
				//cout << take << " " << L << endl;
			}
			ans = max(ans, L*take);
		}


	}
	cout << ans;

}