#include<cstdio>
#include<algorithm>
const int N=1e5+1;
int m,n,a[N],s;
inline bool Cmp(const int&a,const int&b){return a>b;}
int main(){
	scanf("%d%d%d",&n,&m,&m);m--;
	for(int i=1;i<=n;i++)scanf("%d",a+i);s=a[n]-a[1]+1;
	for(int i=1;i<n;i++)a[i]=a[i+1]-a[i]-1;
	std::sort(a+1,a+n,Cmp);
	for(int i=1;i<=m;i++)s-=a[i];
	printf("%d",s);
	return 0;
}