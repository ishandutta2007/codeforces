#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 8008;
char s[N],t[N];
int n,nxt[N],dp[N];
inline void kmp(int p) { //[p,n]
	int len=0; rep(i,1,n-p+1) t[++len]=s[p+i-1];
	nxt[1]=0;
	for (int i=2,j=0; i<=len; i++) {
		while (j&&t[i]!=t[j+1]) j=nxt[j];
		if (t[i]==t[j+1]) j++;
		nxt[i]=j;
	}
}
inline int getval(int x) {
	return (x<=9)?1:((x<=99)?2:((x<=999)?3:4));
}
int main() {
	scanf("%s",s+1); n=strlen(s+1);
	memset(dp,0x3f3f3f3f,sizeof(dp)); dp[0]=0;
	rep(i,0,n-1) {
		kmp(i+1); //printf("%d\n",i);
	//	rep(j,i+1,n) printf("%d : %d\n",j-i,nxt[j-i]);
		rep(j,i+1,n) {
			int len=j-i,p=len-nxt[len],val=(len%p!=0)?1+len:getval(len/p)+p;
			dp[j]=min(dp[j],dp[i]+val);
		}
	}
	cout<<dp[n];
	return 0;
}