#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#include<queue>
#define pb push_back
#include<assert.h>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef long long ll;
const int mod=998244353,INF=1e9;
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
typedef pair<int,int> P;
typedef pair<P,P> PP;
#define fir first
#define sec second

int n,m;
vector<int> p[200010],q[200010];
int A[21][200010];
P que[21*200000+10]; int hd,tl;
P B[2][200010];
int main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++){
		int u=read(),v=read();
		p[u].pb(v); q[v].pb(u);
	}
	for (int i=0;i<=20;i++)
		for (int j=1;j<=n;j++)
			A[i][j]=INF;
	for (int i=0;i<2;i++)
		for (int j=1;j<=n;j++)
			B[i][j]=(P){INF,INF};
	A[0][1]=0; que[++tl]=(P){0,1};
	while (hd<tl){
		P x=que[++hd]; int u=x.first,v=x.second;
		if (u<20){
			if (A[u][v]+(1<<u)<A[u+1][v]){
				A[u+1][v]=A[u][v]+(1<<u);
				que[++tl]=(P){u+1,v};
			}
		}
		else{
			B[1][v]=min(B[1][v],(P){21,A[u][v]});
		}
		if (u&1){
			for (auto y: q[v]){
				if (A[u][v]+1<A[u][y]){
					A[u][y]=A[u][v]+1;
					que[++tl]=(P){u,y};
				}
			}
		}
		else{
			for (auto y: p[v]){
				if (A[u][v]+1<A[u][y]){
					A[u][y]=A[u][v]+1;
					que[++tl]=(P){u,y};
				}
			}
		}
	}
	{
	int ans=INF;
	for (int i=0;i<=20;i++) ans=min(ans,A[i][n]);
	if (ans^INF) return printf("%d\n",ans%mod),0;
	}
	
	priority_queue<PP,vector<PP>,greater<PP> > que;
	for (int i=1;i<=n;i++) if (B[1][i].fir^INF) que.push((PP){B[1][i],(P){1,i}});
	while (!que.empty()){
		PP x=que.top(); que.pop();
		if (B[x.sec.fir][x.sec.sec]!=x.fir) continue;
		int u=x.sec.fir,v=x.sec.sec;
		P foo=(P){B[u][v].fir+1,B[u][v].sec};
		if (foo<B[u^1][v]){
			B[u^1][v]=foo;
			que.push((PP){B[u^1][v],(P){u^1,v}});
		}
		if (u){
			for (auto y: q[v]){
				P foo=(P){B[u][v].fir,B[u][v].sec+1};
				if (foo<B[u][y]){
					B[u][y]=foo;
					que.push((PP){B[u][y],(P){u,y}});
				}
			}
		}
		else{
			for (auto y: p[v]){
				P foo=(P){B[u][v].fir,B[u][v].sec+1};
				if (foo<B[u][y]){
					B[u][y]=foo;
					que.push((PP){B[u][y],(P){u,y}});
				}
			}
		}
	}
	P ans=min(B[0][n],B[1][n]);
	assert(ans.fir^INF);
	int res=ans.sec;
	for (int i=21,V=1<<20;i<=ans.fir;i++,V=V*2%mod){
		res=(res+V)%mod;
	}
	printf("%d\n",res);
	return 0;
}