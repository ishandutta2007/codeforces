#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
const int N = 2020;
int n,m,k,ans[N],f[N][N],A[N],B[N];char s[N][N];
int l[N][N],r[N][N];
inline void init(int i){
	for(int j=1,k=0;j<=m;j++){
		k=s[i][j]=='X'?j:k;l[i][j]=k;
	}
	for(int j=m,k=m+1;j>=1;j--){
		k=s[i][j]=='X'?j:k;r[i][j]=k;
	}
}
inline bool ck(int x, int y, int k){
	static int a[N],b[N],mx[N],mn[N];
	rep(i,1,n)a[i]=l[i][y],b[i]=r[i][y];
	rep(i,x+1,n)umin(b[i],b[i-1]),umax(a[i],a[i-1]);
	per(i,x-1,1)umin(b[i],b[i+1]),umax(a[i],a[i+1]);
	rep(i,1,n-k+1)if(x>=i&&x<=i+k-1&&min(b[i],b[i+k-1])-max(a[i],a[i+k-1])>=k+1){
		return 1;
	}
	return 0;
}
int main() {
	read(n);read(m);read(k);
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,k)read(A[i]),read(B[i]),s[A[i]][B[i]]='X';
	per(i,n,1)per(j,m,1)if(s[i][j]=='.'){
		f[i][j]=min(f[i][j+1],f[i+1][j]);
		if(i+f[i][j]<=n&&j+f[i][j]<=m&&s[i+f[i][j]][j+f[i][j]]=='.')f[i][j]++;
		umax(ans[k],f[i][j]);
	}
	rep(i,1,n)init(i);
	per(t,k,1){//recover t-->ans[t-1]
		ans[t-1]=ans[t];s[A[t]][B[t]]='.';init(A[t]);
		while(ck(A[t],B[t],ans[t-1]+1))ans[t-1]++;
	}
	rep(i,1,k)printf("%d\n",ans[i]);
	return 0;
}