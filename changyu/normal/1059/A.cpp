#include<cstdio>
#include<algorithm>
const int N=1e5+2;
struct person{int a,l;}a[N];
inline bool cmp(person a,person b){return a.a<b.a;}
int n,m,l,s;
int main(){
	scanf("%d%d%d",&n,&l,&m);
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&a[i].a,&a[i].l);
	a[++n]=(person){l,0};
	std::sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	  s+=(a[i].a-a[i-1].l-a[i-1].a)/m;
	printf("%d",s);
	return 0;
}