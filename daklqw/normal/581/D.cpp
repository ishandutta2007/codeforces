#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using std::swap;
using std::sort;
struct lr{
	int l,r;
	char c;
	lr(int aa=0,int b=0,char c=0):l(aa),r(b),c(c){}
	bool operator <(const lr& rhs)const{
		if(r!=rhs.r)return r>rhs.r;
		return l<rhs.l;
	}
}a[4];
int l1,l2,l3,r1,r2,r3;
char res[110][110];
int main(){
	scanf("%d%d%d%d%d%d",&l1,&r1,&l2,&r2,&l3,&r3);
	int t=l1*r1+l2*r2+l3*r3;
	if(int(sqrt(t)+1e-8)*int(sqrt(t)+1e-8)!=t){puts("-1");return 0;}
	int t2=int(sqrt(t)+1e-8);
	if(l1>t2||l2>t2||l3>t2||r1>t2||r2>t2||r3>t2){puts("-1");return 0;}
	if(l1>r1)swap(l1,r1);if(l2>r2)swap(l2,r2);if(l3>r3)swap(l3,r3);
	a[1]=lr(l1,r1,'A');
	a[2]=lr(l2,r2,'B');
	a[3]=lr(l3,r3,'C');
	if(r1==r2&&r2==r3&&r1==t2&&l1+l2+l3==t2){
		printf("%d\n",t2);
		for(int i=1;i<=l1;++i,putchar('\n'))
			for(int j=1;j<=r1;++j)putchar('A');
		for(int i=1;i<=l2;++i,putchar('\n'))
			for(int j=1;j<=r1;++j)putchar('B');
		for(int i=1;i<=l3;++i,putchar('\n'))
			for(int j=1;j<=r1;++j)putchar('C');
		return 0;
	}
	sort(a+1,a+4);
	if(a[1].r!=t2){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=a[1].l;++i)
	for(int j=1;j<=a[1].r;++j)
	res[i][j]=a[1].c;
	if(a[2].l==a[3].l);else
	if(a[2].r==a[3].r){
		swap(a[2].l,a[2].r);
		swap(a[3].l,a[3].r);
	}else
	swap(a[2].l,a[2].r);
	if(a[2].l==a[3].l);else
	if(a[2].r==a[3].r){
		swap(a[2].l,a[2].r);
		swap(a[3].l,a[3].r);
	}
	for(int i=1;i<=a[2].l;++i){
		for(int j=1;j<=a[2].r;++j)res[i+a[1].l][j]=a[2].c;
		for(int j=1;j<=a[3].r;++j)res[i+a[1].l][j+a[2].r]=a[3].c;
	}
	printf("%d\n",t2);
	for(int i=1;i<=t2;++i){
		for(int j=1;j<=t2;++j)putchar(res[i][j]);
		putchar('\n');
	}
	return 0;
}