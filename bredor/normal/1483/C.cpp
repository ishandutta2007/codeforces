// 228
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;i++)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
const int N=300005;
const ll INF=0x7f7f7f7f;
ll n,h[N],b[N],s[N],st,p[N],dp[N],t[N]; 
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
int main(){
	n=read();
	rep(i,1,n) h[i]=read();
	rep(i,1,n) b[i]=read();
	mem(p,-INF);
	rep(i,1,n){
		ll tmp=dp[i-1];
		while(st&&s[st]>=h[i]) tmp=max(tmp,t[st]),st--;
		s[++st]=h[i],t[st]=tmp,p[st]=max(p[st-1],tmp+b[i]);
		dp[i]=p[st];
	}
	printf("%lld",dp[n]);
	return 0;
}