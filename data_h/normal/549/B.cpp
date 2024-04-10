#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1111;

int n;
char table[N][N];
int c[N], a[N];

vector<int> answer;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", table[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	while (1) {
		int t = -1;
		for (int i = 0; i < n; i++) {
			if (c[i] == a[i]) {
				t = i;
				break;
			}
		}
		if (t == -1) {
			break;
		} else {
			for (int i = 0; i < n; i++) {
				if (table[t][i] == '1') {
					c[i]++;
				}
			}
			answer.push_back(t);
		}
	}
	printf("%d\n", (int)answer.size());
	sort(answer.begin(), answer.end());
	for (int i = 0; i < (int)answer.size(); i++) {
		printf("%d%c", answer[i] + 1, i + 1 == (int)answer.size() ? '\n' : ' ');
	}
	return 0;
}