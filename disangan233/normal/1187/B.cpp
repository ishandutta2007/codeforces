#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int
#define db double
#define ak *
#define in inline
in char getch()
{
	static char buf[1<<12],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<!2,stdin),p1==p2)?EOF:*p1++;
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
int n,cnt[26],cntt[26],a[26][200005];
char s[200005],t[200005];
int main()
{
	n=read();scanf("%s",s+1);
	for(re i=1;i<=n;i++) cnt[s[i]-'a']++,a[s[i]-'a'][cnt[s[i]-'a']]=i;
	for(re i=0;i<26;i++) sort(a[i]+1,a[i]+cnt[i]+1);
	re m=read();
	while(m--)
	{
		memset(cntt,0,sizeof(cntt));
		scanf("%s",t+1);
		re k=strlen(t+1),ans=0;
		for(re i=1;i<=k;i++) cntt[t[i]-'a']++;
		for(re i=0;i<26;i++) ans=max(ans,a[i][cntt[i]]);
		printf("%d\n",ans);
	}
}