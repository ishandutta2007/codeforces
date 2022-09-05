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
const int N = 17000000;
int n,a[1000000],prime[N>>2],len,mrk[N],cnt[N];
int gcd(int a, int b){return !b?a:gcd(b,a%b);}
void getp(int n){
	rep(i,2,n){
		if(!mrk[i])prime[++len]=i;
		rep(j,1,len){
			if(i*prime[j]>n)break;
			mrk[i*prime[j]]=prime[j];
			if(i%prime[j]==0)break;
		}
	}
}
int main() {
	read(n);rep(i,1,n)read(a[i]);int g=0;rep(i,1,n)g=gcd(g,a[i]);
	rep(i,1,n)a[i]/=g;getp(15000000);
	int mx=1;rep(i,1,n)mx=max(mx,a[i]);if(mx==1){puts("-1");return 0;}
	rep(i,1,n){
		int v=a[i];while(mrk[v]){
			int x=mrk[v];while(v%x==0)v/=x;cnt[x]++;
		}
		if(v>1)cnt[v]++;
	}
	int res=n;rep(i,1,15000000)res=min(res,n-cnt[i]);printf("%d",res);
	return 0;
}