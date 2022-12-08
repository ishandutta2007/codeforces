#include<bits/stdc++.h>
using namespace std;
long long n,k;
const long long maxn=3e5+10;
long long a[maxn],now,tot,ans;
struct rec{
	long long x,pos;
}s[maxn];
bool comp(const rec &x,const rec &y){
	return x.x>y.x;
}
int main(){
	int aa;
	scanf("%I64d%I64d",&n,&k);
	for (long long i=1;i<=n;++i){
		scanf("%I64d",&a[i]);
	}
	for (long long i=n;i>=1;--i){
		s[i].x=s[i+1].x+a[i];
		s[i].pos=i;
	}
	sort(s+2,s+1+n,comp);
	long long ans=0;
	for (long long i=2;i<=k;++i){
		ans+=s[i].x;
	}
	printf("%I64d",ans+s[1].x);
	return 0;
}