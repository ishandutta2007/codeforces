#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,cnt[10],n;
char s[4][MAXN*2],ans[MAXN*3];
void solve(int ix,int iy,int type)
{
	int len=0,bj=1;
	//cout<<"??? "<<ix<<" "<<iy<<" "<<type<<endl;
	for(int i=1;i<=2*n;++i)
	{
		while(bj<=2*n && s[iy][bj]-'0'==type) ans[++len]=s[iy][bj],++bj;
		ans[++len]=s[ix][i];
		if(s[ix][i]-'0'!=type && bj<=2*n) ++bj;
	}
	while(bj<=2*n) ans[++len]=s[iy][bj],++bj;
	//while(len<3*n) ans[++len]='0';
	for(int i=1;i<=len;++i) printf("%c",ans[i]);
	putchar('\n');
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		scanf("%s%s%s",s[1]+1,s[2]+1,s[3]+1);
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=2*n;++i)
		{
			if(s[1][i]=='1') ++cnt[1];
			if(s[2][i]=='1') ++cnt[2];
			if(s[3][i]=='1') ++cnt[3];
		}
		int cho=0;
		if(cnt[1]<=n) ++cho;
		if(cnt[2]<=n) ++cho;
		if(cnt[3]<=n) ++cho;
		//cout<<"??? "<<cho<<endl;
		int a=0,b=0;
		if(cho>1)
		{
			if(cnt[1]<=n) b=a,a=1;
			if(cnt[2]<=n) b=a,a=2;
			if(cnt[3]<=n) b=a,a=3;
			if(cnt[a]>cnt[b]) swap(a,b);
			solve(a,b,1);
		}
		else
		{
			if(cnt[1]>n) b=a,a=1;
			if(cnt[2]>n) b=a,a=2;
			if(cnt[3]>n) b=a,a=3;
			if(cnt[a]<cnt[b]) swap(a,b);
			solve(a,b,0);
		}
	}
	return 0;
}