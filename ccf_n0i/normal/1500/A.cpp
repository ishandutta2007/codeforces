#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
int n,i,j;
struct cc{
	int v,i;
}a[200005];
bool operator <(cc x,cc y){
	return x.v<y.v;
}
int c[5000005],d[5000005];
int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%d",&a[i].v);
		a[i].i=i;
	}
	n=min(n,10000);
	sort(a+1,a+n+1);
	rep(i,n){
		for(j=i+1;j<=n;j++){
			if(c[a[j].v-a[i].v]&&d[a[j].v-a[i].v]){
				if(c[a[j].v-a[i].v]!=i&&c[a[j].v-a[i].v]!=j&&d[a[j].v-a[i].v]!=i&&d[a[j].v-a[i].v]!=j){
					printf("YES\n%d %d %d %d\n",a[c[a[j].v-a[i].v]].i,a[j].i,a[i].i,a[d[a[j].v-a[i].v]].i);
					return 0;
				}
			}
			else{
				c[a[j].v-a[i].v]=i;
				d[a[j].v-a[i].v]=j;
			}
		}
	}
	puts("NO");
	return 0;
}