#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=1e6+6,P=998244353;
int a[N];
int fpw(int x,int y){
	int s=1;
	for (;y;y>>=1,x=(ll)x*x%P)
		if (y&1) s=(ll)s*x%P;
	return s;
}
int main(){
	int n,fac1=1,fac2=1; scanf("%d",&n);
	rep(i,1,n) fac1=(ll)fac1*i%P; fac1=fpw(fac1,P-2);
	rep(i,1,2*n) fac2=(ll)fac2*i%P;
	rep(i,1,2*n) scanf("%d",&a[i]);
	sort(a+1,a+1+2*n);
	int ans=0;
	rep(i,1,n) ans=(ans+P-a[i])%P;
	rep(i,n+1,2*n) ans=(ans+a[i])%P;
	cout<<(ll)ans*fac2%P*fac1%P*fac1%P<<endl;
	return 0;
}