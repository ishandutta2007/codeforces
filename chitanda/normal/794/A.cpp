#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int a, b, c, n, x;

int main(){
	scanf("%d%d%d", &b, &a, &c);
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &x);
		if(x > a && x < c) cnt++;
	}
	printf("%d\n", cnt);
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}