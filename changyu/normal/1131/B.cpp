#include<cstdio>
#include<set>
int a,b,c,d,n,s;
int main()
{
	scanf("%d",&n);
	for(;n--;){
	  scanf("%d%d",&c,&d);
	  s+=std::max(std::min(c,d)-std::max(a,b)+1,0)-(c==d&&n);
	  a=c,b=d;
	}printf("%d",s);
	return 0;
}