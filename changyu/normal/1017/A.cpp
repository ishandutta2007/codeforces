#include<cstdio>
#include<algorithm>
struct student{int a,p;}a[1001],x;
inline bool cmp(student a,student b){return a.a==b.a?a.p<b.p:a.a>b.a;}
int n,b,c,d;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d%d",&a[i].a,&b,&c,&d),a[i].a+=b+c+d;
	x=a[1];
	std::sort(a+1,a+1+n,cmp);
	printf("%d",std::lower_bound(a+1,a+n+1,x,cmp)-a);
    return 0;
}