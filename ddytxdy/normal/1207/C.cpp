#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+50;
int n,t,a,b,c[N];LL f[N][2];
void solve(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)f[i][0]=f[i][1]=1e18;
	f[0][0]=b;f[0][1]=1e9;
	for(int i=1;i<=n;i++)scanf("%1d",&c[i]);
	for(int i=1;i<=n;i++){
		if(c[i])f[i][1]=f[i-1][1]+2*b+a;
		else{
			f[i][1]=min(f[i-1][1]+2*b+a,f[i-1][0]+2*a+2*b);
			f[i][0]=min(f[i-1][0]+b+a,f[i-1][1]+2*a+b);
		}
	}
	cout<<f[n][0]<<endl;
}
int main(){
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}