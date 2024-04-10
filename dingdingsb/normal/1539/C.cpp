// Problem: C. Stable Groups
// Contest: Codeforces - Codeforces Round #727 (Div. 2)
// URL: https://codeforces.ml/contest/1539/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+100;
int n,k,x;
int a[N];
signed main(){
	scanf("%lld%lld%lld\n",&n,&k,&x);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	vector<int>num;
	for(int i=1;i<n;i++)
		if(a[i+1]-a[i]>x)
			num.push_back((a[i+1]-a[i]-1)/x);
	sort(num.begin(),num.end());
	int ans=num.size()+1;
	for(auto kk:num){
		//printf("%d %d %d\n",k,kk,ans);
		if(kk<=k)k-=kk,ans--;
		else break;
	}
	printf("%lld",ans);
}