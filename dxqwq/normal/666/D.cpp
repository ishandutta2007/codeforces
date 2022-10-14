// Problem: D. Chain Reaction
// Contest: Codeforces - Codeforces Round #349 (Div. 1)
// URL: https://codeforces.com/problemset/problem/666/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int N=4;
struct point{int x,y;}a[13],b[13],res[13];
int dis(point A,point B){return abs(A.x-B.x)+abs(A.y-B.y);}
bool chk(point A,point B){return (A.x==B.x)||(A.y==B.y);}
int ans,p[4];
void solve()
{
	for(int i=0; i<N; ++i) p[i]=i;
	do
	{
		int sum=0;
		bool flg=1;
		for(int i=0; i<N&&flg; ++i)
			flg&=chk(a[i],b[p[i]]);
		if(!flg) continue;
		for(int i=0; i<N; ++i)
			sum=max(sum,dis(a[i],b[p[i]]));
		if(sum<ans)
		{
			ans=sum;
			for(int i=0; i<N; ++i) 
				res[i]=b[p[i]];
		}
	}
	while(next_permutation(p,p+N));
	return ;
}
void Diana()
{
	ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0; i<N; ++i)
		a[i].x=read(),a[i].y=read();
	for(int s=0; s<16; s++)
	{
		vector<int> vx,vy;
		for(int i=0; i<N; i++)
		{
			if((1<<i)&s) vy.push_back(a[i].y);
			else vx.push_back(a[i].x);
		}
		sort(vx.begin(),vx.end()),
		vx.erase(unique(vx.begin(),vx.end()),vx.end()),
		sort(vy.begin(),vy.end()),
		vy.erase(unique(vy.begin(),vy.end()),vy.end());
		bool rev=0;
		if(vx.size()<vy.size())
			swap(vx,vy),rev=1;
		if(vx.size()==2&&vy.size()==2)
		{
			if(vx[1]-vx[0]!=vy[1]-vy[0]) continue;
			for(int i=0; i<N; ++i)
				b[i]=(point){vx[i>>1],vy[i&1]};
			if(rev) for(int i=0; i<N; ++i) swap(b[i].x,b[i].y);
			solve();
		}
		if(vx.size()==2&&vy.size()==1)
		{
			vy.push_back(vy[0]+vx[1]-vx[0]);
			for(int i=0; i<N; ++i)
				b[i]=(point){vx[i>>1],vy[i&1]};
			if(rev) for(int i=0; i<N; ++i) swap(b[i].x,b[i].y);
			solve();
			vy[1]=vy[0],vy[0]=vy[1]-vx[1]+vx[0];
			for(int i=0; i<N; ++i)
				b[i]=(point){vx[i>>1],vy[i&1]};
			if(rev) for(int i=0; i<N; ++i) swap(b[i].x,b[i].y);
			solve();
		}
		if(vx.size()==2&&vy.size()==0)
		{
			vector<int> ta,tb;
			if(rev) 
				for(int i=0; i<N; ++i) 
					if(a[i].y==vx[0]) ta.push_back(a[i].x);
					else tb.push_back(a[i].x);
			else
				for(int i=0; i<N; ++i) 
					if(a[i].x==vx[0]) ta.push_back(a[i].y);
					else tb.push_back(a[i].y);
			sort(ta.begin(),ta.end()),sort(tb.begin(),tb.end());
			if(ta.size()!=tb.size()) continue;
			vector<int> Q={ta[0],tb[0],ta[1]-vx[1]+vx[0],tb[1]-vx[1]+vx[0]};
			sort(Q.begin(),Q.end());
			int Z=(Q[0]+Q[3])>>1;
			vector<int> vz={Z,Z+vx[1]-vx[0]};
			for(int i=0; i<N; ++i)
				b[i]=(point){vx[i>>1],vz[i&1]};
			if(rev) for(int i=0; i<N; ++i) swap(b[i].x,b[i].y);
			solve();  
		}
	}
	if(ans>1e18) puts("-1");
	else
	{
		printf("%lld\n",ans);
		for(int i=0; i<N; i++)
			printf("%lld %lld\n",res[i].x,res[i].y);
	}
	return ;
}
signed main()
{
	for(int T=read(); T--;) Diana();
	return 0;
}