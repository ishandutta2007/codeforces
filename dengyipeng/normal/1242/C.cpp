#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
#define mem(a) memset(a,0,sizeof(a))
#define maxk 16
#define maxn 5005
#define ll long long 
using namespace std;

int K,n[maxk],i,j,k,S,a[maxk][maxn],vis[maxk];
int f[1<<maxk],g[1<<maxk],g0[1<<maxk];
int p[1<<maxk][maxk],q[1<<maxk][maxk],pp[maxk],qq[maxk];
ll sum0,sum[maxk],need,res;
struct node{
	int x,y;
	node(int _x=0,int _y=0){x=_x,y=_y;}
};
map<int,node> s;

void read(int &x){
	x=0; char ch=getchar(); int tp=1;
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if (ch=='-') tp=-1,ch=getchar();
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	x=x*tp;
}

int dg(int T,int i,int S){
	if (i>K){
		if (f[T]&&g[S^T]) {
			g0[S]=T,g[S]=1;
			return 1;
		}
		return 0;
	}
	if (dg(T,i+1,S)) return 1;
	if ((S&(1<<i-1))&&dg(T|(1<<i-1),i+1,S)) return 1;
	return 0;
}

int main(){
	read(K);
	for(i=1;i<=K;i++){
		read(n[i]);
		for(j=1;j<=n[i];j++) {
			read(a[i][j]);
			sum[i]+=a[i][j],sum0+=a[i][j];
			s[a[i][j]]=node(i,j);
		}
	}
	if (sum0%K) {printf("No");return 0;} 
	need=sum0/K;
	for(int sti=1;sti<=K;sti++) {
		for(int st=1;st<=n[sti];st++) {
			mem(vis),mem(pp),mem(qq);
			res=need-(sum[sti]-a[sti][st]);
			vis[sti]=1,i=sti,pp[sti]=st,S=1<<sti-1;
			node now=s[res];
			while (now.x&&!vis[now.x]){
				vis[now.x]=1,pp[now.x]=now.y,qq[now.x]=i,S|=1<<now.x-1;
				res=need-(sum[now.x]-a[now.x][now.y]);
				i=now.x,now=s[res];
			}
			if (now.x==sti&&res==a[sti][st]&&!f[S]) {
				qq[sti]=i,f[S]=1;
				memcpy(p[S],pp,sizeof(pp));
				memcpy(q[S],qq,sizeof(qq));
			}
		}
	}
	memcpy(g,f,sizeof(f));
	for(S=1;S<1<<K;S++) if (!g[S])
		dg(0,1,S); else g0[S]=S;
	if (g[(1<<K)-1]) {
		printf("Yes\n");
		mem(pp),mem(qq);
		S=(1<<K)-1;
		while (S) {
			int T=g0[S];
			for(i=1;i<=K;i++) if (T&(1<<i-1)) 
				pp[i]=p[T][i],qq[i]=q[T][i];
			S^=T;
		}
		for(i=1;i<=K;i++) printf("%d %d\n",a[i][pp[i]],qq[i]);
	} else printf("No");
}