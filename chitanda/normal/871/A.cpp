#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

int main(){
	int n, q;
	scanf("%d", &q);
	for(int i = 1; i <= q; ++i){
		scanf("%d", &n);
		if(n % 4 == 0){
			printf("%d\n", n / 4);
		}else if(n % 4 == 2 && n >= 6){
			printf("%d\n", n / 4);
		}else if(n % 4 == 1 && n >= 9){
			printf("%d\n", n / 4 - 1);
		}else if(n % 4 == 3 && n >= 15){
			printf("%d\n", (n - 15) / 4 + 2);
		}else printf("-1\n");
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}