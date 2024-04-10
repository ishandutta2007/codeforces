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

map<int, int> Rem[2][1 << 16];
char Type[20];
int Cost[2][20];
int Have[2][1 << 16];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Comment these lines before submitting
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);

	// Start code here

	int n;
	cin >> n;

	for(int i = 0; i < n; ++i) {
		cin >> Type[i] >> Cost[0][i] >> Cost[1][i];
		Type[i] = (Type[i] == 'B');
	}

	ok_dump();

	for(int msk = 1; msk < (1 << n); ++msk) {
		for(int l = 0; l < n; ++l) {
			if(msk & (1 << l)) {
				int mskk = (msk ^ (1 << l));
				Have[0][msk] = Have[0][mskk] + (Type[l] == 0);
				Have[1][msk] = Have[1][mskk] + (Type[l] == 1);
				break;
			}
		}
	}

	// for(int msk = 0; msk < (1 << n); ++msk) {
	// 	cerr << msk << ": " << Have[0][msk] << " " << Have[1][msk] << endl;
	// }

	ok_dump();

	Rem[0][0][0] = Rem[1][0][0] = 0;
	for(int msk = 0; msk < (1 << n); ++msk) {
		for(int c = 0; c < 2; ++c) {
			for(auto p : Rem[c][msk]) {
				int tok[2] = {0, 0};
				tok[c] += p.first;

				for(int nxt = 0; nxt < n; ++nxt) {
					if(msk & (1 << nxt)) continue;

					int need[2] =  {Cost[0][nxt], Cost[1][nxt]};



					need[0] -= Have[0][msk];
					need[1] -= Have[1][msk];

					need[0] = max(need[0], 0);
					need[1] = max(need[1], 0);

					int add = max(need[0] - tok[0], need[1] - tok[1]);
					

					int rem[2] = {tok[0] + add - need[0], tok[1] + add - need[1]};

/*					if(msk == 3 && nxt == 2) {
						cerr << "DUMP:\n";
						cerr << p.first << " " << p.second << endl;
						
						cerr << need[0] << " " << need[1] << endl;
						cerr << tok[0] << " " << tok[1] << endl;

						cerr << "END DUMP\n";
					}*/

					if(rem[0] == 0) {
						if(Rem[1][msk | (1 << nxt)].count(rem[1]) == 0) Rem[1][msk | (1 << nxt)][rem[1]] = p.second + add;
						Rem[1][msk | (1 << nxt)][rem[1]] = min(Rem[1][msk | (1 << nxt)][rem[1]], p.second + add);
					} else {
						assert(rem[1] == 0);
						if(Rem[0][msk | (1 << nxt)].count(rem[0]) == 0) Rem[0][msk | (1 << nxt)][rem[0]] = p.second + add;
						Rem[0][msk | (1 << nxt)][rem[0]] = min(Rem[0][msk | (1 << nxt)][rem[0]], p.second + add);
					}
				}
			}
		}
	}

	/*for(int c = 0; c < 2; ++c) {
		for(auto p : Rem[c][7]) {
			cerr << c << " " << p.first << " -> " << p.second << endl;
		}
	}*/

	int ans = numeric_limits<int>::max();
	for(int c = 0; c < 2; ++c)
	for(auto p : Rem[c][(1 << n) - 1])
		ans = min(ans, p.second);
	cout << ans + n << endl;

	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/