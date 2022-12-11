#include<cstdio>
#include<algorithm>
#include<cstring>
#include<assert.h>
using namespace std;
typedef long long ll;
const int Mod=1e9+7; int maxw;
inline int upd(int x){return x+(x>>31&Mod);}
inline void add(int &x,int y){x=upd(x+y-Mod);}
inline void iadd(int &x,int y){x=upd(x-y);}

char s[510]; int len;
int n,m;  //itv tot; given tot
int a[20],b[20],c[20],d[20],e[20];
int L[510],M[510],R[510],Ls[510],Rs[510];
int build(int l,int r){
	int x=++n; L[x]=l,R[x]=r;
	if (l==r) return x;
	assert(s[l]=='('&&s[r]==')');
	int p=l,t=1;
	while (t){
		p++; assert(p<=r);
		if (s[p]=='(') t++;
		else if (s[p]==')') t--;
	}
	M[x]=p+1; Ls[x]=build(l+1,p-1); Rs[x]=build(p+3,r-1);
	return x;
}
int dp[512][65536];  //128MB
int work(int *x,int y){
	int S=0;
	for (int i=1;i<=m;i++)
		S|=(x[i]^y)<<i-1;
	return S;
}
int work(char x){
	if (x=='A') return work(a,0);
	if (x=='a') return work(a,1);
	if (x=='B') return work(b,0);
	if (x=='b') return work(b,1);
	if (x=='C') return work(c,0);
	if (x=='c') return work(c,1);
	if (x=='D') return work(d,0);
	if (x=='d') return work(d,1);
	assert(0);
}
void fwt_or(int *f){
	for (int i=0;i<m;i++)
		for (int j=0,t=1<<m;j<t;j++)
			if (!(j>>i&1))
				add(f[j|1<<i],f[j]);
}
void ifwt_or(int *f){
	for (int i=0;i<m;i++)
		for (int j=0,t=1<<m;j<t;j++)
			if (!(j>>i&1))
				iadd(f[j|1<<i],f[j]);
}
void fwt_and(int *f){
	for (int i=0;i<m;i++)
		for (int j=0,t=1<<m;j<t;j++)
			if (!(j>>i&1))
				add(f[j],f[j|1<<i]);
}
void ifwt_and(int *f){
	for (int i=0;i<m;i++)
		for (int j=0,t=1<<m;j<t;j++)
			if (!(j>>i&1))
				iadd(f[j],f[j|1<<i]);
}
void solve(int x){
	int l=L[x],r=R[x],mid=M[x],ls=Ls[x],rs=Rs[x];
	if (l==r){
		if (s[l]=='?'){
			dp[x][work(a,0)]++;
			dp[x][work(a,1)]++;
			dp[x][work(b,0)]++;
			dp[x][work(b,1)]++;
			dp[x][work(c,0)]++;
			dp[x][work(c,1)]++;
			dp[x][work(d,0)]++;
			dp[x][work(d,1)]++;
		}
		else dp[x][work(s[l])]++;
		return;
	}
	static int A[65536],B[65536];
	int *P=dp[ls],*Q=dp[rs],*T=dp[x];
	if (s[mid]=='?'||s[mid]=='|'){
		for (int i=0;i<maxw;i++) A[i]=P[i],B[i]=Q[i];
		fwt_or(A),fwt_or(B);
		for (int i=0;i<maxw;i++) T[i]=1LL*A[i]*B[i]%Mod;
		ifwt_or(T);
	}
	if (s[mid]=='?'||s[mid]=='&'){
		for (int i=0;i<maxw;i++) A[i]=P[i],B[i]=Q[i];
		fwt_and(A),fwt_and(B);
		for (int i=0;i<maxw;i++) A[i]=1LL*A[i]*B[i]%Mod;
		ifwt_and(A);
		for (int i=0;i<maxw;i++) add(T[i],A[i]);
	}
}
int main()
{
	scanf("%s",s+1); len=strlen(s+1);
	scanf("%d",&m); maxw=1<<m;
	for (int i=1;i<=m;i++)
		scanf("%d%d%d%d%d",a+i,b+i,c+i,d+i,e+i);
	build(1,len);
	for (int i=n;i;i--) solve(i);
	int S=0;
	for (int i=1;i<=m;i++) S|=e[i]<<i-1;
	printf("%d\n",dp[1][S]);
	return 0;
}