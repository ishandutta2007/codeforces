#include<cstdio>
const int N=2e5+3,Dx[4]={0,1,0,-1},Dy[4]={1,0,-1,0};
int n,x[N],y[N],a,b,s[4],p;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)scanf("%d%d",x+i,y+i);
	for(int k=0,aa,bb;k<4;k++){
	  aa=a+Dx[k],bb=b+Dy[k];
	  for(int i=1;i<=n;i++)
		if((x[i]<=aa&&aa<=a||x[i]>=aa&&aa>=a)&&(y[i]<=bb&&bb<=b||y[i]>=bb&&bb>=b))
		  s[k]++;
	  p=s[k]>s[p]?k:p;
	}printf("%d\n%d %d",s[p],a+Dx[p],b+Dy[p]);
	return 0;
}