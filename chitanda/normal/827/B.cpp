#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n, k;

int main(){
	scanf("%d%d", &n, &k);
	n -= 1;
	int m = n / k, r = n % k;
	int now = 2;
	printf("%d\n", m * 2 + (r > 0) + (r > 1));
	for(int i = 1; i <= r; ++i){
		int last = 1;
		for(int j = 1; j <= m + 1; ++j){
			printf("%d %d\n", last, now++);
			last = now - 1;
		}
	}
	for(int i = 1; i <= k - r; ++i){
		int last = 1;
		for(int j = 1; j <= m; ++j){
			printf("%d %d\n", last, now++);
			last = now - 1;
		}
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}