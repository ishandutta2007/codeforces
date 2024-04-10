#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 5e5+5;
int n;
ll a[N];

int main() {
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) {
		scanf("%I64d",a + i);
		if(i) a[i] += a[i-1];
	}
	if(a[n-1]%3 != 0) {
		printf("0\n");
		return 0;
	}
	ll seen = 0, ans = 0;
	for(int i = 0; i < n-1; ++i) {
		if(a[i] == 2*a[n-1]/3) {
			ans += seen;
		}
		seen += a[i] == a[n-1]/3;
	}
	printf("%I64d\n",ans);
	return 0;
}