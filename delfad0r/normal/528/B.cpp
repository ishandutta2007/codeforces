#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > ii;

int N;
ii I[200010];

int main() {
	scanf("%d", &N);
	for(int n = 0; n < N; ++n) {
		int x, w;
		scanf("%d%d", &x, &w);
		I[n] = ii(x + w, x - w);
	}
	
	sort(I, I + N);
	
	int ans = 0, ex = - (1 << 30);
	for(int n = 0; n < N; ++n) {
		if(ex > I[n].second) continue;
		++ans;
		ex = I[n].first;
	}
	
	printf("%d\n", ans);
}