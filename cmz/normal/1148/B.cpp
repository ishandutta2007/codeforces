#include<bits/stdc++.h>
using namespace std;
vector <long long> b;
long long a[2000000];
int main(){
	long long n,m,ansa,ansb,k;
	scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&ansa,&ansb,&k);
	if (k>=n||k>=m){
		printf("-1");
		exit(0);
	}
	for (long long i=1;i<=n;++i)
	scanf("%I64d",&a[i]);
	for (long long i=1;i<=m;++i) {
		long long x;
		scanf("%I64d",&x);
		b.push_back(x);
	}
	long long num;
	long long ans=0;
	if (k+1>n) num=n; else num=k+1;
	for (long long i=1;i<=num;++i){
		long long cur=a[i]+ansa;
		long long pos=lower_bound(b.begin(),b.end(),cur)-b.begin();
		if (pos+k-i+1>=m){
			printf("-1");
			exit(0);
		} else
		ans=max(ans,b[pos+k-i+1]+ansb);
	}
	printf("%I64d",ans);
	return 0;
}