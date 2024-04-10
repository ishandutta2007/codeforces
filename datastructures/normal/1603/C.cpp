#include <iostream>
#include <cstdio>
#define mod 998244353
using namespace std;
int t,n,a[100005],c[2][1305],len[100005];
int f[2][1305],g[2][1305],ans;
void upd(int &x,int y){
	x+=y;
	if (x>=mod)x-=mod;
	return;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		len[0]=0;
		c[0][++len[0]]=1;
		ans=0;
		for (int i=1;i<=n;i++){
			len[i]=0;
			for (int j=0;j<=1280;j++)f[i&1][j]=g[i&1][j]=0;
			int k=1;
			for (int j=1;j<=a[i];){
				int val=a[i]/j;
				int qwqval=(a[i]-1)/j+1;
				c[i&1][++len[i]]=qwqval;
				while(c[(i-1)&1][k]>val)k++;
				f[i&1][len[i]]=1;
				g[i&1][len[i]]=g[(i-1)&1][k];
				upd(f[i&1][len[i]],f[(i-1)&1][k]);
				upd(g[i&1][len[i]],1ll*(j-1)*f[i&1][len[i]]%mod);
				if (qwqval==1)break;
				j=min(a[i]/val+1,(a[i]-1)/(qwqval-1)+1);
			}
			upd(ans,g[i&1][1]);
		}
		for (int i=0;i<=1280;i++)f[0][i]=f[1][i]=g[0][i]=g[1][i]=0;
		cout<<ans<<endl;
	}
	return 0;
}