// Problem: CF643F Bears and Juice
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF643F
// Memory Limit: 250 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int P=131;
int n,p,q;typedef unsigned ui;
ui C[P];
ui calc(int m){
	vector<ui>a,b;
	for(int i=1;i<=m;i++)a.push_back(n-i+1),b.push_back(i);
	for(int i=0;i<m;i++)for(int j=0;j<m;j++){
		int d=__gcd(a[i],b[j]);
		a[i]/=d;b[j]/=d;
	}
	ui res=1;
	for(int i=0;i<m;i++)res*=a[i];
	return res;
}
signed main(){
	cin>>n>>p>>q;
	ui ans=0;
	for(int i=0;i<=min(n-1,p);i++)C[i]=calc(i);
	for(ui i=1;i<=q;i++){
		ui tmp=0;
		for(ui j=0,k=1;j<=min(n-1,p);j++,k*=i)
			tmp+=C[j]*k;
		ans^=(i*tmp);
	}
	cout<<ans;
}