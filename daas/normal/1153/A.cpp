#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<queue>
using namespace std;
inline int read()
{
    int kkk=0,x=1;
    char c=getchar();
    while((c<'0' || c>'9') && c!='-')
        c=getchar();
    if(c=='-')
        c=getchar(),x=-1;
    while(c>='0' && c<='9')
        kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
    return kkk*x;
}
int n,t,ans,minn=0x7f7f7f7f;
int main()
{
	n=read(),t=read();
	for(register int i=1;i<=n;++i)
	{
		int fi=read(),di=read();
		if(fi>=t && fi<minn)
			ans=i,minn=fi;
		else
		{
			int K=t-fi;
			int P=0;
			while(di*P<K)
				++P;
			if(fi+P*di<minn)
				ans=i,minn=fi+P*di;
		}
	}
	printf("%d\n",ans);
    return 0;
}