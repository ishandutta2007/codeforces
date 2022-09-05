#include<bits/stdc++.h>
using namespace std;
long long a,n,res;
int main() {
	scanf("%lld%lld",&a,&n);n+=a;
	for(long long l=1;l<=n;l++){
		long long c=n/l,r=n/c;//l..r
		long long x=a%c,y=a/c-x;
		if(y>=0&&(n-x)/c>=(n+y+c)/(c+1))res+=max(min((n-x)/c,r)-max((n+y+c)/(c+1)-y/(c+1),l)+1,0ll);
		l=r;
	}
	cout<<res<<endl;return 0;
}