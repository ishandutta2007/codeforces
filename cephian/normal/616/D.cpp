#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int n,k;
int a[500005];
multiset<int> ms;
set<int> s;

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	int i=1,j=1;
	int mx = 0;
	int fi, fj;
	for(; j <= n; ++j) {
		ms.insert(a[j]);
		s.insert(a[j]);
		while(s.size() > k) {
			ms.erase(ms.find(a[i]));
			if(ms.count(a[i]) == 0)
				s.erase(a[i]);
			++i;
		}
		int m = j-i+1;
		if(m > mx) {
			mx = m;
			fi = i;
			fj = j;
		}
	}
	printf("%d %d\n", fi, fj);
	return 0;
}