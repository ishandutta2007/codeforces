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
int s[110], g[110], f[110];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", s + i);
		if(s[i] == 0){
			f[i] = f[i - 1] + 1; //zero
			g[i] = g[i - 1];
		}else{
			f[i] = f[i - 1];
			g[i] = max(f[i - 1], g[i - 1]) + 1;
		}
	}
	printf("%d\n", max(f[n], g[n]));
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}