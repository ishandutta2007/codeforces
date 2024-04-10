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
const int N = 166666,mo=1e9+7;
int n,m,tar,dfn[N],num,ans[2],s[N],len,cost[N][2];Vi dot[N];
struct edge{int to,a,b;};
vector<edge>e[N];
int Abs(int x){return x>0?x:-x;}
int sgn(int x){return x>0?0:1;}
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
void dfs(int u){
	dfn[u]=num;s[++len]=u;
	rep(i,0,SZ(e[u])-1)if(dfn[e[u][i].to]!=num)dfs(e[u][i].to);
}
bool cmp(int x, int y){return SZ(e[x])<SZ(e[y]);}
int main() {
	read(m);read(n);tar=1;
	ans[0]=1;
	rep(i,1,m){
		int k,x,y;read(k);
		if(k==1){read(x);dot[Abs(x)].pb(sgn(x));}
		else{
			read(x);read(y);
			if(Abs(x)!=Abs(y)){
				e[Abs(x)].pb((edge){Abs(y),sgn(x),sgn(y)});
				e[Abs(y)].pb((edge){Abs(x),sgn(y),sgn(x)});
			}
			else if(x==y){printf("%d\n",power(2,n-1));return 0;}
			else tar^=1;//*=2??
		}
	}
	rep(u,1,n)rep(i,0,1)rep(j,0,SZ(dot[u])-1)cost[u][i]^=i^dot[u][j];
	rep(u,1,n)if(!dfn[u]){
		num++;len=0;dfs(u);
		if(len==1){
			int dp[2]={0};
			rep(i,0,1){
				int x=0;rep(j,0,SZ(dot[u])-1)x^=i^dot[u][j];
				rep(j,0,1)add(dp[j^x],ans[j]);
			}
			ans[0]=dp[0];ans[1]=dp[1];
		}
		else{
			sort(s+1,s+len+1,cmp);int rec=len,head=s[1];
			num++;len=0;dfs(head);
		//	rep(j,1,len)cerr<<s[j]<<' ';cerr<<endl;
			assert(len==rec);
			int dp[2]={0};
			rep(i,0,1){
				static int f[N][2][2];rep(j,0,len)f[j][0][0]=f[j][0][1]=f[j][1][0]=f[j][1][1]=0;
				f[1][cost[s[1]][i]][i]=1;
				rep(j,1,len-1)rep(k,0,1)rep(sum,0,1)rep(lst,0,1){
					int x=sum^cost[s[j+1]][k];
					rep(t,0,SZ(e[s[j]])-1)if(e[s[j]][t].to==s[j+1])x^=(lst^e[s[j]][t].a)|(k^e[s[j]][t].b);
					if(j+1==len&&len>2)rep(t,0,SZ(e[s[len]])-1)if(e[s[len]][t].to==s[1])x^=(k^e[s[len]][t].a)|(i^e[s[len]][t].b);
					add(f[j+1][x][k],f[j][sum][lst]);
				}
			//	cerr<<i<<':'<<f[len][0]<<' '<<f[len][1]<<endl;
				rep(j,0,1)rep(des,0,1)rep(i,0,1){
					int x=j^des;
					add(dp[x],1LL*ans[j]*f[len][des][i]%mo);
				}
			}
			ans[0]=dp[0];ans[1]=dp[1];
		}
	}
	cout<<ans[tar]<<endl;
	return 0;
}