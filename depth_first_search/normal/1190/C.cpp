#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
using namespace std;
int n,k,a[N+5],Mn[2],Mx[2],lst[N+5][2],nxt[N+5][2];
int main()
{
	RI i;char c;for(cin>>n>>k,i=1;i<=n;++i) cin>>c,a[i]=c&1;
	for(i=1;i<=n;++i) Mx[a[i]]=i;for(Mn[0]=Mn[1]=n+1,i=n;i;--i) Mn[a[i]]=i;
	if(Mx[0]-Mn[0]+1<=k||Mx[1]-Mn[1]+1<=k) return puts("tokitsukaze"),0;
	for(i=1;i<=n;++i) lst[i][0]=lst[i-1][0],lst[i][1]=lst[i-1][1],lst[i][a[i]]=i;
	nxt[n+1][0]=nxt[n+1][1]=n+1;
	for(i=n;i>=1;--i) nxt[i][0]=nxt[i+1][0],nxt[i][1]=nxt[i+1][1],nxt[i][a[i]]=i;
	for(i=1;i+k-1<=n;++i)
	{
		if(i<=Mn[0]&&Mn[0]<=i+k-1&&Mx[0]-nxt[i+k][0]+1<=k) goto Point;
		if(i<=Mx[0]&&Mx[0]<=i+k-1&&lst[i-1][0]-Mn[0]+1<=k) goto Point;
		return puts("once again"),0;Point:
		if(i<=Mn[1]&&Mn[1]<=i+k-1&&Mx[1]-nxt[i+k][1]+1<=k) continue;
		if(i<=Mx[1]&&Mx[1]<=i+k-1&&lst[i-1][1]-Mn[1]+1<=k) continue;
		return puts("once again"),0;
	}return puts("quailty"),0;
}