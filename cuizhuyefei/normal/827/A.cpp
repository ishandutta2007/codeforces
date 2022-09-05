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
const int N = 2333333;
int n,m;char s[N],t[N];
string a[N];int len[N],pos[N],f[N];
void upd(int p, int i, int l){
	if(l>f[p]){f[p]=l;pos[p]=i;}
}
int main() {
	read(m);rep(i,1,m){
		scanf("%s",t);len[i]=strlen(t);a[i]=t;
		int x,y;read(y);while(y--){read(x);upd(x,i,len[i]);n=max(n,x+len[i]-1);}
	}
	rep(i,1,n)if(!f[i])printf("a");
	else printf("%c",a[pos[i]][len[pos[i]]-f[i]]),upd(i+1,pos[i],f[i]-1);
	return 0;
}