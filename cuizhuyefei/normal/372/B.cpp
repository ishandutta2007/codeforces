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
const int N = 45;
int n,m,q,s[N][N],v[N],cnt[N][N];
char S[N][N];
struct que {int x1,y1,x2,y2;} Q[555555];
ll ans[555555];
int main() {
	read(n); read(m); read(q);
	rep(i,1,n) scanf("%s",S[i]+1);
	rep(i,1,n) rep(j,1,m) s[i][j]=(S[i][j]=='1')+s[i][j-1];
	rep(i,1,q) {read(Q[i].x1);read(Q[i].y1);read(Q[i].x2);read(Q[i].y2);}
	rep(l,1,m) rep(r,l,m) {
		rep(i,1,n) v[i]=(s[i][r]-s[i][l-1])>0;
		rep(i,1,n) {
			cnt[i][i-1]=0;
			for (int j=i,now=0; j<=n; j++) {
				if (v[j]) now=0; else now++;
				cnt[i][j]=cnt[i][j-1]+now;
			}
		}
		rep(i,1,q) ans[i]+=cnt[Q[i].x1][Q[i].x2]*(Q[i].y1<=l&&Q[i].y2>=r);
	}
	rep(i,1,q) cout<<ans[i]<<endl;
	return 0;
}