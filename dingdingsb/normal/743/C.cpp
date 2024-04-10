// Problem: CF743C Vladik and fractions
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF743C
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n;cin>>n;
	if(n==1)cout<<-1;
	else cout<<n<<" "<<n+1<<" "<<n*(n+1);
}