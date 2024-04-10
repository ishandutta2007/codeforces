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
const int N = 303;
int n,m,v[N][N],l[N][N],cnt[N][N];
vector<char> a[N][N],b[N][N];char S[300000];
Vi s[666666];int len;
void move(int x1,int y1, int x2, int y2){
	if(x1==x2&&y1==y2)return;//WA
	Vi S;S.pb(x1);S.pb(y1);S.pb(x2);S.pb(y2);s[++len]=S;
	v[x1][y1]--;v[x2][y2]++;
}
void getl(vector<char> a[N][N]){
	rep(i,1,n)rep(j,1,m)l[i][j]=SZ(a[i][j]);
}
void solve(vector<char> a[N][N]){
	getl(a);rep(i,1,n)rep(j,1,m)v[i][j]=SZ(a[i][j]);
	rep(i,1,n)rep(j,1,m)per(k,l[i][j]-1,0)
		if(i==1&&j==1){if(a[i][j][k]=='0')move(i,j,n,j);else move(i,j,i,m);}
		else if(i==1&&j==m){if(a[i][j][k]=='0')move(i,j,i,1);else move(i,j,n,j);}
		else if(a[i][j][k]=='0'){if(j!=1)move(i,j,i,1);else move(i,j,1,j);}
		else {if(j!=m)move(i,j,i,m);else move(i,j,1,j);}//WA
	rep(i,1,n)rep(j,1,m)if(i!=1)per(k,v[i][j]-1,0)move(i,j,1,j);
}
int main() {//freopen("1.in","r",stdin);
	read(n);read(m);rep(i,1,n)rep(j,1,m){
		scanf("%s",S+1);int l=strlen(S+1);rep(p,1,l)a[i][j].pb(S[p]);
	}rep(i,1,n)rep(j,1,m){
		scanf("%s",S+1);int l=strlen(S+1);per(p,l,1)b[i][j].pb(S[p]);
	}
//	printf("%lf\n",1.0*clock()/CLOCKS_PER_SEC);
	solve(a);
	int rec=len;
	solve(b);
	rep(i,rec+1,len)swap(s[i][0],s[i][2]),swap(s[i][1],s[i][3]);
	reverse(s+rec+1,s+len+1);
	
//	printf("%lf\n",1.0*clock()/CLOCKS_PER_SEC);
//	return 0;
	
	printf("%d\n",len);
	rep(i,1,len)printf("%d %d %d %d\n",s[i][0],s[i][1],s[i][2],s[i][3]);
	return 0;
}
//1.n & m