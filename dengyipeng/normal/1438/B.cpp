#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 1005
#define ll long long 
using namespace std;

int T,n,i,j,k,a[maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		int ans=0;
		for(i=1;i<=n;i++) for(j=i+1;j<=n;j++) if (a[i]==a[j])
			{ans=1;break;}
		if (!ans) printf("NO\n");
		else printf("YES\n");
	}
}