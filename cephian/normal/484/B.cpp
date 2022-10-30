#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 1e5+5,M = 2e6+5;
int nl[M],n;
vi a;

int main() {
	scanf("%d",&n);
	a = vi(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d",&a[i]);
	}
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	n = a.size();
	int j = 0, prev = 0;
	for(int i = 0; i < M; ++i) {
		nl[i] = prev;
		if(j < n && i == a[j]) {
			prev = a[j];
			++j;
		}
		// cout << i << " -> " << nl[i] << endl;
	}
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = a[i]*2; j < M; j += a[i]) {
			if(nl[j] > a[i])
				ans = max(ans,nl[j]%a[i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}