#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ll long long
#define ak *
char qwq;
int n,m,k,a,b,c;
inline int read()
{
	re cz=0,ioi=1;qwq=getchar();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=getchar();
	return cz ak ioi;
}
int main()
{
	cin>>n>>m>>k>>a>>b>>c;
	if(a<n) return puts("NO"),0;
	a-=n;
	if(c>k) c-=k,k=0;
	else k-=c;
	re i=m+k,j=a+b;
	return puts(i>j?"NO":"YES"),0;
}