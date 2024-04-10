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
const int N = 555555;
int n,k,a[N];char s[N];int sta[N],top;
char ans[N];int len;
void solve(int l, int r, int k){
	if(l>r||k==0)return;
	if(a[l]-l+1<=k){rep(i,l,a[l])ans[++len]=s[i];solve(a[l]+1,r,k-(a[l]-l+1));}
	else solve(l+1,a[l]-1,k);
}
int main() {
	read(n);read(k);scanf("%s",s+1);
	rep(i,1,n)if(s[i]=='(')sta[++top]=i;
	else a[i]=sta[top],a[sta[top]]=i,top--;
	solve(1,n,k);rep(i,1,len)printf("%c",ans[i]);
	return 0;
}