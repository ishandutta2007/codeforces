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
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 150;
int n,m,k;char a[N][N],s[N][N];
Pii f[N*N];

char Get(int x){
	x--;
	if(x<26)return 'a'+x;
	x-=26;
	if(x<26)return 'A'+x;
	x-=26;
	return '0'+x;
}
int main() {
	int T;read(T);while(T--){
		read(n);read(m);read(k);
		rep(i,1,n)scanf("%s",a[i]+1);
		int sz=0;
		rep(i,1,n)
			if(i&1){rep(j,1,m)f[++sz]=Pii(i,j);}
			else{per(j,m,1)f[++sz]=Pii(i,j);}
		int tot=0;
		rep(i,1,n)rep(j,1,m)tot+=a[i][j]=='R';
		int p=1;
		rep(t,1,k){
			int c=tot/(k-t+1);tot-=c;assert(c);
			while(p<=sz&&(c||t==k)){
				c-=a[f[p].fi][f[p].se]=='R';
				s[f[p].fi][f[p].se]=Get(t);
				p++;
			}
		}
		rep(i,1,n){rep(j,1,m)printf("%c",s[i][j]);puts("");}
	}
	return 0;
}