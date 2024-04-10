// Problem: CF468C Hack it!
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF468C
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;int mod;
signed main(){
	cin>>mod;
	int l=mod-inf*9%mod*9%mod;
	int r=l+inf-1;
	cout<<l<<" "<<r;
}