#include<stdio.h>
#define R register int
int a[5001];
inline void Min(int&x,int&y){
	x=x<y?x:y;
}
inline int Solve(int l,int r,int m){
	int minnum=2e9,res1=0,res2=r-l+1;
	for(R i=l;i<=r;i++){
		Min(minnum,a[i]);
	}
	int lt=l-1;
	for(R i=l;i<=r;i++){
		if(a[i]==minnum){
			if(lt<i-1){
				res1+=Solve(lt+1,i-1,minnum);
			}
			lt=i;
		}
	}
	if(lt!=r){
		res1+=Solve(lt+1,r,minnum);
	}
	res1+=minnum-m;
	return res1<res2?res1:res2;
}
int main(){
	int n,lt=0,ans=0;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]==0){
			if(lt<i-1){
				ans+=Solve(lt+1,i-1,0);
			}
			lt=i;
		}
	}
	if(lt!=n){
		ans+=Solve(lt+1,n,0);
	}
	printf("%d",ans);
	return 0;
}