#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()
typedef long long ll;

int X2;

int get_maxp(int n){
	int lim = sqrt(n) + 0.1;
	for(int i = 2; i <= lim; ++i)
		if(n % i == 0){
			while(n % i == 0) n /= i;
			if(n == 1) return i;
		}
	return n;
}

int main(){
	scanf("%d", &X2);
	int maxp = get_maxp(X2);
	//printf("%d\n", maxp);
	int ans = X2;;
	for(int i = X2 - maxp + 1; i <= X2; ++i){
		int p = get_maxp(i);
		//printf("%d: %d\n", i, p);
		if(i != p)
			ans = min(ans, i - p + 1);
	}
	printf("%d\n", ans);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}