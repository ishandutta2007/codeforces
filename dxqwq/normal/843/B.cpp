#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while('0'<=ch && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
mt19937 rnd(7872754);
unordered_map<int,bool> mp;
signed main()
{
	int n=read(),s=read(),t=read(),res,nxt;
	printf("? %lld\n",s),mp[s]=1;
	fflush(stdout),res=read(),nxt=read();
	if(res>=t) printf("! %lld\n",res),fflush(stdout),exit(0);
	int Sdt=nxt,Max=res,mans=1000000007;
	for(int i=1; i<=999; i++)
	{
		int q=rnd()%n+1;
		if(mp[q]) q=rnd()%n+1;
		printf("? %lld\n",q);
		fflush(stdout);
		res=read(),nxt=read();
		if(res<t) 
		{
			if(res>Max) Max=res,Sdt=nxt;
		}
		else mans=min(mans,res);
	}
	if(mans==t) printf("! %lld\n",mans),fflush(stdout),exit(0);
	else
	{
		for(int i=1; i<=1000; i++)
		{
			if(Sdt==-1) puts("! -1"),fflush(stdout),exit(0);
			printf("? %lld\n",Sdt);
			fflush(stdout);
			res=read(),nxt=read();
			if(res>=t) printf("! %lld\n",res),fflush(stdout),exit(0);
			else Sdt=nxt;
		}
		printf("! %lld\n",mans),fflush(stdout),exit(0);
	}
	return 0;
}