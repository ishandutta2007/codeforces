// Problem: B. Love Song
// Contest: Codeforces - Codeforces Round #727 (Div. 2)
// URL: https://codeforces.ml/contest/1539/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+100;
int n,q;char s[N];
int sum[N][26];
signed main(){
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++)
			sum[i][j]+=sum[i-1][j];
		sum[i][s[i]-'a']++;
	}
	while(q--){
		int l,r;scanf("%d%d",&l,&r);
		int ans=0;
		for(int i=0;i<26;i++)
			ans+=(i+1)*(sum[r][i]-sum[l-1][i]);
		printf("%lld\n",ans);
	}
}