#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
typedef long long LL;
inline int read()
{
	int x=0;bool f=0;char c=getchar();
	for (;c<'0'||c>'9';c=getchar()) f=c=='-'?1:0;
	for (;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return f?-x:x;
}
const int N=100005;
int n;LL A[N],S[N],mx[N],mn[N],ans=0;

int main()
{
	n=read()-1;
	for (int i=1;i<=n+1;i++) A[i]=read();
	for (int i=1;i<=n;i++) A[i]=abs(A[i]-A[i+1]);
	for (int i=1,k=1;i<=n;i++,k=-k) S[i]=S[i-1]+A[i]*k;
	mx[n+1]=-1e18;mn[n+1]=1e18;
	for (int i=n;i;i--) mx[i]=max(S[i],mx[i+1]);
	for (int i=n;i;i--) mn[i]=min(S[i],mn[i+1]);
	for (int i=1;i<=n;i+=2) ans=max(ans,mx[i]-S[i-1]);
	for (int i=2;i<=n;i+=2) ans=max(ans,-mn[i]+S[i-1]);
	cout<<ans<<endl;
	return 0;
}