#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 100000
struct P{int b,p;};
bool cmp(P a,P b){return a.p<b.p;}
vector<P> vc,vd;
int main()
{
	int n,c,d,i,j,k,x,a,b,ans=0;char s[5];
	n=read();c=read();d=read();
	for(i=1;i<=n;++i)
	{
		a=read();b=read();scanf("%s",s);
		(s[0]=='C'?vc:vd).push_back((P){a,b});
	}
	sort(vc.begin(),vc.end(),cmp);
	sort(vd.begin(),vd.end(),cmp);
	for(i=a=0;i<vc.size();++i)if(vc[i].p<=c)a=max(a,vc[i].b);
	for(i=b=0;i<vd.size();++i)if(vd[i].p<=d)b=max(b,vd[i].b);
	if(a&&b)ans=a+b;
	for(i=vc.size(),j=a=b=0,k=-1;i--;)
	{
		for(;j<vc.size()&&vc[i].p+vc[j].p<=c;++j)
			if(vc[j].b>a)b=a,a=vc[j].b,k=j;
			else if(vc[j].b>b)b=vc[j].b;
		if(x=i==k?b:a)ans=max(ans,vc[i].b+x);
	}
	for(i=vd.size(),j=a=b=0,k=-1;i--;)
	{
		for(;j<vd.size()&&vd[i].p+vd[j].p<=d;++j)
			if(vd[j].b>a)b=a,a=vd[j].b,k=j;
			else if(vd[j].b>b)b=vd[j].b;
		if(x=i==k?b:a)ans=max(ans,vd[i].b+x);
	}
	printf("%d",ans);
}