#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 1000005
using namespace std;

int T,n,K,d,i,j,k,a[maxn],t[maxn],cnt,ans;

int main(){
//	freopen("ceshi.in","r",stdin);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&n,&K,&d);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		cnt=0; for(i=1;i<=d;i++) if (!t[a[i]]++) cnt++;
		ans=cnt;
		for(i=d+1;i<=n;i++){
			if (!--t[a[i-d]]) cnt--;
			if (!t[a[i]]++) cnt++;
			ans=min(ans,cnt);
		}
		for(i=n-d+1;i<=n;i++) t[a[i]]--;
		printf("%d\n",ans);
	}
}