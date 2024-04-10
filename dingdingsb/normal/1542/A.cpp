// Problem: A. Odd Set
// Contest: Codeforces - Codeforces Round #729 (Div. 2)
// URL: https://codeforces.ml/contest/1542/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int t,n,a[N];
signed main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);int cnt=0;
		for(int i=1;i<=2*n;i++)
			scanf("%d",&a[i]),cnt+=a[i]%2;
		if(cnt==n)puts("Yes");
		else puts("No");
	}
}