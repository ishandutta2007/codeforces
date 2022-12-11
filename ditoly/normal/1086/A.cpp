#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
pair<int,int> p[3];
int main()
{
	int i,yl=1000,yr=0;
	for(i=0;i<3;++i)p[i].first=read(),p[i].second=read(),yl=min(yl,p[i].second),yr=max(yr,p[i].second);
	sort(p,p+3);
	printf("%d\n",yr-yl+1+p[2].first-p[0].first);
	for(i=yl;i<=yr;++i)printf("%d %d\n",p[1].first,i);
	for(i=p[0].first;i<p[1].first;++i)printf("%d %d\n",i,p[0].second);
	for(i=p[2].first;i>p[1].first;--i)printf("%d %d\n",i,p[2].second);
}