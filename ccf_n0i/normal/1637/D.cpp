#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define rep0(i,n) for ((i)=0;(i)<(n);(i)++)
using namespace std;
int a[111],b[111],sum,dlt;
long long res;
bitset<10005> f;
void solve(){
	int n,i,j,k;sum=dlt=res=0;
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n)scanf("%d",&b[i]);
	f.reset();
	f[0]=1;
	rep(i,n){
		if(a[i]>b[i]) swap(a[i],b[i]);
		sum+=a[i];
		dlt+=b[i]-a[i];
		f|=(f<<(b[i]-a[i]));
		res+=1ll*(n-2)*a[i]*a[i];
		res+=1ll*(n-2)*b[i]*b[i];
	}
	for(i=dlt/2;i;i--) if(f[i]) break;
	res+=1ll*(sum+i)*(sum+i);
	res+=1ll*(sum+dlt-i)*(sum+dlt-i);
	cout<<res<<endl;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}