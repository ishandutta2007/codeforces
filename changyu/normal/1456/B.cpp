#include<cstdio>
#include<algorithm>
const int N=1e5+3;
int n,a[N],b,c,ans;
inline int Xor(int l,int r){
	int x=0;
	for(int i=l;i<=r;i++)x^=a[i];
	return x;
}
int main(){
	ans=N;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",a+i);
	for(int i=1;i<n;i++){
	  b=a[i]^a[i+1];
	  if(i>1&&b<a[i-1]||i+1<n&&b>a[i+2])return 0*puts("1");
	}
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++){
		b=Xor(i,j);
		if(i>1&&b<a[i-1]||j<n&&b>a[j+1])ans=std::min(ans,j-i);
		for(int k=j+2;k<=n;k++){
		  c=Xor(j+1,k);
		  if(b>c)ans=std::min(ans,k-i-1);
		}
	  }
	printf("%d\n",ans==N?-1:ans);
	return 0;
}