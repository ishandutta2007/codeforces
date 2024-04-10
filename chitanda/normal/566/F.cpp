#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n, a[1001000], f[1001000];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i), f[a[i]] = 1;
	int ans = 0;
	for(int i = 1; i <= 1000000; ++i){
		for(int j = i + i; j <= 1000000; j += i)
			if(f[j]) f[j] = max(f[j], f[i] + 1);
		ans = max(ans, f[i]);
	}
	printf("%d\n", ans);
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}