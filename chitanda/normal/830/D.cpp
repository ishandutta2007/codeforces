#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()
#define add(a, b) a = (a + b) % M

int n;
int f[510][510];

int main(){
	scanf("%d", &n);
	f[0][0] = 1;
	for(int i = 1; i <= n; ++i){
		for(int l = 0; l <= n; ++l)
			for(int r = 0; l + r <= n; ++r){
				int num = (ll)f[i - 1][l] * f[i - 1][r] % M;
				add(f[i][l + r], num);
				add(f[i][l + r + 1], num);
				add(f[i][l + r], (ll)num * l * 2);
				add(f[i][l + r], (ll)num * r * 2);
				add(f[i][l + r - 1], (ll)num * l * r * 2);
				if(l) add(f[i][l + r - 1], (ll)num * l * (l - 1));
				if(r) add(f[i][l + r - 1], (ll)num * r * (r - 1));
			}
	}
	printf("%d\n", f[n][1]);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}