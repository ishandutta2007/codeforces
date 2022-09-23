#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> V;
int A[100005];

int main() {
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	sort(A + 1, A + N + 1);

	int cnt = 0; A[0] = A[1];
	for(int i = 1; i <= N; i++) {
		if(A[i] != A[i - 1]) { V.push_back(cnt); cnt = 1; }
		else cnt++;
	}
	V.push_back(cnt);

	//for(int i = 0; i < V.size(); i++) printf("%d ", V[i]); puts("");

	sort(V.begin(), V.end());
	reverse(V.begin(), V.end());

	int s = 0;
	int ans = 0;
	for(int i = 1; i <= N; i++) {
		s += V.size();
		//printf("%d %d\n", s, i);
		while(!V.empty() && V.back() <= i) V.pop_back();
		if(ans < s - i) ans = s - i;
	}
	printf("%d\n", ans);
	return 0;
}