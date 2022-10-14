// Problem: B. Dynamic Problem Scoring
// Contest: Codeforces - Codeforces Round #412 (rated, Div. 1, based on VK Cup 2017 Round 3)
// URL: https://codeforces.com/contest/806/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
struct node
{
	int a,b,c,d,e;
}pp[1000003];
int A,B,C,D,E;
const int p[]={-1,1,1,1,1,1,1};
const int q[]={1,32,16,8,4,2,1};
int t[13];
namespace solve
{
	bool cmp(int x,int y,int z,int w)//frac a>frac b
	{
		if(z==-1) return 0;
		return x*w<y*z;
	}
	bool ccmp(int x,int y,int z,int w)//frac a>frac b
	{
		if(z==-1) return 0;
		return x*w<=y*z;
	}
	int qwq(int l,int r,int n,int op){
			if(op==0)if(ccmp(r,n,p[op],q[op])||cmp(p[op+1],q[op+1],l,n)) return 0;
			if(op!=0)if(ccmp(r,n,p[op],q[op])||cmp(p[op+1],q[op+1],l,n)) return 0;
			return 1;
	}
};
const int s[]={3000,2500,2000,1500,1000,500};
signed main()
{
	int n=read();
	for(int i=1; i<=n; i++) 
	{
		pp[i].a=read(),pp[i].b=read(),pp[i].c=read(),pp[i].d=read(),pp[i].e=read();
		if(pp[i].a!=-1) ++A;
		 if(pp[i].b!=-1) ++B;
		 if(pp[i].c!=-1) ++C;
		 if(pp[i].d!=-1) ++D;
		 if(pp[i].e!=-1) ++E;
	}
	int ans=1000000008;
	for(t[0]=0; t[0]<6; t[0]++)
	for(t[1]=0; t[1]<6; t[1]++)
	for(t[2]=0; t[2]<6; t[2]++)
	for(t[3]=0; t[3]<6; t[3]++)
	for(t[4]=0; t[4]<6; t[4]++)
	{
		int d=0;
		//printf("%lld\n",S);
		if(pp[1].a!=-1) d+=s[t[0]]-s[t[0]]/250*pp[1].a;
		if(pp[1].b!=-1) d+=s[t[1]]-s[t[1]]/250*pp[1].b;
		if(pp[1].c!=-1) d+=s[t[2]]-s[t[2]]/250*pp[1].c;
		if(pp[1].d!=-1) d+=s[t[3]]-s[t[3]]/250*pp[1].d;
		if(pp[1].e!=-1) d+=s[t[4]]-s[t[4]]/250*pp[1].e;
		if(pp[2].a!=-1) d-=s[t[0]]-s[t[0]]/250*pp[2].a;
		if(pp[2].b!=-1) d-=s[t[1]]-s[t[1]]/250*pp[2].b;
		if(pp[2].c!=-1) d-=s[t[2]]-s[t[2]]/250*pp[2].c;
		if(pp[2].d!=-1) d-=s[t[3]]-s[t[3]]/250*pp[2].d;
		if(pp[2].e!=-1) d-=s[t[4]]-s[t[4]]/250*pp[2].e;
		if(d>0) 
		{
			for(int j=0; j<=4000; ++j)
			{
				int f=0;
				if(solve::qwq(A,A+(j*(pp[1].a!=-1)),n+j,t[0])) ++f;
				if(solve::qwq(B,B+(j*(pp[1].b!=-1)),n+j,t[1])) ++f;
				if(solve::qwq(C,C+(j*(pp[1].c!=-1)),n+j,t[2])) ++f;
				if(solve::qwq(D,D+(j*(pp[1].d!=-1)),n+j,t[3])) ++f;
				if(solve::qwq(E,E+(j*(pp[1].e!=-1)),n+j,t[4])) ++f;
				if(f==5)
				{
					// if(j==1)
					// printf("%lld\n",d),
					// printf("%lld %lld %lld %lld %lld\n",t[0],t[1],t[2],t[3],t[4]),
					// printf("%lld %lld %lld %lld\n",D,D+(j*(pp[1].d!=-1)),n+j,t[3]);
					ans=min(ans,j);
					break;
				}
			}
		}
	}
	if(ans==1000000008) puts("-1");
	else printf("%lld\n",ans);
    return 0;
}