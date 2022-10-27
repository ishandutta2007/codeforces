#include<bits/stdc++.h>
#include<windows.h>
#define MN 100005
typedef long long ll;
int n,a[MN],N,lst;
ll b[MN];
int main()
{
	int tt;
	for(scanf("%d",&tt);tt--;) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		if(a[n]==0) {
			puts("0");
			continue;
		}
		lst=0;
		while(n>1) {
			bool flg=0;
			for(int i=n;i>lst;i--) {
				if(a[i]==0) {
					lst=i;
					break;
				}
			}
			n--;
			for(int i=std::max(1,lst);i<=n;i++) a[i]=a[i+1]-a[i];
			std::sort(a+std::max(1,lst),a+1+n);
			if(lst) lst--;
		}
		printf("%d\n",a[1]);
	}
}