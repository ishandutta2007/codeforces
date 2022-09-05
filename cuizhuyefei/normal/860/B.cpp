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
const int N = 3220000;
int n;char t[70700][12];
int ch[N][10],val[N],tot;
int main() {
	read(n);rep(i,1,n)scanf("%s",t[i]+1);
	rep(i,1,n){
		int s[12];rep(j,1,9)s[j]=t[i][j]-'0';
		set<int>Set;
		rep(j,1,9){
			int x=0;
			rep(k,j,9){
				if(!ch[x][s[k]])ch[x][s[k]]=++tot;
				x=ch[x][s[k]];
				if(!Set.count(x))Set.insert(x),val[x]++;
			}
		}
	}
	rep(i,1,n){
		int s[12];rep(j,1,9)s[j]=t[i][j]-'0';
		int l=1,r=9;
		rep(j,1,9){
			int x=0;
			rep(k,j,9){
				x=ch[x][s[k]];
				if(val[x]==1&&k-j+1<r-l+1)l=j,r=k;
			}
		}
		rep(j,l,r)putchar(s[j]+'0');puts("");
	}
	return 0;
}