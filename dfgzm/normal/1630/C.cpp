#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=200010;
int i,j,k,n,m,T;
int R[maxn],a[maxn],dp[maxn];
int main(){
	cin>>n;
	for(i=1;i<=n;i++)R[i]=0;
	for(i=1;i<=n;i++)a[i]=read(),R[a[i]]=i;
	int now=1,to=R[a[1]],ans=1;
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(i=1;i<=n;i++){
		dp[i]=min(dp[i],dp[i-1]+1);
		to=max(to,R[a[i]]);
		dp[to]=min(dp[to],dp[i]+1);
	}
	printf("%d\n",n-dp[n]);
	return 0;
}