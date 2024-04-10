#include<cstdio>
int main(){
	int n,t,m,k,i,j,l,r;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d%d%d%d",&n,&m,&k,&l);
		bool f=true;
		for(j=1;j<n;j++){
			scanf("%d",&r);
			if(l+m+k<r){
				f=false;
			}
			if(l+k-r>l){
				m+=l;
			}else{
				m+=l+k-r;
			}
			l=r;
		}
		if(f==true){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}