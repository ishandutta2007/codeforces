#include <cstdio>
int main(){
	int n,l1=-1;
	long long in,ans=1;
	scanf("%d",&n);
	for(int k=0;k<n;k++){
		scanf("%I64d",&in);
		if(in==1){
			if(l1!=-1)ans*=(long long)(k-l1);
			l1=k;
		}
	}
	printf("%I64d",l1==-1?0:ans);
	return 0;
};