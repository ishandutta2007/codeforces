#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ak *
#define ll long long
inline char getch()
{
	static char buf[10000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
#define gc() getchar()
char qwq;
inline int read()
{
	re cz=0,ioi=1;
	qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
long long f[105][3];
int n,cnt[26],ans;
int main()
{
	n=read();
	f[0][0]=1;
	for(re i=1;i<=n;i++) f[i][0]=1;
	for(re i=1;i<=n;i++)
	for(re j=1;j<=2;j++)
	f[i][j]=f[i-1][j-1]+f[i-1][j];
	for(re i=1;i<=n;i++)
	{
		char ch[1005];
		scanf("%s",ch);
		cnt[ch[0]-'a']++;
	}
	for(re i=0;i<26;i++) 
	if(cnt[i])
	{
		re a=cnt[i]/2,b=cnt[i]-a;
		ans+=f[a][2]+f[b][2];
	}
	cout<<ans;
	return 0;
}