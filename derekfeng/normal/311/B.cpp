#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	register char ch=getchar();x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,m,p,d[100004],a[100004],tms,lst,dq[103][100004];
ll dp[103][100004],s[103],t[103];
ll f(int id,int lst,int x){
	ll k=-lst,b=dp[id][lst]-dp[1][lst]+1ll*lst*a[lst];
	return k*x+b;
}
bool check(int id,int f1,int f2,int f3){
	ll k1=-f1,b1=dp[id][f1]-dp[1][f1]+1ll*f1*a[f1];
	ll k2=-f2,b2=dp[id][f2]-dp[1][f2]+1ll*f2*a[f2];
	ll k3=-f3,b3=dp[id][f3]-dp[1][f3]+1ll*f3*a[f3];
	return (b3-b2)*(k2-k1)>=(b2-b1)*(k3-k2);
}
void push_(int id,int x){
	while(s[id]+1<t[id]&&check(id,dq[id][t[id]-2],dq[id][t[id]-1],x))t[id]--;
	dq[id][t[id]++]=x;
}
void pop_(int id,int x){
	while(s[id]+1<t[id]&&f(id,dq[id][s[id]],x)>=f(id,dq[id][s[id]+1],x))s[id]++;
}
ll top_(int id,int x){
	return f(id,dq[id][s[id]],a[x]);
}
int main(){
	read(n),read(m),read(p);
	p=min(p,m);
	for(int i=2;i<=n;i++)read(d[i]),d[i]+=d[i-1];
	for(int i=1;i<=m;i++)read(a[i]),read(tms),a[i]=tms-d[a[i]];
	sort(a+1,a+1+m);
	for(int i=1;i<=m;i++){
		dp[1][i]=dp[1][i-1]+1ll*(i-1)*(a[i]-a[i-1]);
		push_(1,i);
		for(int j=2;j<=min(p,i);j++){
			pop_(j-1,a[i]);
			dp[j][i]=dp[1][i]+top_(j-1,i);
			push_(j,i);
		}
	}
	write(dp[p][m]);
}