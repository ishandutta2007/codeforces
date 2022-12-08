#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
const int mod=1e9+7;
int n,m;
int a[maxn],b[maxn];
int cnt[maxn][maxn];
inline int power(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%mod) if (b&1) res=1ll*res*a%mod;
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		for (int j=1;j<=a[i];++j) cnt[i][j]=1;
		cnt[i][a[i]+1]=2;
	}
	for (int i=1;i<=m;++i){
		scanf("%d",&b[i]);
		for (int j=1;j<=b[i];++j){
			if (cnt[j][i]==2){
				puts("0");
				return 0;
			}
			cnt[j][i]=1;
		}
		if (cnt[b[i]+1][i]==1){
			puts("0");
			return 0;
		} else cnt[b[i]+1][i]=2;
	}
	int anss=0;
	for (int i=1;i<=n;++i){
		//puts("");
		for (int j=1;j<=m;++j){
			if (cnt[i][j]==0) ++anss;
			//printf("%d ",cnt[i][j]);
		}
	}
		
	printf("%d",power(2,anss));
}