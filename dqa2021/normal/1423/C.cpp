#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#define pb push_back
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
int S;  //75 key points

int n,k;
struct Rec{
	int u,v;
}rec[100010]; int top;
bool inq[10010];

struct Edge{
	int to,nxt;
}edge[20010];
int cnt=1,last[10010];
inline void addedge(int x,int y){
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}

bool mrk[10010];
int Siz,Rt,siz[10010],maxs[10010];
void getsiz(int x,int f){
	siz[x]=1;
	for (int i=last[x],v;i;i=edge[i].nxt)
		if (!mrk[v=edge[i].to]&&v^f)
			getsiz(v,x),siz[x]+=siz[v];
}
void getroot(int x,int f){
	maxs[x]=0;
	for (int i=last[x],v;i;i=edge[i].nxt)
		if (!mrk[v=edge[i].to]&&v^f)
			getroot(v,x),maxs[x]=max(maxs[x],siz[v]);
	maxs[x]=max(maxs[x],Siz-siz[x]);
	if (!~Rt||maxs[x]<maxs[Rt]) Rt=x;
}

int stk[10010],stktop;
void dfs1(int x,int f){
	stk[++stktop]=x;
	for (int i=last[x],v;i;i=edge[i].nxt)
		if (!mrk[v=edge[i].to]&&v^f)
			dfs1(v,x);
}

void solve(int x){
	mrk[x]=1;
	stktop=0; dfs1(x,0);
	for (int i=2;i<=stktop;i++){
		int y=stk[i];
		rec[++top]=(Rec){x,y};
	}
	for (int i=last[x],v;i;i=edge[i].nxt)
		if (!mrk[v=edge[i].to]){
			getsiz(v,0); Siz=siz[v],Rt=-1;
			getroot(v,0); solve(Rt);
		}
}

int tot[10010];
vector<int> T[10010];
int fat[10010];
void dfs0(int x,int f){
	tot[x]=1; fat[x]=f;
	for (int i=last[x],v;i;i=edge[i].nxt)
		if ((v=edge[i].to)^f){
			dfs0(v,x);
			if (!mrk[v]) tot[x]+=tot[v];
		}
	if (x!=1&&tot[x]<S) return;
	mrk[x]=1; inq[x]=1;
	T[x].reserve(tot[x]-1);
	for (int i=last[x],v;i;i=edge[i].nxt)
		if ((v=edge[i].to)^f){
			if (mrk[v]) continue;
			stktop=0; dfs1(v,0);
			for (int j=1;j<=stktop;j++){
				int y=stk[j];
				rec[++top]=(Rec){x,y};
				T[x].pb(y);
			}
			getsiz(v,0); Siz=siz[v],Rt=-1;
			getroot(v,0); solve(Rt);
		}
}
int main()
{
	n=read(),k=read();
	for (int i=1;i<n;i++) addedge(read(),read());
	if (n<=1000){
		getsiz(1,0); Siz=siz[1],Rt=-1;
		getroot(1,0); solve(Rt);
	}
	else{
		S=(n+74)/75;
		dfs0(1,0);
		stktop=0;
		for (int i=1;i<=n;i++) if (inq[i]) stk[++stktop]=i;
		for (int i=1;i<=stktop;i++)
			for (int j=i+1;j<=stktop;j++){
				int x=stk[i],y=stk[j];
				rec[++top]=(Rec){x,y};
			}
		for (int i=1;i<=stktop;i++){
			int xx=stk[i],x=fat[stk[i]];
			while (x&&!inq[x]) x=fat[x];
			if (!x) continue;
			for (int y: T[x]) rec[++top]=(Rec){xx,y};
		}
	}
	printf("%d\n",top);
	for (int i=1;i<=top;i++) printf("%d %d\n",rec[i].u,rec[i].v);
	return 0;
}