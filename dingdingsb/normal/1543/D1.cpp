// Problem: D1. RPD and Rap Sheet (Easy Version)
// Contest: Codeforces - Codeforces Round #730 (Div. 2)
// URL: https://codeforces.ml/contest/1543/problem/D1
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int t,n,k;
int ask(int x){
	cout<<x<<endl;cout.flush();
	cin>>x;return x;
}
signed main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		int a=0;
		for(int x=0;x<n;x++){
			if(ask(x^a))
				goto loop;
			a=x;
		}
		loop:;
	}
	return 0;
}