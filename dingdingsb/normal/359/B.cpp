// Problem: CF359B Permutation
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF359B
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
signed main(){
	cin>>n>>m;n*=2;
	cout<<m+1;for(int i=1;i<=n;i++)if(i!=m+1)cout<<" "<<i;
}