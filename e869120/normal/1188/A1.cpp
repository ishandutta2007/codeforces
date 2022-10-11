#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int N, deg[1 << 19];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N - 1; i++) {
		int pa, pb; scanf("%d%d", &pa, &pb);
		deg[pa]++; deg[pb]++;
	}
	bool flag = false;
	for (int i = 1; i <= N; i++) {
		if (deg[i] == 2) flag = true;
	}
	if (flag == true) printf("NO\n");
	else printf("YES\n");
	return 0;
}