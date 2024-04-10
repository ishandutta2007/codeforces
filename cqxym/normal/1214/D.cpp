#include<stdio.h>
bool v[2000000],c[2000000],d[2000000];
int s[1000001];
int main(){
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	char q;
	for(i=0;i<n;i++){
		scanf("%c",&q);
		for(j=0;j<m;j++){
			scanf("%c",&q);
			if(q=='.'){
				v[i*m+j]=true;
			}
		}
	}
	c[n*m-1+m]=true;
	for(i=n-1;i>-1;i--){
		for(j=m-1;j>-1;j--){
			if(((c[i*m+j+1]==true&&j<m-1)||c[i*m+j+m]==true)&&v[i*m+j]==true){
				c[i*m+j]=true;
			}
		}
	}
	d[0]=true;
	for(i=1;i<m;i++){
		if(v[i]==true&&d[i-1]==true){
			d[i]=true;
		}
	}
	for(i=m;i<n*m;i+=m){
		if(v[i]==true&&d[i-m]==true){
			d[i]=true;
		}
	}
	for(i=1;i<n;i++){
		for(j=1;j<m;j++){
			if(((d[i*m+j-1]==true&&j>0)||d[i*m+j-m]==true)&&v[i*m+j]==true){
				d[i*m+j]=true;
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if((c[i*m+j]&d[i*m+j])==1){
				s[i+j]++;
			}
		}
	}
	for(i=1;i<m+n-2;i++){
		if(s[i]<2){
			printf("%d",s[i]);
			return 0;
		}
	}
	printf("2");
	return 0;
}