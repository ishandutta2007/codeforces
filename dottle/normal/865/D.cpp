#include<bits/stdc++.h>
#define int long long
const int N=1000500;
using namespace std;

int a[N],n,ans;
priority_queue<int> q;

main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		q.push(-a[i]),ans+=a[i]+q.top(),q.pop(),q.push(-a[i]);
	} 
	printf("%lld",ans);
}