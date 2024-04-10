#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int last[1000100], a[1000100];
int n;

int main(){
	scanf("%d", &n);
	ll ans = 0, cnt = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		cnt += i - last[a[i]];
		ans += cnt - 1;
		last[a[i]] = i;
	}
	ans = ans * 2 + n;
	printf("%.10f\n", 1. * ans / n / n);
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}