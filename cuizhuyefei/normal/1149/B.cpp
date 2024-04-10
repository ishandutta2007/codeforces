#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 102000,inf=0x3f3f3f3f;
int n,q;char s[N];int nxt[N][26],f[255][255][255];
int a[N],b[N],c[N];int A,B,C;
inline void trans(int i, int j, int k){
	f[i][j][k]=inf;
	if(i>0)umin(f[i][j][k],nxt[f[i-1][j][k]][a[i]]);
	if(j>0)umin(f[i][j][k],nxt[f[i][j-1][k]][b[j]]);
	if(k>0)umin(f[i][j][k],nxt[f[i][j][k-1]][c[k]]);
}
int main() {
	read(n);read(q);scanf("%s",s+1);
	rep(i,0,25)nxt[n][i]=nxt[n+1][i]=n+1;
	per(i,n,1){
		memcpy(nxt[i-1],nxt[i],104);
		nxt[i-1][s[i]-'a']=i;
	}
	while(q--){
		char t[5];scanf("%s",t);
		if(t[0]=='+'){
			int id;read(id);scanf("%s",t);int ch=t[0]-'a';
			if(id==1){
				a[++A]=ch;
				rep(i,0,B)rep(j,0,C)trans(A,i,j);
			}
			else if(id==2){
				b[++B]=ch;
				rep(i,0,A)rep(k,0,C)trans(i,B,k);
			}
			else{
				c[++C]=ch;
				rep(i,0,A)rep(j,0,B)trans(i,j,C);
			}
		}
		else{
			int id;read(id);
			if(id==1)A--;if(id==2)B--;if(id==3)C--;
		}
		printf("%s\n",f[A][B][C]<=n?"YES":"NO");
	}
	return 0;
}