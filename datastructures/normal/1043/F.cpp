#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 4000000
using namespace std;
inline char gc() {
	static char buf[1048576], *p1, *p2;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1048576, stdin),p1 == p2) ? EOF : *p1++;
}
inline int read() {
	char ch = gc(); int r = 0, w = 1;
	for (; ch < '0' || ch > '9'; ch = gc()) if (ch == '-') w = -1;
	for (; '0' <= ch && ch <= '9'; ch = gc()) r = r * 10 + (ch - '0');
	return r * w;
}
int n,a[4000005],g;
int isp[4000005],tot,p[1000005],mu[4000005];
int cnt[4000005],f[4000005],dp[4000005];
int ans;
int gcd(int a,int b){
	if (b==0)return a;
	return gcd(b,a%b);
}
void prework(){
	isp[0]=isp[1]=1;
	mu[1]=1;
	for (int i=2;i<=maxn;i++){
		if (isp[i]==0){
			p[++tot]=i;
			mu[i]=-1;
		}
		for (int j=1;j<=tot&&i*p[j]<=maxn;j++){
			isp[i*p[j]]=1;
			if (i%p[j]==0){
				mu[i*p[j]]=0;
				break;
			}
			mu[i*p[j]]=-mu[i];
		}
	}
	return;
}
int main(){
	prework();
	cin>>n;
	for (int i=1;i<=n;i++)a[i]=read(),g=gcd(g,a[i]);
    if (g>1){
        cout<<-1<<endl;
        return 0;
    }
	int num_1=0;
	for (int i=1;i<=n;i++){
		a[i]/=g;
		cnt[a[i]]++;
		if (a[i]==1)num_1++;
	}
	if (num_1>0){
		cout<<1<<endl;
		return 0;
	}
	for (int i=1;i<=tot;i++)
		for (int j=maxn/p[i];j>=1;j--)cnt[j]+=cnt[j*p[i]];
	for (int i=1;i<=maxn;i++)f[i]=mu[i]*cnt[i];
	for (int i=1;i<=tot;i++)
		for (int j=p[i];j<=maxn;j+=p[i])f[j]+=f[j/p[i]];
	memset(dp,0x3f,sizeof(dp));
	for (int i=1;i<=maxn;i++)
		if (f[i]>0)dp[i]=1;
	for (int i=1;i<=maxn;i++){
		if (f[i]==0)continue;
		for (int j=i;j<=maxn;j+=i)
			if (dp[j/i]+1<dp[j])dp[j]=dp[j/i]+1;
	}
	ans=1000000000;
	for (int i=1;i<=n;i++)ans=min(ans,dp[a[i]]);
	cout<<ans+1<<endl;
	return 0;
}