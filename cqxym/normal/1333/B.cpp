#include<stdio.h>
#define R register int
int ct[100001][3],a[100001],b[100001];
inline void Solve(){
	int n;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
		ct[i][0]=ct[i-1][0];
		ct[i][1]=ct[i-1][1];
		ct[i][2]=ct[i-1][2];
		if(a[i]==-1){
			ct[i][0]++;
		}else if(a[i]==0){
			ct[i][1]++;
		}else{
			ct[i][2]++;
		}
	}
	for(R i=1;i<=n;i++){
		scanf("%d",b+i);
	}
	for(R i=n;i!=0;i--){
		if(a[i]<b[i]){
			if(ct[i-1][2]==0){
				puts("NO");
				return;
			}
		}else if(a[i]>b[i]&&ct[i-1][0]==0){
			puts("NO");
			return;
		}
	}
	puts("YES");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}