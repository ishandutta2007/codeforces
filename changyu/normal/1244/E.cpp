#include<cstdio>
#include<algorithm>
const int N=1e5+3;
int n,a[N];long long m,b[N];
inline bool Check(int g){
	for(int i=1,j=1;i<=n;i++){
	  for(;a[i]-a[j]>g;j++);
	  if(((long long)(j-1)*(a[i]-g)-b[j-1])+(b[n]-b[i]-(long long)(n-i)*a[i])<=m)return 1;
	}
	for(int i=n,j=n;i;i--){
	  for(;a[j]-a[i]>g;j--);
	  if(((long long)(i-1)*a[i]-b[i-1])+(b[n]-b[j]-(long long)(n-j)*(a[i]+g))<=m)return 1;
	}return 0;
}
int main(){
	int l,r,md;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(l=0,r=0x3f3f3f3f;l<r;)md=l+r>>1,Check(md)?r=md:l=md+1;
	printf("%d",l);
	return 0;
}