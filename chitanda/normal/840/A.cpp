#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n;
int a[200100], b[200100], w[200100], ans[200100];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	for(int j = 1; j <= n; ++j)
		scanf("%d", b + j), w[j] = j;
	sort(w + 1, w + n + 1, [](int i, int j) { return b[i] > b[j]; });
	for(int i = 1; i <= n; ++i)
		ans[w[i]] = a[i];
	for(int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}