#include<bits/stdc++.h>
#define int long long
const int N=200050,P=20;
using namespace std;

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

int t,n,a[N],b[N],ln[N];
int st[P][N];

int qry(int x,int y){
	int z=ln[y-x+1];
	return gcd(st[z][x],st[z][y-(1<<z)+1]);
}

main(){
	scanf("%lld",&t),ln[0]=-1;
	for(int i=1;i<N;i++)ln[i]=ln[i>>1]+1;
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=1;i<n;i++)b[i]=abs(a[i]-a[i+1]),st[0][i]=b[i];--n;
		for(int i=1;i<P;i++)
			for(int j=1;j<=n-(1<<i)+1;j++)
				st[i][j]=gcd(st[i-1][j],st[i-1][j+(1<<i-1)]);
		int ans=0;
		for(int i=1;i<=n;i++){
			while(i+ans<=n&&qry(i,i+ans)!=1)
				ans++;
		} 
		printf("%lld\n",ans+1);
	}
}