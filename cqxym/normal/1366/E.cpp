#include<stdio.h>
#define R register int
#define N 200002
int a[N],b[N],lf[N],rt[N],pos[N];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for(R i=1;i<=m;i++){
		scanf("%d",b+i);
	}
	lf[m+1]=n+1;
	for(R i=m;i!=0;i--){
		rt[i]=lf[i+1]-1;
		int mn=2e9,lt=rt[i];
		while(lt!=0&&a[lt]!=b[i]){
			mn=mn<a[lt]?mn:a[lt];
			lt--;
		}
		if(lt==0||mn<b[i]){
			putchar('0');
			return 0;
		}
		pos[i]=lt;
		while(lt!=0&&a[lt]>=b[i]){
			lt--;
		}
		lf[i]=lt+1;
	}
	if(lf[1]!=1){
		putchar('0');
		return 0;
	}
	int ans=1;
	for(R i=m;i!=1;i--){
		ans=(long long)ans*(pos[i]-rt[i-1])%998244353;
	}
	printf("%d",ans);
	return 0;
}