#include<cstdio>
const int Pow2[21]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
int n,l,r,s;
int main(){
	scanf("%d%d%d",&n,&l,&r);
	for(int i=0;i<l;i++)
	  s+=Pow2[i];
	printf("%d ",s+(n-l));
	for(int i=l;i<r;i++)
	  s+=Pow2[i];
	printf("%d" ,s+(n-r)*Pow2[r-1]);
	return 0;
}