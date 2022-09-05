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
const int N = 30300,mo=1e9+7;
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline void sub(int &x, int y){x=x-y>=0?x-y:x-y+mo;}
char s[N];int n,d,a[N],ch[N][10],fail[N],tot,dp[52][2][N];bool mrk[N],safe[N][10];
inline void getfail(){
	static int q[N];int f=0,r=0;
	rep(i,0,9)if(ch[0][i])q[r++]=ch[0][i];
	while(f!=r){
		int u=q[f++];
		rep(i,0,9)if(ch[u][i]){
			int v=ch[u][i];q[r++]=v;
			int x=fail[u];while(x&&!ch[x][i])x=fail[x];
			fail[v]=ch[x][i];
		}else ch[u][i]=ch[fail[u]][i];
	}
}
inline int getans(){
	int res=0;rep(i,1,d)res=(10LL*res+a[i])%mo;res++;
	rep(i,0,tot)mrk[i]=0,memset(ch[i],0,10<<2),fail[i]=0;tot=0;
	rep(i,1,n-d/2+1){
		int u=0;rep(j,i,i+d/2-1){
			if(!ch[u][s[j]-'0'])ch[u][s[j]-'0']=++tot;
			u=ch[u][s[j]-'0'];
		}
		mrk[u]=1;
	}
	getfail();
	memset(dp,0,sizeof(dp));memset(safe,0,sizeof(safe));
	rep(i,0,tot)rep(j,0,9)safe[i][j]=(!mrk[i]&&!mrk[ch[i][j]]);
//	cerr<<safe[0][1]<<' '<<ch[0][1]<<endl;
	dp[0][1][0]=1;
	rep(i,0,d-1)rep(j,0,1)rep(k,0,tot)if(dp[i][j][k]){
		per(c,!j?9:a[i+1],0)if(safe[k][c])add(dp[i+1][j&(c==a[i+1])][ch[k][c]],dp[i][j][k]);
	}
	rep(j,0,1)rep(k,0,tot)sub(res,dp[d][j][k]);
//	printf("%d\n",res);
	return res;
}
int main() {
	scanf("%s",s+1);n=strlen(s+1);
	char S[100];scanf("%s",S+1);d=strlen(S+1);
	rep(i,1,d)a[i]=S[i]-'0';a[d]--;
	for(int i=d;a[i]<0;i--)a[i]+=10,a[i-1]--;
	int res=-getans();
	scanf("%s",S+1);d=strlen(S+1);rep(i,1,d)a[i]=S[i]-'0';
	res=((res+getans())%mo+mo)%mo;
	printf("%d\n",res);
	return 0;
}