// Problem: A. Contest Start
// Contest: Codeforces - Codeforces Round #727 (Div. 2)
// URL: https://codeforces.ml/contest/1539/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int k;int n,x,t;
signed main(){
	cin>>k;
	while(k--){
		cin>>n>>x>>t;
		int a=t/x;
		if(a==0)puts("0");
		else if(n<=a){
			//n-1 +...+1
			printf("%lld\n",(n)*(n-1)/2);
		}else{
			//a-1 + ... +1
			printf("%lld\n",(n-a)*a+a*(a-1)/2);
		}
	}
}