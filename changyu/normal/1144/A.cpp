#include<cstdio>
int m,b[28],t[1000],k;char a[102]; 
signed main(){
	scanf("%d",&m);
	for(;m--;){
	  scanf("%s",a+1);
	  for(int j=0;j<28;j++)b[j]=0;
	  for(int i=1;a[i];i++)b[a[i]-96]++;
	  k=0;
	  for(int j=27;j;j--){b[j]=b[j]-b[j-1];if(b[j])t[++k]=b[j];}
	  puts(k==2&&t[1]==-1&&t[2]==1?"Yes":"No");
	}
	return 0;
}