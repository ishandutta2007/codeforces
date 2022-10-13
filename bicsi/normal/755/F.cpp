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

const int kMaxN = 1000005;

int P[kMaxN];
bool Viz[kMaxN];
int Cnt[kMaxN];
bitset<kMaxN> OK;

vector<int> Lens;
int n, k;

void MakeCycles() {
	for(int i = 1; i <= n; ++i) {
		if(!Viz[i]) {
			int len = 0, j = i;
			do {
				len++;
				Viz[j] = 1;
				j = P[j];
			} while(Viz[j] == 0);
			Lens.push_back(len);
		}
	}
}

void BagaBitset(int len, int cnt) {
	for(int i = 0; i < cnt; ++i)
		OK |= (OK << len);
}
void BagaSmen(int len, int cnt) {
	auto Ant = OK;
	vector<int> Have(len, 0);
	for(int i = 0; i <= n; ++i) {
		Have[i % len] += OK[i];

		OK[i] = (Have[i % len] > 0);

		if(i - cnt * len >= 0)
			Have[i % len] -= Ant[i - cnt * len];
	}
}

int SolveBest() {
	OK[0] = true;
	for(auto x : Lens) {
		Cnt[x] += 1;
	}

	for(int len = 1; len <= n; ++len) {
		int have = Cnt[len];
		if(have == 0) continue;
		if(have <= 32) {
			BagaBitset(len, have);
		} else {
			BagaSmen(len, have);
		}
	}

	if(OK[k]) return k;
	return k + 1;
}

int SolveWorst() {
	priority_queue<int> Q;
	for(auto x : Lens)
		Q.push(x);

	int ans = 0;
	for(int i = 0; i < k; ++i) {
		if(Q.empty()) break;
		int top = Q.top();
		Q.pop();
		if(top <= 1) ans += top;
		else {
			ans += 2;
			Q.push(top - 2);
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Comment these lines before submitting
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);

	// Start code here

	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> P[i];

	MakeCycles();

	cout << SolveBest() << " " << SolveWorst() << endl;


	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/