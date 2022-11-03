#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N;
ll A, B, C;
ll T[200200];
bool killed[200200];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	cin >> A >> B >> C;
	for(int n = 0; n < N; ++n) cin >> T[n];
	
	if(A > B) swap(A, B);
	if(A > C) swap(A, C);
	if(B > C) swap(B, C);
	
	sort(T, T + N);
	if(T[N - 1] > A + B + C) {
		cout << "-1\n";
		return 0;
	}
	int ans = 0;
	while(T[N - 1] > B + C) {
		++ans;
		--N;
	}
	vector<int> a, b, c, ab, ac, bc;
	for(int n = 0; n < N; ++n) {
		if(T[n] <= A) a.push_back(n);
		if(T[n] <= B) b.push_back(n);
		if(T[n] <= C) c.push_back(n);
		if(T[n] <= A + B) ab.push_back(n);
		else if(T[n] > C && T[n] <= A + C) ac.push_back(n);
		else if(T[n] > A + C && T[n] <= B + C) bc.push_back(n);
	}
	while(true) {
		while(ab.size() && killed[ab.back()]) ab.pop_back();
		while(ac.size() && killed[ac.back()]) ac.pop_back();
		while(bc.size() && killed[bc.back()]) bc.pop_back();
		if(bc.size()) {
			++ans;
			killed[bc.back()] = true;
			while(a.size() && killed[a.back()]) a.pop_back();
			if(a.size())
				killed[a.back()] = true;
		} else if(ac.size()) {
			++ans;
			killed[ac.back()] = true;
			while(b.size() && killed[b.back()]) b.pop_back();
			if(b.size())
				killed[b.back()] = true;
		} else if(ab.size() && T[ab.back()] > C) {
			++ans;
			killed[ab.back()] = true;
			while(c.size() && killed[c.back()]) c.pop_back();
			if(c.size())
				killed[c.back()] = true;
		} else break;
	}
	while(true) {
		while(c.size() && killed[c.back()]) c.pop_back();
		if(c.size()) killed[c.back()] = true;
		else break;
		while(b.size() && killed[b.back()]) b.pop_back();
		if(b.size()) killed[b.back()] = true;
		while(a.size() && killed[a.back()]) a.pop_back();
		if(a.size()) killed[a.back()] = true;
		while(ab.size() && killed[ab.back()]) ab.pop_back();
		if(b.empty() && a.empty() && ab.size()) killed[ab.back()] = true;
		++ans;
	}
	cout << ans << '\n';
}