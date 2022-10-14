// Problem: F. Maximum Balanced Circle
// Contest: Codeforces - Codeforces Round #555 (Div. 3)
// URL: https://codeforces.com/contest/1157/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int cnt[1000003];
signed main()
{
	int n=read();
	for(int i=1; i<=n; i++) ++cnt[read()];
	int Ans=0,L=0,R=0;
	//for(int i=1; i<=10; i++) printf("%d ",cnt[i]);
	//puts("");
	for(int l=1,r=1,A=0; r<=250000; ++r)
	{
		A+=cnt[r];
		if(cnt[r]>=2){
		while(cnt[l]<2) A-=cnt[l],++l;
		while(!cnt[l-1]) A-=cnt[l],++l;
		}
		else l=r+1,A=0;
		if(A+cnt[l-1]+cnt[r+1]>=Ans)
		{
			Ans=A+cnt[l-1]+cnt[r+1];
			L=l-1,R=r+1;
			//printf("%d %d\n",L,R);
		}
	}
	for(int i=1; i<250000; ++i) if(Ans<cnt[i]+cnt[i+1])
	{
		Ans=cnt[i]+cnt[i+1];
		L=i,R=i+1;
	}
	printf("%d\n",Ans);
	//printf("%d %d\n",L,R);
	for(int i=L; i<=R; ++i) if(cnt[i]) printf("%d ",i);
	for(int i=R; i>=L; --i) for(int j=1; j<cnt[i]; ++j) printf("%d ",i); 
    return 0;
}