#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 105
#define maxm 200005
using namespace std;

int n,p[maxn],a[maxn],b[maxn],i,j,k,ans;
char ch;

int main(){
//	freopen("ceshi.in","r",stdin);
	scanf("%d",&n);
	for(ch=getchar();ch!='0'&&ch!='1';ch=getchar());
	for(i=1;i<=n;i++) p[i]=ch-'0',ch=getchar();
	for(i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	int ans=0;
	for(i=0;i<maxm;i++){
		int cnt=0;
		for(j=1;j<=n;j++) {
			if (i>=b[j]&&(i-b[j])%a[j]==0)
				p[j]^=1;
			cnt+=p[j];
		}
		ans=max(ans,cnt);
	}
	printf("%d",ans);
	
}