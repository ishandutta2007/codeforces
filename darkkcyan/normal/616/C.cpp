#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

#define fff(i, a, b) for (i = a; i != b; ++i)
#define ff(i, n) fff(i, 0, n)

int main (void) {
	ios_base::sync_with_stdio(0);

	int i, j, k, h;

	int n, m;
	cin >> n >> m >> ws;

	char board[n][m];
	int tarr[n][m];
	vector<int> ptable;

	ptable.push_back(-1);

	ff (i, n) {
		ff (j, m) {
			cin >> board[i][j];
			tarr[i][j] = 0;
		}
		cin >> ws;
	}

	stack <int> xStack;
	stack <int> yStack;
	ff (i, n) {
		ff (j, m) {
			if (board[i][j] != '.') continue;
			if (tarr[i][j] != 0) continue;
			int pnum = ptable.size();
			int result = 0;
			xStack.push(i);
			yStack.push(j);
			while (!xStack.empty()) {
				int x = xStack.top();
				int y = yStack.top();
				xStack.pop();
				yStack.pop();
				if (x < 0 or x >= n) continue;
				if (y < 0 or y >= m) continue;
				if (board[x][y] != '.') continue;
				if (tarr[x][y] > 0) continue;
				++result;
				tarr[x][y] = pnum;
				xStack.push(x - 1);
				yStack.push(y);
				xStack.push(x + 1);
				yStack.push(y);
				xStack.push(x);
				yStack.push(y - 1);
				xStack.push(x);
				yStack.push(y + 1);
			}
			ptable.push_back(result);
		}
	}

	string outputLine;

	ff (i, m) outputLine += ' ';

	// ff (i, n) {
	// 	ff (j, m) {
	// 		cout << tarr[i][j] << ' ';
	// 	}
	//
	// 	cout << endl;
	// }

	set<int> pset;
	ff (i, n) {
		ff (j, m) {
			if (board[i][j] == '.') outputLine[j] = '.';
			else {
				int t = 1;
				pset.clear();
				pset.insert(-1);
				if (i > 0 and board[i - 1][j] == '.') {
					t += ptable[tarr[i - 1][j]];
					pset.insert(tarr[i - 1][j]);
				}
				if (i < n - 1 and board[i + 1][j] == '.' and pset.count(tarr[i + 1][j]) == 0) {
					t += ptable[tarr[i + 1][j]];
					pset.insert(tarr[i + 1][j]);
				}
				if (j > 0 and board[i][j - 1] == '.' and pset.count(tarr[i][j - 1]) == 0) {
					t += ptable[tarr[i][j - 1]];
					pset.insert(tarr[i][j - 1]);
				}
// cout << i << ' ' << j << tarr[i][j + 1] << endl;
				if (j < m - 1 and board[i][j + 1] == '.' and pset.count(tarr[i][j + 1]) == 0) {
					t += ptable[tarr[i][j + 1]];
					pset.insert(tarr[i][j + 1]);
				}
				outputLine[j] = (char) (t % 10 + '0');
			}
		}
		cout << outputLine << '\n';
	}

	return 0;
}