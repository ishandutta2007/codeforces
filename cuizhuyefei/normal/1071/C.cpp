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
const int N = 233333, M = 1<<14;
int n,a[N],dp[M],q[M|3];
Vi a1,a2,a3;
void move(int x, int y, int z){
	a1.pb(x);a2.pb(y);a3.pb(z);a[x]^=1;a[y]^=1;a[z]^=1;
}
int main() {
	read(n);rep(i,1,n)read(a[i]);
	while(n>12){
		if(a[n]==0){n--;continue;}
		if(a[n-1]==0){
			bool ok=0;
			per(i,n-2,n-10)if(a[i]==1&&2*i-n>=1){
				ok=1;move(2*i-n,i,n);
				break;
			}
			if(!ok)move(n-6,n-3,n);
		}
		else if(a[n-2]==1){
			move(n-2,n-1,n);
		}
		else{
			if(a[n-3]==1&&a[n-4]==1&&a[n-5]==1)move(n-5,n-3,n-1),move(n-8,n-4,n);
			else if(a[n-3]==1)move(n-6,n-3,n);
			else{
				bool ok=0;per(i,n-2,n-10)if(a[i]&&2*i-n>=1){
					ok=1;move(2*i-n,i,n);break;
				}
				if(!ok)move(n-12,n-6,n);
			}
		}
	}
	memset(dp,-1,sizeof(dp));
	int S=0;rep(i,1,n)if(a[i])S|=1<<i;dp[S]=0;
	int f=0,r=1;q[f]=S;
	while(f!=r){
		int u=q[f++];
		rep(i,1,n)rep(j,i+1,n)rep(k,j+1,n)
			if(j-i==k-j&&dp[u^(1<<i)^(1<<j)^(1<<k)]==-1){
				int x=u^(1<<i)^(1<<j)^(1<<k);dp[x]=u;q[r++]=x;
			}
	}
	if(dp[0]==-1)puts("NO");
	else{
		for(int s=0;s!=S;s=dp[s]){
			int b[4],len=0,v=s^dp[s];rep(i,1,n)if((v>>i)&1)b[++len]=i;
			a1.pb(b[1]);a2.pb(b[2]);a3.pb(b[3]);
		}
		puts("YES");printf("%d\n",SZ(a1));
		rep(i,0,SZ(a1)-1)printf("%d %d %d\n",a1[i],a2[i],a3[i]);
	}
	return 0;
}