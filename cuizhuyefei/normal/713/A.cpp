#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 5000000;
int ch[2][N],val[N],cnt;
char t[20]; int len,qz[20];
void add(int now, int tp) { //t[1..len]-'0'
	per(i,len,len-18) {
		int c=i<=0?0:((t[i]-'0')&1);
		if (!ch[c][now]) ch[c][now]=++cnt;
		now=ch[c][now]; if ((i>=1&&!qz[i-1])||i<=0) val[now]+=tp;
	}
}
int query(int now) {
	per(i,len,1) {
		int c=(t[i]-'0')&1;
		if (!ch[c][now]) return 0;
		now=ch[c][now];
	}
	return val[now];
}
int main() {
	int q;read(q);
	while (q--) {
		char s[3];scanf("%s",s); scanf("%s",t+1); len=strlen(t+1);
		rep(i,1,len) qz[i]=qz[i-1]+((t[i]-'0')&1);
		if (s[0]=='+') add(0,1);
		else if (s[0]=='-') add(0,-1);
		else printf("%d\n",query(0));
	}
	return 0;
}