#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 505
using namespace std;

int n,i,j,k,a[maxn],p[maxn],x,y;
int cmp(int i,int j){return a[i]<a[j];}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) a[i]=n-1-a[i],p[i]=i;
	sort(p+1,p+1+n,cmp);
	int sum=0,pre=0,ans=-1;
	for(i=1;i<=n;i++){
		sum+=a[p[i]]-pre;
		if (sum==(i-pre)*(i-pre-1)/2) {
			if (i>pre+1&&a[p[i]]-a[p[pre+1]]>ans)
				ans=a[p[i]]-a[p[pre+1]],x=p[i],y=p[pre+1];
			pre=i,sum=0;
		}
	}
	if (ans==-1) printf("! 0 0\n");
	else printf("! %d %d\n",x,y);
//	printf("%d\n",ans);
}