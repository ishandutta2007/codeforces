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

const int kMaxN = 500000;

int V[kMaxN], I[kMaxN];
unordered_set<int> Taken, Avail;
int Cnt[2];

void Take(int x) {
	Avail.erase(x);
	Taken.insert(x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Comment these lines before submitting
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);

	// Start code here

	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; ++i) {
		cin >> V[i];
		I[i] = i;
	}

	for(int i = m; i >= 1; --i) {
		Avail.insert(i);
		if(Avail.size() > 800000) break;
	}




	sort(I + 1, I + n + 1, [](int a, int b) {return V[a] > V[b];});

	vector<int> ToSolve;

	for(int i = 1; i <= n; ++i) {
		int now = I[i];
		if(Cnt[V[now] % 2] < n / 2 && !Taken.count(V[now])) {
			Cnt[V[now] % 2] += 1;
			Take(V[now]);
		} else {
			ToSolve.push_back(now);
		}
	}

	int sz = ToSolve.size();

	for(auto x : Avail) {
		if(Cnt[x % 2] < n / 2) {
			Cnt[x % 2] += 1;
			V[ToSolve.back()] = x;
			ToSolve.pop_back();

			if(ToSolve.empty()) break;
		}
	}

	if(!ToSolve.empty()) {
		cout << -1 << endl;
	} else {
		cout << sz << endl;
		for(int i = 1; i <= n; ++i) {
			cout << V[i] << " ";
		}
		cout << endl;
	}



	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/