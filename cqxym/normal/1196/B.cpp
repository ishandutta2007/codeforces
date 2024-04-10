#include<cstdio>
int a[200001];
int main(){
	int t,i,j,n,x,ct,k;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d%d",&n,&k);
		ct=0;
		for(j=0;j<n;j++){
			scanf("%d",&x);
			if(x%2==1){
				a[ct]=j+1;
				ct++;
			}
		}
		if(ct>=k&&(ct-k&1)<1){
			puts("YES");
			for(j=0;j<k-1;j++){
				printf("%d ",a[j]);
			}
			printf("%d\n",n);
		}else{
			puts("NO");
		}
	}
	return 0;
}