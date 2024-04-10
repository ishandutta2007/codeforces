#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+1e6;
bool is_pr[N];
void Euler(){
	for(int i=2;i<N;++i) is_pr[i]=1;
	for(int i=2;i<N;++i)
		if(is_pr[i]){
			for(int j=2;i*j<N;++j)
				is_pr[i*j]=0;
		}
}
ll f[N][2];
int a[N];
int main(){
	Euler();
	int T; scanf("%d",&T);
	while(T--){	
		int n,e; scanf("%d%d",&n,&e);
		ll ans=0;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=n;i>=1;--i){
			f[i][0]=f[i][1]=0;
			if(a[i]==1) f[i][0]=1;
			if(is_pr[a[i]]) f[i][1]=1,--ans;
			if(i+e<=n){
				f[i][1]=f[i+e][1]*f[i][0]+(f[i+e][0]+1)*f[i][1];
				f[i][0]=f[i][0]*(f[i+e][0]+1);
			}
			ans+=f[i][1];
		}
		printf("%lld\n",ans);
	}		
	return 0;
}