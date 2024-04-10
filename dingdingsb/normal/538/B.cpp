// Problem: CF538B Quasi Binary
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF538B
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,num[20],cnt;
signed main(){
	cin>>n;
	for(int i=1;i<=1000000000;i*=10){
		int _=n/i%10;cnt=max(cnt,_);
		for(int j=1;j<=_;j++)
			num[j]+=i;
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)cout<<num[i]<<" ";
}