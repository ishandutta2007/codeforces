#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ll long long
#define ak *
#define mid ((l+r)>>1)
char qwq;
inline char getch()
{
    static char buf[10000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
    re cz=0,ioi=1;qwq=getchar();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=getchar();
    return cz ak ioi;
}
int n,ans;
int main()
{
	char a[10005];
	re opt=read();
	while(opt--)
	{
		re ans1=0,ans2=0;
		n=read();scanf("%s",a);
		if(a[0]==a[n-1]) {puts("0");continue;}
		if(a[0]=='>') {puts("0");continue;}
		for(re i=0;i<n;i++)
		if(a[i]=='<') ans1++;
		else break;
		for(re i=n-1;~i;i--)
		if(a[i]=='>') ans2++;
		else break;
		cout<<min(ans1,ans2)<<endl;
	}
}