#include<bits/stdc++.h>
#define int long long
const int N=800050,M=650000;
using namespace std;
 
int n,a[N],ans,sum;
struct BIT{
	int s[N];
	void add(int k,int p){
		while(k<=M)s[k]+=p,k+=k&-k;
	}
	int sum(int k){
		int ans=0;
		while(k)ans+=s[k],k-=k&-k;
		return ans;
	}
}A,B;
 
main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]),sum+=a[i];
		ans-=B.sum(a[i]);
		for(int j=1;a[i]*(j+1)-1<=M;j++)
			ans-=a[i]*j*(A.sum(a[i]*(j+1)-1)-A.sum(a[i]*j-1));
		printf("%lld ",sum*(i-1)+ans);
		A.add(a[i],1);
		for(int j=1;a[i]*j<=M;j++)
			B.add(a[i]*j,a[i]);
	}
}