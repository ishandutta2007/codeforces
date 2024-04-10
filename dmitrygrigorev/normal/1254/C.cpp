#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

/*

vector<pair<int, int> > v = {{-2, 1}, {3, -1}, {-2, -1}, {1, -2}, {0, 3}, {2, 2}};

int get(int a, int b, int c, int d){
	b--, c--, d--;
	int dx1 = v[c].first - v[b].first, dy1 = v[c].second-v[b].second, dx2 = v[d].first - v[b].first, dy2 = v[d].second-v[b].second;
	int R = dx1*dy2 - dx2*dy1;
	if (a==2) {
		if (R>0) return 1;
		return -1;
	}
*/

int ask(int a, int b, int c, int d){



	cout << a << " " << b << " " << c << " " << d << endl;
	int R;
	cin >> R;
	return R;
}

main(){
#ifdef LOCAL
	//freopen("P_input.txt", "r", stdin);
	//freopen("P_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int mx = 2;

	for (int i=3; i <= n; ++i){
		int val = ask(2, 1, i, mx);
		if (val == 1) mx = i;
	}

	vector<pair<int, int> > square;

	//cout << ask(2, 1, 5, 3);
	//exit(0);

	for (int i=2; i <= n; ++i){
		if (i==mx) continue;
		int S = ask(1, 1, mx, i);
		square.push_back({S, i});
	}

	//cout << mx << endl;
	//exit(0);

	sort(square.begin(), square.end());

	vector<int> right, left;

	for (int i=0; i+1 < square.size(); ++i){
		int val = ask(2, 1, square[i].second, square.back().second);
		if (val==1) right.push_back(square[i].second);
		else left.push_back(square[i].second);
	}

	cout << 0 << " 1 " << mx << " ";
	for (int i=0; i < right.size(); ++i){
		cout << right[i] << " ";
	} 
	cout << square.back().second << " ";
	for (int i=0; i < left.size(); ++i){
		cout << left[left.size()-i-1] << " ";
	}
	cout << endl;
}