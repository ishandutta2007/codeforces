#include<bits/stdc++.h>
using namespace std;
#define in inline
#define db double
#define ll long long
#define ull unsigned ll
#define re register int
#define ak *
in char getch()
{
	char buf[10000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
char qwq;
#define gc() getch()
in int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
const int N=1e6+5;
int n,na,nb;
char a[N],b[N];
int main()
{
	scanf("%d",&n);
	for(re i=1;i<=n;i++)
	{
		scanf("%s %s",a+1,b+1);
		na=strlen(a+1),nb=strlen(b+1);
		re op=1;
		for(re j=1,k=1;j<=na&&k<=nb;)
		{
			if(b[k]!=a[j]) {op=0;break;}
			re ca=0,cb=1; 
			while(b[k]==a[j]) ca++,k++;
			while(a[j]==a[j+1]) cb++,j++;
			if(cb>ca) {op=0;break;}
			j++;
			if(j>na&&k<=nb) op=0;
			if(k>nb&&j<=na) op=0;
		} 
		puts(op?"YES":"NO"); 
	}
}