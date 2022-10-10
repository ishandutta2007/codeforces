#include <iostream>
#include <stack>

using namespace std;

#define fff(i, a, b) for (i = a; i != b; ++i)
#define ff(i, n) fff(i, 0, n)

int main (void) {
	ios_base::sync_with_stdio(0);

	int i, j, t;
	int m, n, k;

	cin >> n >> m >> k >> ws;
	int map[n][m];
	unsigned long long val[n][m];
	char ch;

	ff (i, n) {
		ff (j, m) {
			cin >> ch;
			map[i][j] = (ch == '*') ? 1 : 0;
			val[i][j] = 0;
		}
		cin >> ws;
	}

	stack<int> xStack;
	stack<int> yStack;

	ff (i, k) {
		int x, y;
		cin >> x >> y;
		--x; --y;

		if (map[x][y] > 1) {
			int px = x;
			int py = y;
			if (map[x][y] == 2) {
				px = val[x][y] / m;
				py = val[x][y] % m;
			}

			cout << val[px][py] << '\n';
			continue;
		}

		unsigned long long p = x * m + y;

		xStack.push(x);
		yStack.push(y);
		unsigned long long result = 0;

		while (!xStack.empty()) {
			int nx = xStack.top();
			int ny = yStack.top();
			xStack.pop();
			yStack.pop();

			if (map[nx][ny] > 1) continue;
			if (map[nx][ny] == 1) {
				++result;
				continue;
			}

			map[nx][ny] = 2;
			val[nx][ny] = p;

			xStack.push(nx - 1);
			yStack.push(ny);

			xStack.push(nx + 1);
			yStack.push(ny);

			xStack.push(nx);
			yStack.push(ny - 1);

			xStack.push(nx);
			yStack.push(ny + 1);

		}

		map[x][y] = 3;
		val[x][y] = result;

		cout << result << '\n';

	}


	return 0;

}