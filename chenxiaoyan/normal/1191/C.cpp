#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 100000
int n,m,k;
int p[M+1];
signed main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%lld",p+i);
	int now=0,ans=0;
	while(now<m){
		ans++;
		int noww=now,r=(p[now+1]-noww+k-1)/k*k,l=r-k+1;
		while(now<m&&l<=p[now+1]-noww&&p[now+1]-noww<=r)now++;
	}
	printf("%lld",ans);
	return 0;
}
/*1
10 4 5
3 5 7 10
*/
/*2
13 4 5
7 8 9 10
*/