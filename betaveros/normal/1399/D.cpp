#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define allof(s) (s).begin(), (s).end()

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

int n;
char a[200008];
int answer[200008];

vector<int> seqs[2];

int getSeq(int bit) {
	if (seqs[!bit].size()) {
		int x = seqs[!bit].back();
		seqs[!bit].pop_back();
		seqs[bit].push_back(x);
		return x;
	} else {
		int x = (int) (seqs[bit].size() + 1);
		seqs[bit].push_back(x);
		return x;
	}
}

void verify() {
	int nGroups = (seqs[0].size() + seqs[1].size());
	fori (g, 1, nGroups + 1) {
		char last = '\0';
		fori (i, 0, n) {
			assert(answer[i] <= nGroups);
			if (answer[i] == g) {
				if (last != '\0') {
					assert(
						(last == '0' && a[i] == '1') ||
						(last == '1' && a[i] == '0'));
				}

				last = a[i];
			}
		}
	}
}

void tc() {
	cin >> n >> a;

	fori (i, 0, n) {
		switch (a[i]) {
			case '0':
				answer[i] = getSeq(0);
				break;
			case '1':
				answer[i] = getSeq(1);
				break;
			default:
				throw logic_error("bad");
		}
	}

	// verify();

	cout << (seqs[0].size() + seqs[1].size()) << '\n';
	fori (i, 0, n) {
		if (i) cout << ' ';
		cout << answer[i];
	}
	cout << '\n';

	seqs[0].clear();
	seqs[1].clear();
}

int main() {
	int tcn;
	cin >> tcn;
	fori (i, 0, tcn) {
		tc();
	}
}