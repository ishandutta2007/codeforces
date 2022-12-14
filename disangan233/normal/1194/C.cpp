#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ll long long
#define db double
#define ak *
#define in inline
in char getch()
{
	static char buf[10000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
char qwq;
#define gc() getchar()
in int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
const int N=105,M=1e6+5;
int cnt[26],cot[26];
char a[N],b[N],c[N];
int main()
{
	re t=read();
	while(t--)
	{
		scanf("%s %s %s",a+1,b+1,c+1);
		re na=strlen(a+1),nb=strlen(b+1),nc=strlen(c+1);
		memset(cnt,0,sizeof(cnt));memset(cot,0,sizeof(cot));
		for(re i=1;i<=nc;i++) cnt[c[i]-'a']++;
		re nw=1;
		for(re i=1;i<=nb;i++)
		{
			if(nw<=na&&a[nw]==b[i]) nw++;
			else cot[b[i]-'a']++;
		}
		if(nw!=na+1) puts("NO");
		else
		{
			re op=1;
			for(re i=0;i<26;i++)
			if(cnt[i]<cot[i]) {op=0;break;}
			puts(op?"YES":"NO");
		}
	}
}