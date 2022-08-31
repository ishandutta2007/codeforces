#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

ll tut;

struct Vertex{map<int, int> go; int cnt1; int cnt2;};

vector<Vertex> bor;

void create_vertex(){
	Vertex vt;
	vt.cnt1 = 0, vt.cnt2=0;
	vt.go = {};
	bor.push_back(vt);
}

void add(int Q, int tp){
	if (tp==1){
		bor[Q].cnt1++;
		tut += bor[Q].cnt2;
	}
	else{
		bor[Q].cnt2++;
		tut += bor[Q].cnt1;
	}
}

int go(int vertex, int ed, int tp){
	if (!bor[vertex].go.count(ed)){
		create_vertex();
		bor[vertex].go[ed] = bor.size()-1;
	}

	int Q = bor[vertex].go[ed];
	add(Q, tp);

	return Q;
}

ll solve(vector<int> &v, int l, int r){
	if (l==r) return 0;
	int mid = (l+r)/2;
	bor.clear();
	create_vertex();
	int cur = 0;
	vector<int> path = {0};
	vector<int> st;
	tut=0;
	for (int i=mid+1; i <= r; ++i){
		if (!st.size() || v[i] != st.back()){
			path.push_back(go(cur, v[i], 1));
			//cout << path.back()<< " " << v[i] << endl;
			st.push_back(v[i]);
		}
		else{
			st.pop_back();
			path.pop_back();
			int L = path.back();
			add(L, 1);
		}
		cur = path.back();
	}

	//exit(0);
	cur=0;
	path = {0};
	st.clear();
	for (int i=mid; i >= l; i--){
		if (!st.size() || v[i] != st.back()){
			path.push_back(go(cur, v[i], 2));
			//cout << path.back() << " " << v[i] << endl;
			st.push_back(v[i]);
		}
		else{
			st.pop_back();
			path.pop_back();
			int L = path.back();
			add(L, 2);
		}
		cur = path.back();
	}
	//cout << tut;
	//exit(0);

	ll cu = tut;
	return cu + solve(v, l, mid) + solve(v, mid+1, r);

}

void solve(){
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i=0;i<n;++i) cin >> v[i];

	cout << solve(v, 0, n-1) << "\n";
	
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	for (int i=0; i < q; ++i) solve();
}