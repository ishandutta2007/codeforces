#include <bits/stdc++.h>
using namespace std;

const int N = 400;
int a[N],n,ans=-(1<<30);

set<int> done,proc;

int main() {
	scanf("%d",&n);
	proc.insert(0);
	while(proc.size()) {
		int a = *proc.begin(), b = n*2-1-a;
		proc.erase(a);
		done.insert(a);
		for(int m = max(0,n-b); m <= min(a,n); ++m) {
			int i = a-m + n-m;
			if(!done.count(i) && !proc.count(i)) {
				proc.insert(i);
			}
		}
	}
	for(int i = 0; i < 2*n-1; ++i)
		scanf("%d",a+i);
	sort(a,a+2*n-1);
	for(int b : done) {
		int s = 0;
		for(int i = 0; i < b; ++i)
			s += -a[i];
		for(int i = b; i < 2*n+1; ++i)
			s += a[i];
		ans = max(ans,s);
	}
	printf("%d\n",ans);
}