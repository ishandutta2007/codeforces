#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MN 300000
char a[MN+5],b[MN+5],c[MN+5];
bool cmp(char x,char y){return x>y;}
int main()
{
	int n,i,al,ar,bl,br,cl,cr;
	scanf("%s%s",a,b);n=strlen(a);
	sort(a,a+n);sort(b,b+n,cmp);
	al=0;ar=n+1>>1;bl=0;br=n>>1;cl=0;cr=n;
	for(i=0;i<n;++i)
		if(i&1)
			if(b[bl]>a[al])c[cl++]=b[bl++];
			else c[--cr]=b[--br];
		else
			if(a[al]<b[bl])c[cl++]=a[al++];
			else c[--cr]=a[--ar];
	puts(c);
}