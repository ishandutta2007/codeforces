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
const int N = 666666,inf=0x3f3f3f3f;
int n,q,a[N],l[N],r[N],s[N];set<int>Set;
Vi mrk[N];
void GG(){puts("NO");exit(0);}
int main() {
	read(n);read(q);rep(i,1,n)read(a[i]);
	rep(i,1,n)r[a[i]]=max(r[a[i]],i);
	memset(l,inf,sizeof(l));per(i,n,1)l[a[i]]=min(l[a[i]],i);
	l[1]=min(l[1],l[0]);r[1]=max(r[1],r[0]);
	if(l[q]>r[q]){l[q]=l[0],r[q]=l[0];}if(l[q]>r[q]||l[q]>n+1||r[q]>n+1)GG();
	rep(i,1,q){
		if(l[i]>r[i])l[i]=l[q],r[i]=r[q];
		if(l[i]>r[i])GG();
	}
	rep(i,1,q)mrk[l[i]].pb(i),mrk[r[i]+1].pb(-i);
	rep(i,1,n){
		per(j,SZ(mrk[i])-1,0)
			if(mrk[i][j]>0)Set.insert(mrk[i][j]);
			else Set.erase(-mrk[i][j]);
		if(Set.empty())GG();s[i]=*Set.rbegin();
	}
	rep(i,1,n)if(a[i]&&a[i]!=s[i])GG();
	puts("YES");rep(i,1,n)printf("%d ",s[i]);
	return 0;
}