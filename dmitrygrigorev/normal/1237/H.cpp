#include <bits/stdc++.h>
#define ll long long
#define db long double
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

bool check(vector<int> a, vector<int> b){
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i=0;i<a.size(); ++i){
		//cout << a[i] << " " << b[i] << endl;
		if (a[i] != b[i] && (min(a[i], b[i]) != 1 || max(a[i], b[i]) != 2)) return false;
	}
	return true;
}

void perform(vector<int> &a, vector<int> &ans, int cnt){
	if (cnt==0) return;
	vector<int> b;
	for (int i=0; i < cnt; ++i){
		b.push_back(a[cnt-i-1]);
		if (b.back() == 1 || b.back() == 2) b.back() = 3-b.back();
	}
	for (int i=cnt; i < a.size(); ++i) b.push_back(a[i]);
	a=b;
	ans.push_back(cnt);
}

bool eq(int x, int y){
	if (x == 1 || x==2) return (x+y==3);
	return (x==y);
}

void solve(vector<int> a, vector<int> b){
	if (!check(a, b)){
		cout << -1 << endl;
		return;
	}

	bool was = false;

	int sum = 0;
	for (int i=0; i < b.size(); ++i) if (b[i] == 1) sum++;
	int tot = 0;
	for (int i=0; i < a.size(); ++i) if (a[i] == 2) tot++;
	vector<int> ans;

	for (int i=0; i <= a.size(); ++i){
		if (tot==sum){
			perform(a, ans, i);
			was = true;
			break;
		}
		if (i==a.size()) break;
		if (a[i] == 2) tot--;
		if (a[i] == 1) tot++;
	}

	int rem = -1;

	if (!was){
		int sum = 0;
		for (int i=0; i < a.size(); ++i) if (a[i] == 1) sum++;
		int tot = 0;
		for (int i=0; i < b.size(); ++i) if (b[i] == 2) tot++;
		vector<int> ans;

		for (int i=0; i <= b.size(); ++i){
			if (tot==sum){
				perform(b, ans, i);
				rem = i;
				ans.pop_back();
				was = true;
				break;
			}
			if (i==b.size()) break;
			if (b[i] == 2) tot--;
			if (b[i] == 1) tot++;
		}
	}

	for (int i=0; i < a.size(); ++i){
		int index = a.size() - i - 1;
		for (int j=i; j < a.size(); ++j){
			if (eq(a[j], b[index])){
				perform(a, ans, j);
				perform(a, ans, j+1);
				break;
			}
		}
	}

	if (rem>0) ans.push_back(rem);

	if (a!=b){
		cout << "WRONG";
		exit(0);
	}
	cout << ans.size() << endl;
	for (int i=0; i < ans.size(); ++i){
		cout << ans[i]*2 << " ";
	}
	cout << endl;

}

void solve(){
	string s, t;
	cin >> s >> t;

	vector<int> a, b;
	for (int i=0; i < s.size(); i += 2){
		if (s[i] == '0' && s[i+1] == '0') a.push_back(0);
		if (s[i] == '0' && s[i+1] == '1') a.push_back(1);
		if (s[i] == '1' && s[i+1] == '0') a.push_back(2);
		if (s[i] == '1' && s[i+1] == '1') a.push_back(3);

		if (t[i] == '0' && t[i+1] == '0') b.push_back(0);
		if (t[i] == '0' && t[i+1] == '1') b.push_back(1);
		if (t[i] == '1' && t[i+1] == '0') b.push_back(2);
		if (t[i] == '1' && t[i+1] == '1') b.push_back(3);
	}

	solve(a, b);

}

main(){
#ifdef LOCAL
	freopen("N_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i=0; i < t; ++i) solve();
}