#include<stdio.h>
#include<algorithm>
using namespace std;
#define R register int
int a[400001];
inline void Solve(){
	int n,x,ls=0,lp=2e9,ct=0;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",&x);
		if(x!=lp){
			a[ct]=i-ls;
			ct++;
			lp=x;
			ls=i;
		}
	}
	a[ct]=n-ls;
	ct++;
	//printf("X%d\n",ct);
	int tot;
	lp=0;
	for(R i=1;i<=ct;i++){
		lp+=a[i];
		if(lp>(n>>1)){
			tot=i;
			break;
		}
		//printf("%d %d\n",a[i].p,a[i].cnt);
	}
	if(tot<4){
		puts("0 0 0");
		return;
	}
	for(R i=2;i<tot;i++){
		a[i]+=a[i-1];
	}
	int tem=-1;
	for(R i=1;i<tot;i++){
		if(a[i]>(a[1]<<1)){
			tem=i;
			break;
		}
	}
	if(tem==-1||a[tot-1]-a[tem]<=a[1]){
		puts("0 0 0");
		return;
	}
	printf("%d %d %d\n",a[1],a[tem]-a[1],a[tot-1]-a[tem]);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i<t;i++){
		Solve();
	}
	return 0;
}