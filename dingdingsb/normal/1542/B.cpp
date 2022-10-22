// Problem: B. Plus and Multiply
// Contest: Codeforces - Codeforces Round #729 (Div. 2)
// URL: https://codeforces.ml/contest/1542/problem/B
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a,b;
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		if(a==1||n==1){
			puts(n%b==1||b==1?"Yes":"No");
			goto nxt;
		}
		else{
			for(int i=1;i<=n;i*=a)
				if((n-i)%b==0){
					puts("Yes");
					goto nxt;
				}
		}
		puts("No");
		nxt:;
	}
}