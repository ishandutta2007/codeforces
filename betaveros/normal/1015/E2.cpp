#include <iostream>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define allof(s) (s).begin(), (s).end()

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

char grid[1008][1008];
int nRows, nCols;
int oldColCsum[1008][1008];
int oldRowCsum[1008][1008];
int newColGain[1008][1008];
int newRowGain[1008][1008];

int starSize(int r, int c) {
	if (grid[r][c] != '*') return 0;

	int lo = 0; // ok
	int hi = min(min(r, c), min(nRows - r - 1, nCols - c - 1)) + 1; // bad;

	while (hi - lo > 1) {
		int mid = (lo + hi) / 2;
		if (
				oldColCsum[r][c] - oldColCsum[r][c - mid] == mid
				&&
				oldRowCsum[r][c] - oldRowCsum[r - mid][c] == mid
				&&
				oldColCsum[r][c + 1 + mid] - oldColCsum[r][c + 1] == mid
				&&
				oldRowCsum[r + 1 + mid][c] - oldRowCsum[r + 1][c] == mid
			) {
			lo = mid;
		} else {
			hi = mid;
		}
	}

	return lo;
}

bool ok() {
	fori (i, 0, nRows) {
		fori (j, 0, nCols) {
			newColGain[i][j + 1] += newColGain[i][j];
			newRowGain[i + 1][j] += newRowGain[i][j];

			if (grid[i][j] == '*' && newRowGain[i][j] == 0 && newColGain[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	cin >> nRows >> nCols;
	fori (i, 0, nRows) cin >> grid[i];

	fori (i, 0, nRows) {
		fori (j, 0, nCols) {
			oldColCsum[i][j+1] = oldColCsum[i][j] + (grid[i][j] == '*');
			oldRowCsum[i+1][j] = oldRowCsum[i][j] + (grid[i][j] == '*');
		}
	}

	int starCount = 0;
	fori (i, 0, nRows) {
		fori (j, 0, nCols) {
			int size = starSize(i, j);
			// cerr << "size" << i << j << ":" << size << "\n";
			if (size) {
				starCount++;
				newColGain[i][j - size] += 1;
				newColGain[i][j + size + 1] -= 1;
				newRowGain[i - size][j] += 1;
				newRowGain[i + size + 1][j] -= 1;
			}
		}
	}

	if (ok()) {
		cout << starCount << "\n";
		fori (i, 0, nRows) {
			fori (j, 0, nCols) {
				int size = starSize(i, j);
				if (size) {
					cout << (i + 1) << " " << (j + 1) << " " << starSize(i, j) << "\n";
				}
			}
		}
	} else {
		cout << -1 << "\n";
	}
}