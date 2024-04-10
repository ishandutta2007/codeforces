#include<cstdio>
int main(){
	int n,x,i,m;
	long long s;
	scanf("%d%d",&n,&m);
	s=m;
	for(i=1;i<n;i++){
		scanf("%d",&x);
		s+=x;
		if(x>m){
			m=x;
		}
	}
	if(s%2==1||m>s/2){
		printf("NO");
	}else{
		printf("YES");
	}
	return 0;
}