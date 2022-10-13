/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*******************Debugging defines*************************/

#define ok_dump() cerr<<"OK\n"
#define var_dump(x) cerr<<#x": "<<x<<'\n'
#define arr_dump(x, n) do{cerr<<#x"[]: ";\
     for(int _=0;_<n;++_) cerr<<x[_]<<" ";cerr<<'\n';}while(0)

/*************************************************************/

string str, ans;
int n, k;

set<int> Pos[256], NotSolved;

void GoFor(int i) {
	// cerr << "GoFor: " << i << '\n';
	ans += str[i];
	while(true) {
		auto it = NotSolved.lower_bound(i);
		if(it == NotSolved.end() || (*it) >= (i + k)) break;
		// cerr << "Erase: " << *it << '\n';
		NotSolved.erase(it);
	}
}

bool SolveGreedy(int c) {
	// cerr << "SolveGreedy: " << c << '\n';
	while(NotSolved.size()) {
		auto it = NotSolved.begin();
		auto it2 = Pos[c].upper_bound(*it);

		if(it2 == Pos[c].begin()) return false;
		--it2;

		// cerr << *it << " " << *it2 << '\n';

		if(*it2 <= *it - k) return false;

		GoFor(*it2);
		Pos[c].erase(it2);
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;
	cin >> str;
	n = str.length();
	

	for(int i = 0; i < n; ++i) {
		Pos[str[i]].insert(i);
	}

	for(int i = k - 1; i < n; ++i)
		NotSolved.insert(i);

	for(int c = 'a'; c <= 'z'; ++c) {
		if(!SolveGreedy(c)) {
			// cerr << "Solved bad:" << c << '\n';
			while(Pos[c].size()) {
				auto it = Pos[c].begin();
				GoFor(*it);
				Pos[c].erase(it);
			}
		} else break;
	}
	cout << ans << endl;
	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/