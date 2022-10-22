#include<cstdio>
#include<algorithm>
const int N=1001;
int n,m,a[N],b[N];
inline bool Check(int k){
	int s=0;
	for(int i=1;i<=k;i++)b[i]=a[i];
	std::sort(b+1,b+1+k);
	for(int i=k;i>0;i-=2){s+=b[i];if(s>m)return 0;} 
	return 1;
}
int main(){
	int l,r,md;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(l=1,r=n;l<r;)md=l+r+1>>1,Check(md)?l=md:r=md-1;
	printf("%d",r);
	return 0;
}