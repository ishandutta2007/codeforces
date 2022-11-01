#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 55;

char table[N][N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", table[i]);
	}
	int answer =0 ;
	for (int i = 0; i + 1 < n; i++) {
		for (int j = 0; j + 1 < m; j++) {
			static vector<char> buffer;
			buffer.clear();
			buffer.push_back(table[i][j]);
			buffer.push_back(table[i + 1][j]);
			buffer.push_back(table[i][j + 1]);
			buffer.push_back(table[i + 1][j + 1]);
			sort(buffer.begin(), buffer.end());
			if (buffer[0] == 'a' && buffer[1] == 'c' && buffer[2] == 'e' & buffer[3] == 'f') {
				answer++;
			}
		}
	}
	printf("%d\n", answer);
	return 0;
}