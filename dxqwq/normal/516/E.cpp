// Problem: E. Drazil and His Happy Friends
// Contest: Codeforces - Codeforces Round #292 (Div. 1)
// URL: https://codeforces.com/problemset/problem/516/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#define int long long
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define lb lower_bound
#define mp make_pair
#define zky IOI_AKer
#define fi first
#define se second
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
vector<int> A[200003],B[200003];
int N=read(),M=read(),D=__gcd(N,M),ans=0;
void exgcd(int &x,int &y,int a,int b)
{
    if(!b)
    {
        x=1,y=0;
        return;
    }
    exgcd(x,y,b,a%b);
    int t=x;
    x=y,y=t-a/b*y;
}
int solve(int n,int m,vector<int> X,vector<int> Y)
{
	if((int)X.size()==n) return -1;
	set<int> s;
	int sx=(int)X.size(),sy=(int)Y.size();
	for(int i=0; i<sx; ++i) s.insert(X[i]);
	for(int i=0; i<sy; ++i) 
	{
		s.insert(Y[i]%n);
		if((int)s.size()==n) return i;
	}
	vector<int> C;
	int x,y,a=m,b=n;
	exgcd(x,y,a,b);
	while(x<0) x+=n,y-=m;
	while(x>=n) x-=n,y+=m;
	// printf("%lld %lld %lld %lld\n",x,y,a,b);
	for(int i:s) C.push_back(x*i%n),assert((x*i%n)*m%n==i);
	sort(C.begin(),C.end()),C.push_back(C[0]+n);
	int sz=(int)C.size(),ans=-1;
	for(int i=1; i<sz; ++i)
		ans=max(ans,(C[i]-1-C[i-1])*m+C[i-1]*m%n);
	return ans;
}
int a[1000003],b[1000003];
signed main()
{
	if(D>200000) puts("-1"),exit(0);
	for(int T=read(),x; T--;)
		x=read(),A[x%D].push_back(x/D);
	for(int T=read(),x; T--;)
		x=read(),B[x%D].push_back(x/D);
	for(int i=0; i<D; ++i) 
		if(A[i].empty()&&B[i].empty()) 
			puts("-1"),exit(0);
		else if((int)A[i].size()!=N||(int)B[i].size()!=M)
			ans=max(ans,solve(N/D,M/D,A[i],B[i])*D+i),
			ans=max(ans,solve(M/D,N/D,B[i],A[i])*D+i);
	printf("%lld\n",ans);
	return 0;
}