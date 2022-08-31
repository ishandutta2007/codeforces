#include <bits/stdc++.h>
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;
int n;
vector<int> Shift(vector<int> &v, int x){
	vector<int> t;
	int start = n - x;
	for (int i=0;i<n;++i){
		t.push_back(v[(i+start)%n]);
	}
	return t;
}

vector<pair<int, int> > rmq;

void build(int i, int l, int r, vector<int> &v){
	if (r-l==1){
		rmq[i] = {v[l], l};
		return;
	}
	int mid = (l+r)/2;
	build(2*i+1, l, mid, v), build(2*i+2, mid, r, v);
	rmq[i] = min(rmq[2*i+1], rmq[2*i+2]);
}

pair<int, int> get_min(int i, int l, int r, int l1, int r1){
	if (l1 >= r1) return {1e9, 1e9};
	if (l==l1 && r==r1) return rmq[i];
	int mid = (l+r)/2;
	return min(get_min(2*i+1, l, mid, l1, min(r1, mid)), get_min(2*i+2, mid, r, max(l1, mid), r1));
}

pair<int, int> solve(int l, int r){
	if (l > r) return {0,0};
	if (l==r) return {1,0};
	pair<int, int> index = get_min(0, 0, n, l, r+1);
	if (l==0 && r==n-1){
		int A = solve(l, index.second-1).first, B = solve(index.second+1, r).first;
		return {A, B};
	}
	return {1 + max(solve(l, index.second-1).first, solve(index.second+1, r).first), 0};
}

pair<int, int> get(vector<int> &v){
	build(0, 0, n, v);
	return solve(0, n-1);
}

main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("J_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	if (n==1){
		cout << 1 << " " << 0 << endl;
		return 0;
	}
	rmq.assign(4*n, {-1, -1});
	vector<int> v(n);
	for (int i=0; i < n; ++i) cin >> v[i];
	int index = -1;
	for (int i=0;i<n;++i) if (v[i] == 1) index = i;
	int shift = index;
	vector<int> t;
	for (int i=0;i<n;++i){
		t.push_back(v[(i+index)%n]);
	}
	v = t;
	int L = -1, R = n;
	while (R-L>1){
		int M = (L+R)/2;
		vector<int> a = Shift(v, M);
		pair<int, int> A = get(a);
		//cout << M << " " << A.first << " " << A.second << endl;
		if (A.first <= A.second) L = M;
		else R = M;
	}

	vector<int> T = Shift(v, L);
	int res = (shift + 3*n - L)%n;
	pair<int, int> Q = get(T);
	cout << max(Q.first+1, Q.second+1) << " " << res << endl;
}