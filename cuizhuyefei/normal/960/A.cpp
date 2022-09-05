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
const int N = 66666;
char s[N];
char t[]={'0','a','b','c'};
int n,a[N],len;
bool ok() {
	rep(i,1,n) {
		int j; for (j=i+1; j<=n; j++) if (s[j]!=s[i]) break;
		//[i,j-1]
		a[++len]=j-i; if (len>3||s[i]!=t[len]) return 0;
		i=j-1;
	}
	if (len!=3) return 0;
	return a[1]==a[3]||a[2]==a[3];
}
int main() {
	scanf("%s",s+1); n=strlen(s+1);
	if (ok())puts("YES"); else puts("NO");
	return 0;
}