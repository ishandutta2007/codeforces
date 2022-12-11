#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
const int MN=1e5;
int r[MN+5];
int main()
{
	int n,s,i,cnt=0;
	n=read();s=read();
	for(i=1;i<n;++i)++r[read()],++r[read()];
	for(i=1;i<=n;++i)if(r[i]==1)++cnt;
	printf("%.10lf",(double)s/cnt*2);
}