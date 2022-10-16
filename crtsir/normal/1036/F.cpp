#include<bits/stdc++.h>
using namespace std;
const long long N=1e18;
long long T,cnt;
long long x,a[5100001];
bool QAQ(long long x){
	long long sq=1ll*sqrt(x);
	return sq*sq<x;
}
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	cin>>T;
	for(long long i=2;i<=1000000;i++){
		long long x=i*i;
		while(x<=N/i){
			x*=i;
			if(QAQ(x))
				a[++cnt]=x;
		}
	}
	sort(a+1,a+cnt+1);
	cnt=(int)(unique(a+1,a+cnt+1)-a-1);
	while(T--){
		scanf("%lld",&x);long long sq=sqrt(x);
		if(sq*sq>x)sq--;
		printf("%lld\n",x-1ll*(upper_bound(a+1,a+cnt+1,x)-a-1)-sq);
	}
}