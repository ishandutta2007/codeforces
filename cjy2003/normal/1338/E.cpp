#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int n,in[8080],d[8080],p[8080],q[8080],pcnt,qcnt;
char s[2020];
bool mp[8080][8080];
long long ans;
char decode(char x)
{
	return x>=65?x-55:x-48;
}
int main()
{
	scanf("%d",&n);
	/*for(int i=1;i<=n;++i)
	{
		char s=getchar();
		int cur;
		for(int j=1;j<=n;j+=4)
		{
			s=getchar();
			cur=s>='0'&&s<='9'?s-'0':s-'A'+10;
			if(cur>>3)mp[i][j]=1,++in[j];
			if(cur>>2&1)mp[i][j+1]=1,++in[j+1];
			if(cur>>1&1)mp[i][j+2]=1,++in[j+2];
			if(cur&1)mp[i][j+3]=1,++in[j+3];
		}
	}*/
	for(int i=1; i<=n; i++)
	{
		char ch = getchar();
		for(int j=4; j<=n; j+=4)
		{
			ch = decode(getchar());
			mp[i][j-3] = (ch&8)>>3,mp[i][j-2] = (ch&4)>>2,mp[i][j-1] = (ch&2)>>1,mp[i][j] = ch&1;
		}
	}
	for(int i=1; i<=n; i++) for(int j=i+1; j<=n; j++)
	{
		if(mp[i][j]) {in[j]++;} else {in[i]++;}
	}
	for(int i=1;i<=n;++i)d[i]=i;
	sort(d+1,d+1+n,[&](int x,int y){return in[x]<in[y];});
	int mid=0;
	for(int i=1;i<=n;++i)
	{
		if(in[d[i]]!=i-1){mid=i;break;}
		ans+=(614ll*n+1)*(n-i);
	}
	if(!mid)return printf("%lld",ans),0;
	p[pcnt=1]=d[mid];
	for(int i=mid+1;i<=n;++i)
	{
		if(mp[d[i]][d[mid]])p[++pcnt]=d[i];
		else q[++qcnt]=d[i];
	}
	sort(p+1,p+1+pcnt,[&](int x,int y){return mp[x][y];});
	sort(q+1,q+1+qcnt,[&](int x,int y){return mp[x][y];});
	ans+=3*pcnt*(pcnt-1)/2+3*qcnt*(qcnt-1)/2+3*pcnt*qcnt;
	for(int i=1,last=1,inq=1;i<=pcnt;++i)
	{
		if(!mp[q[inq]][p[i]])
		{
			last=i;
			while(inq<=qcnt&&!mp[q[inq]][p[i]])++inq;
		}
		ans+=i-last;
	}
	for(int i=1,last=1,inp=1;i<=qcnt;++i)
	{
		if(!mp[p[inp]][q[i]])
		{
			last=i;
			while(inp<=pcnt&&!mp[p[inp]][q[i]])++inp;
		}
		ans+=i-last;
		ans+=mp[p[1]][q[i]];
	}
	printf("%lld",ans);
	return 0;
}