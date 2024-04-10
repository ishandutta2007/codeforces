#include <bits/stdc++.h>

using namespace std;

const int N = 2015;

int n, a[N], b[N];

vector< pair<int, int> > ans;

int main() {
	scanf("%d", &n);
	for(int i = 0; i<n; i++) {
		int x;
		scanf("%d", &x);
		b[x-1] = i;
	}
	for(int i = 0;i<n; i++) {
		int x; scanf("%d", &x);
		a[b[x-1]] = i;
	}
	int sum = 0;
	for(int i = 0; i<n; i++) {
		int pos = -1;
		for(int j = i; j<n; j++) {
			b[j] = j;
			if(j > i && a[b[j]] < a[b[j-1]])
				b[j] = b[j-1];
			if(a[j] == i)
				pos = j;
		}
		while(pos != i) {
			sum += pos - b[pos-1];
			ans.emplace_back(pos+1, b[pos-1]+1);
			swap(a[pos], a[b[pos-1]]);
			pos = b[pos-1];
		}
	}
	printf("%d\n%d\n", sum , ans.size());
	for(int i = 0; i<ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}