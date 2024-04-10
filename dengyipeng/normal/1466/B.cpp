#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 100005
#define ll long long
using namespace std;

int T,n,i,j,k,a[maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		int ans=0;
		a[n]++,ans++;
		for(i=n-1;i>=1;i--) {
			if (a[i]+1<a[i+1]) a[i]++;
			ans+=a[i]!=a[i+1];
		}
		printf("%d\n",ans);
	}
}