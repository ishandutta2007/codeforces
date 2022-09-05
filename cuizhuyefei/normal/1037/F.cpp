#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1000200,mo=1e9+7;
int n,k,a[N],b[N][21],Log[N];ll res;
int query(int l, int r){
	int k=Log[r-l+1];return max(b[l][k],b[r-(1<<k)+1][k]);
}
void solve(int t){
	static int val[N],cnt[N];int top=0;ll sum=0;
	for(int i=t;i>=1;i-=k-1){
		int x=query(i,i+2*k-2),y=1;sum+=x;
		while(top&&val[top]<=x)sum+=1LL*(x-val[top])*cnt[top]%mo,y+=cnt[top],top--;
		top++;val[top]=x;cnt[top]=y;res+=sum;res%=mo;
	}
}
int main() {
	read(n);read(k);rep(i,1,n)read(a[i]);
	rep(i,1,n)b[i][0]=a[i];
	rep(j,1,20)rep(i,1,n-(1<<j)+1)
		b[i][j]=max(b[i][j-1],b[i+(1<<(j-1))][j-1]);
	rep(i,1,n){Log[i]=Log[i-1];if(i==(1<<(Log[i]+1)))Log[i]++;}
	rep(i,1,n-k+1)res+=query(i,i+k-1);
	
	rep(i,n-2*k+2-k+2,n-2*k+2)if(i>=1)solve(i);
	
	cout<<res%mo;
	return 0;
}