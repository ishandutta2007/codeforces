#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e6;
typedef long long ll;
ll f[MAX_N][2];
int a[MAX_N];
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	f[0][0]=0,f[0][1]=0;
	for(int i=1;i<=n;++i)
		if(a[i]>0){
			f[i][0]=f[i-1][0]+1;
			f[i][1]=f[i-1][1];
		}else{
			f[i][0]=f[i-1][1];
			f[i][1]=f[i-1][0]+1;
		}
	ll ans[2]={0,0};
	for(int i=1;i<=n;++i) ans[0]+=f[i][0],ans[1]+=f[i][1];
	printf("%lld %lld\n",ans[1],ans[0]);
	return 0;
}