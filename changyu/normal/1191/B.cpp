#include<cstdio>
#include<algorithm>
inline char get(){
	char c=getchar();
	for(;(c>57||c<48)&&(c>122||c<97);c=getchar());
	return c;
}
struct tile{char a,b;}a[3];
bool Cmp(tile a,tile b){return a.a<b.a;}
int main(){
	for(int i=0;i<3;i++)a[i].a=get(),a[i].b=get();
	std::sort(a,a+3,Cmp);
	if(a[0].b==a[1].b&&a[1].b==a[2].b&&a[1].a-a[0].a==a[2].a-a[1].a&&a[1].a-a[0].a<=1)
	  return 0*puts("0");
	for(int i=0;i<3;i++)
	  for(int j=i+1;j<3;j++)
		if(a[i].b==a[j].b&&a[j].a-a[i].a<=2)
		  return 0*puts("1");
	return 0*puts("2");
}