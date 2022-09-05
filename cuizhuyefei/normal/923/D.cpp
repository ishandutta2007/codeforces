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
const int N = 500000;
int n,m,qz1[N],qz2[N],lst1[N],lst2[N];
char s[N],t[N];
int main() { //freopen("1.in","r",stdin);
	scanf("%s%s",s+1,t+1); n=strlen(s+1); m=strlen(t+1);
	rep(i,1,n) qz1[i]=qz1[i-1]+(s[i]!='A');
	rep(i,1,m) qz2[i]=qz2[i-1]+(t[i]!='A');
	rep(i,1,n) lst1[i]=(s[i]!='A')?i:lst1[i-1];
	rep(i,1,m) lst2[i]=(t[i]!='A')?i:lst2[i-1];
	int q; read(q);
	while (q--) {
		int a,b,c,d; read(a);read(b);read(c);read(d);
		int b1=qz1[b]-qz1[a-1],b2=qz2[d]-qz2[c-1],a1=b-max(lst1[b],a-1),a2=d-max(lst2[d],c-1);
		printf("%c",'0'+(b1<=b2&&(b2-b1)%2==0&&a1>=a2&&(b1<b2&&(a1-1>=a2||a1==a2&&b1>0)||b1==b2&&(a1-a2)%3==0)));
	}
	return 0;
}