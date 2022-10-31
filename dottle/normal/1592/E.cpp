#include<bits/stdc++.h>
const int P=20,N=1.1e6;
using namespace std;

int n,a[N],ans,fs[2][N],nx[N],p[2][N];

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=P-1;~i;i--){
		memset(fs,-1,sizeof(fs));
		memset(p,-1,sizeof(p));
		memset(nx,-1,sizeof(nx));
		fs[0][0]=0,p[0][0]=0;
		for(int j=1,s=0,pr=0;j<=n;j++){
			s^=a[j]&~((1<<i+1)-1);
			if(!(a[j]>>i&1))pr=j;
			while(~fs[j&1][s]&&fs[j&1][s]<pr)fs[j&1][s]=nx[fs[j&1][s]];
			if(~fs[j&1][s])ans=max(ans,j-fs[j&1][s]);
			if(~p[j&1][s])nx[p[j&1][s]]=j;
			if(!~fs[j&1][s])fs[j&1][s]=j;
			p[j&1][s]=j;
		}
	}
	cout<<ans;
}