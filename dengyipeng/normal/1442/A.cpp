#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 30005
using namespace std;

int T,n,i,j,k,a[maxn],l,r,mi[maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		l=1; while (l<n&&a[l+1]<=a[l]) l++;
		r=n; while (r>1&&a[r-1]<=a[r]) r--;
		if (l+1>=r) {printf("YES\n");continue;} 
		mi[1]=a[1];
		for(i=2;i<=n;i++) mi[i]=min(mi[i-1],a[i]);
		int cnt=0,nex=a[r];
		int tp=1;
		for(i=r-1;i>l;i--) {
			a[i]-=cnt;
			if (a[i]<=nex) nex=a[i]; else {
				cnt+=a[i]-nex;
				if (mi[i]-cnt<0) {tp=0;break;}
			}
		}
		if (tp) printf("YES\n"); else printf("NO\n");
	}
}