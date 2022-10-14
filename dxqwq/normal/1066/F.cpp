// Problem: F. Yet another 2D Walking
// Contest: Codeforces - Codeforces Round #515 (Div. 3)
// URL: https://codeforces.com/contest/1066/problem/F
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
pair<int,int> a[1000003];
int dis(int x,int y)
{
	int A=(a[x].first+a[x].second),C=(a[x].first-a[x].second);
	int B=(a[y].first+a[y].second),D=(a[y].first-a[y].second);
	//printf("%lld %lld %lld %lld\n",A,C,B,D);
	int R=abs(A-B)+abs(C-D);
	return R;
}
bool cmp(int x,int y)
{
	return abs(a[x].first)+abs(a[x].second)==
	abs(a[y].first)+abs(a[y].second);
}
bool ccmp(pair<int,int> X,pair<int,int> Y)
{
	if(abs(X.first)+abs(X.second)!=abs(Y.first)+abs(Y.second))
	return abs(X.first)+abs(X.second)<abs(Y.first)+abs(Y.second);
	int A=(X.first+X.second),C=(X.first-X.second);
	int B=(Y.first+Y.second),D=(Y.first-Y.second);
	if(A==B) return C>D;
	return A<B;
}
signed main()
{
	int n=read();
	for(int i=1; i<=n; i++) 
	{
		int AA=read(),BB=read();
		int A=(AA+BB),B=(AA-BB);
		a[i].second=B,
		a[i].first=A;
	}
	sort(a+1,a+n+1,ccmp);
	int lstl=0,lstr=0;
	int lans=0,rans=0;
	for(int l=1,r; l<=n; l=r+1)
	{
		r=l;
		while(r<n&&cmp(l,r+1)) ++r;
		///printf("%lld %lld\n",l,r);
		int q=min(dis(lstl,l)+lans,dis(lstr,l)+rans),
		p=min(dis(lstl,r)+lans,dis(lstr,r)+rans);
		lans=p+dis(l,r),rans=q+dis(l,r);
		lstl=l,lstr=r;
	}
	printf("%lld\n",min(lans,rans)/2);
    return 0;
}