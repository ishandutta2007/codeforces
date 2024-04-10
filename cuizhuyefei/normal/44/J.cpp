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
const int N = 1020;
int n,m;
char s[N][N],ans[N][N];
bool GG(){puts("NO"); exit(0);}
int main() {
	read(n); read(m);
	rep(i,1,n) scanf("%s",s[i]+1),memcpy(ans[i],s[i],sizeof(s[i]));
	int cnt1=0,cnt2=0;
	rep(i,1,n) rep(j,1,m)
		cnt1+=s[i][j]=='w',cnt2+=s[i][j]=='b';
	if (cnt2*2!=cnt1) GG();
	rep(i,1,n) rep(j,1,m) if (s[i][j]=='b') {
		int col='a'+(i%2 ? 0 : 2)+(((i-1)/2+(j-1)/2)&1);
		if (i>1&&i<n&&ans[i-1][j]=='w'&&ans[i+1][j]=='w') {
			ans[i-1][j]=ans[i][j]=ans[i+1][j]=col;
		}
		else if (j>1&&j<m&&ans[i][j-1]=='w'&&ans[i][j+1]=='w') {
			ans[i][j-1]=ans[i][j]=ans[i][j+1]=col;
		}
		else GG();
	}
	puts("YES");
	rep(i,1,n) {rep(j,1,m) printf("%c",ans[i][j]); puts("");}
	return 0;
}