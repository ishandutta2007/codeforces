#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define allof(s) (s).begin(), (s).end()

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

const int N = 200008;
int n;
int a[N];
int ranked[N];
int nDistinct;

int minPos[N], maxPos[N]; // rank -> lowest and highest index
int rankCount[N]; // rank -> how many of that rank
int tempCount[N]; // rank -> how many of that rank
int leftBonus[N], rightBonus[N]; // rank -> how many of the -1/+1 rank are strictly before/after all

map<int, int> inverter;

void tc() {
	inverter.clear();

	cin >> n;
	fori (i, 0, n) {
		cin >> a[i];
		ranked[i] = a[i];
	}

	sort(ranked, ranked + n);
	nDistinct = unique(ranked, ranked + n) - ranked;
	// cerr << "distinct: " << nDistinct << "\n";

	fori (i, 0, nDistinct) {
		inverter[ranked[i]] = i;

		minPos[i] = -1;
		rankCount[i] = 0;
		tempCount[i] = 0;
	}

	fori (i, 0, n) {
		int rank = inverter[a[i]];
		if (minPos[rank] == -1) minPos[rank] = i;
		maxPos[rank] = i;
		rankCount[rank]++;
	}

	int best = 0;

	fori (i, 0, n) {
		int rank = inverter[a[i]];
		tempCount[rank]++;

		if (i == minPos[rank]) {
			// resolve leftBonus
			if (rank == 0) {
				leftBonus[rank] = 0;
			} else {
				leftBonus[rank] = tempCount[rank - 1];
			}
			// cerr << "leftBonus of " << rank << " is " << leftBonus[rank] << "\n";
		}

		if (i == maxPos[rank]) {
			// resolve rightBonus
			if (rank == nDistinct - 1) {
				rightBonus[rank] = 0;
			} else {
				rightBonus[rank] = rankCount[rank + 1] - tempCount[rank + 1];
			}
			// cerr << "rightBonus of " << rank << " is " << rightBonus[rank] << "\n";
		}

		// also consider the two-partial-ranks case:
		if (rank < nDistinct - 1) {
			maxify(best, tempCount[rank] + (rankCount[rank + 1] - tempCount[rank + 1]));
		}
	}

	/*
	fori (i, 0, nDistinct) {
		cerr << "rankCount of " << i << " is " << rankCount[i] << "\n";
	}
	*/

	int curRank = 0; // the first rank to be completely used
	while (curRank < nDistinct) {
		int score = leftBonus[curRank] + rankCount[curRank];
		while (curRank < nDistinct - 1 && rightBonus[curRank] == rankCount[curRank + 1]) {
			// completely eat the next rank
			score += rightBonus[curRank];
			curRank++;
		}
		// curRank was still completely used
		score += rightBonus[curRank];
		maxify(best, score);

		curRank++;
	}

	cout << (n - best) << "\n";
}

int main() {
	int tcn;
	cin >> tcn;
	fori (i, 0, tcn) tc();
}