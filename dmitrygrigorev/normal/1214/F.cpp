#include <bits/stdc++.h>
#define ll long long
#define db long double

using namespace std;
vector<ll> add;
pair<int, int> bin_search(vector<pair<int, int> > &a, int l, int r){
	if (l > r) return {0, -1};
	int L = 0, R = a.size() + 1;
	while (R-L>1){
		int M = (L+R)/2;
		if (a[M-1].first <= l-1) L = M;
		else R = M;
	}
	int Q = 0, T = a.size() + 1;
	while (T-Q > 1){
		int M = (T+Q)/2;
		if (a[M-1].first <= r) Q = M;
		else T = M;
	}
	return {L, Q-1};
}

int n;
bool key_par;
void go_2(int l, int r, ll a){
	add[l] += a;
	add[r+1] -= a;
}
void go(int l, int r, ll a){
	//cout << l << " " << r << " " << a << endl;
	if (key_par){
		l = (n-l)%n;
		r = (n-r)%n;
		swap(l, r);
	}
	if (l > r){
		go_2(l, n-1, a);
		go_2(0, r, a);
		return;
	}
	add[l] += a;
	add[r+1] -= a;
}

void add_shift(int index, int l, int r, ll a){
	if (l > r) return;
	//cout << index << " " << l << " " << r << " " << a << endl;
	int first_move = (l-index+4*n)%n;
	int second_move = (r-index+4*n)%n;
	if (first_move <= second_move){
		go(first_move, second_move, a);
	}
	else{
		go(first_move, n-1, a);
		go(0, second_move, a);
	}
}

main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin >> m >> n;
	vector<pair<int, int> > a, b;
	for (int i=0; i < n; i++){
		int x;
		cin >> x;
		x--;
		a.push_back({x, i});
	}
	for (int i=0; i < n; i++){
		int x;
		cin >> x;
		x--;
		b.push_back({x, i});
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	add.assign(n+1, 0);
	for (int i=0; i < b.size(); ++i){
		int value = b[i].first;
		pair<int, int> p = bin_search(a, max(0, value - m/2), value);
		add_shift(i, p.first, p.second, value);
		if (value - m/2 < 0){
			int Q = value-m/2+m;
			pair<int, int> p = bin_search(a, Q, m-1);
			add_shift(i, p.first, p.second, m+value);
		}
		pair<int, int> t = bin_search(a, value+1, min(m-1, value + (m-1)/2));
		add_shift(i, t.first, t.second, -value);
		//if (i==2) cout << value + (m-1)/2 << " " << t.first << " " << t.second << endl;
		if (value + (m-1)/2 > m-1){
			int Q = value + (m-1)/2 - m;
			pair<int, int> t = bin_search(a, 0, Q);
			add_shift(i, t.first, t.second, -value);
		}
		//exit(0);
	}
	//exit(0);
	//cout << endl;
	key_par = true;
	for (int i=0; i < a.size(); ++i){
		int value = a[i].first;
		pair<int, int> p = bin_search(b, max(0, value - (m-1)/2), value-1);
		add_shift(i, p.first, p.second, value);
		if (value - (m-1)/2 < 0){
			int Q = value-(m-1)/2+m;
			pair<int, int> p = bin_search(b, Q, m-1);
			add_shift(i, p.first, p.second, m+value);
		}
		pair<int, int> t = bin_search(b, value, min(m-1, value + m/2));
		add_shift(i, t.first, t.second, -value);
		if (value + m/2 > m-1){
			int Q = value + m/2 - m;
			pair<int, int> t = bin_search(b, 0, Q);
			add_shift(i, t.first, t.second, -value);
		}
		//exit(0);
	}
	int best_shift = -1;
	ll best_ans = 5e18;
	ll ans = 0;
	for (int i=0; i < n; ++i){
		ans += add[i];
		if (ans < best_ans){
			best_shift = i;
			best_ans = ans;
		}
	}
	cout << best_ans << "\n";
	vector<int> res(n);
	for (int i=n-best_shift; i < 2*n-best_shift; ++i){
		int I = i - (n-best_shift);
		int pos = b[i%n].second;
		res[a[I].second] = pos;
	}
	for (int i=0;i<n;++i) cout << res[i]+1 << " ";
}