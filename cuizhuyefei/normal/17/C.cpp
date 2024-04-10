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
const int N = 153, mo = 51123987;
int f[152][56][56][56],n,len,nxt[N][3];
char s[N];
int M(int x) {return x<mo?x:x-mo;}
int main() {
	read(n); scanf("%s",s+1);
	rep(i,1,n) {
		int j; for (j=i+1; j<=n; j++) if (s[i]!=s[j]) break;
		s[++len]=s[i]; i=j-1;
	}
	rep(j,0,2) {int lst=len+1; per(i,len,0) {nxt[i][j]=lst; if (s[i]=='a'+j) lst=i;}}
	f[0][0][0][0]=1; int mx=(n+2)/3;
	rep(i,0,len-1) rep(j,0,2) if (s[i]!='a'+j&&nxt[i][j]<=len) {
		/*rep(a,0,mx) rep(b,0,mx) rep(c,0,mx) {
			int x=(j==0)?(a-1>=0?f[nxt[i][j]][a-1][b][c]+f[i][a-1][b][c]:0)
			:(j==1?(b-1>=0?f[nxt[i][j]][a][b-1][c]+f[i][a][b-1][c]:0)
			:(c-1>=0?f[nxt[i][j]][a][b][c-1]+f[i][a][b][c-1]:0));
			int &t=f[nxt[i][j]][a][b][c]; t=M(t+x);
		}*/
		if (j==0) {
			rep(b,0,mx) rep(c,0,mx) {
				int v=0;
				rep(a,1,mx) {
					int &t=f[nxt[i][j]][a][b][c]; v=M(v+f[i][a-1][b][c]); t=M(t+v);
				}
			}
		} else if (j==1) {
			rep(a,0,mx) rep(c,0,mx) {
				int v=0;
				rep(b,1,mx) {
					int &t=f[nxt[i][j]][a][b][c]; v=M(v+f[i][a][b-1][c]); t=M(t+v);
				}
			}
		} else {
			rep(a,0,mx) rep(b,0,mx) {
				int v=0;
				rep(c,1,mx) {
					int &t=f[nxt[i][j]][a][b][c]; v=M(v+f[i][a][b][c-1]); t=M(t+v);
				}
			}
		}
	}
	/*rep(i,1,len) rep(a,0,mx) rep(b,0,mx) rep(c,0,mx) if (f[i][a][b][c])
		printf("%d %d %d %d : %d\n",i,a,b,c,f[i][a][b][c]);*/
	int ans=0;
	rep(i,1,len) rep(a,mx-1,mx) rep(b,mx-1,mx) rep(c,mx-1,mx) if (a+b+c==n) ans=M(ans+f[i][a][b][c]);
	cout<<ans;
	return 0;
}