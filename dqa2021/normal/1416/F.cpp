#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#include<assert.h>
#include<cstring>
#define pb push_back
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G

int n,m;
vector<int> mp[100010];
vector<int> A[100010];
vector<char> B[100010];
vector<int> id[100010];
struct Rec{
	int x,y,v;
}rec[100010]; int rectop;
bool operator<(const Rec &x,const Rec &y){
	return x.v<y.v;
}

struct Edge{
	int to,nxt,val;
}edge[1250000];
int cnt,last[100010],S,T,O,idtot,_last[100010];  //cnt=1
inline void addedge(int x,int y,int v){
//	printf("addedge %d %d %d\n",x,y,v);
	edge[++cnt]=(Edge){y,last[x],v},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y],0},last[y]=cnt;
}
int que[100010],hd,tl;
int dep[100010];
bool bfs(){
	hd=tl=0;
	memset(dep+1,-1,idtot<<2);
	dep[S]=1; que[++tl]=S;
	while (hd<tl){
		int u=que[++hd],v;
		for (int i=last[u];i;i=edge[i].nxt)
			if (edge[i].val&&!~dep[v=edge[i].to]){
				dep[v]=dep[u]+1;
				if (v==T) return 1;
				que[++tl]=v;
			}
	}
	return 0;
}
int dfs(int x,int flw){
	if (x==T) return flw;
	int t,used=0;
	for (int &i=_last[x],v;i;i=edge[i].nxt)
		if (edge[i].val&&dep[x]+1==dep[v=edge[i].to]){
			t=dfs(v,min(flw-used,edge[i].val));
			edge[i].val-=t; edge[i^1].val+=t;
			used+=t; if (used==flw) return used;
		}
	if (!used) dep[x]=-1;
	return used;
}
int dinic(){
	int res=0;
	while (bfs()){
		memcpy(_last+1,last+1,idtot<<2);
		res+=dfs(S,1e9);
	}
//	printf("S %d T %d\n",S,T);
//	printf("dinic %d\n",res);
	return res;
}

int deg[100010];  //I-O

bool work(int l,int r,int w){
	idtot=0;
	for (int i=l;i<=r;i++) id[rec[i].x][rec[i].y]=++idtot;
	O=++idtot,S=++idtot,T=++idtot;
	cnt=1; for (int i=1;i<=idtot;i++) deg[i]=0,last[i]=0;
	for (int i=l;i<=r;i++){
		int x=rec[i].x,y=rec[i].y;
		if (x+y&1){
			if (x>1&&mp[x-1][y]==w)
				addedge(id[x][y],id[x-1][y],1);
			if (x<n&&mp[x+1][y]==w)
				addedge(id[x][y],id[x+1][y],1);
			if (y>1&&mp[x][y-1]==w)
				addedge(id[x][y],id[x][y-1],1);
			if (y<m&&mp[x][y+1]==w)
				addedge(id[x][y],id[x][y+1],1);
		}
		bool flg=0;
		flg|=x>1&&mp[x-1][y]<w;
		flg|=x<n&&mp[x+1][y]<w;
		flg|=y>1&&mp[x][y-1]<w;
		flg|=y<m&&mp[x][y+1]<w;
		if (!flg)
			if ((x+y)&1) deg[O]--,deg[id[x][y]]++;
			else deg[id[x][y]]--,deg[O]++;
		else if ((x+y)&1) addedge(O,id[x][y],1);
			else addedge(id[x][y],O,1);
	}
	int tot=0;
	for (int i=1;i<=O;i++)
		if (deg[i]>0) addedge(S,i,deg[i]),tot+=deg[i];
		else if (deg[i]<0) addedge(i,T,-deg[i]);
//	printf("tot %d\n",tot);
	if (dinic()^tot) return 0;
	
	for (int i=l;i<=r;i++){
		int x=rec[i].x,y=rec[i].y,u=id[x][y],v=-1;
		for (int j=last[u];j;j=edge[j].nxt){
			v=edge[j].to; if (v>=O){v=-1;continue;}
			if ((x+y)&1&&!edge[j].val||!((x+y)&1)&&edge[j].val) break;
			else v=-1;
		}
		if (~v){
			v=l+v-1;
			int _x=rec[v].x,_y=rec[v].y;
			if (_x==x-1) B[x][y]='U';
			else if (_x==x+1) B[x][y]='D';
			else if (_y==y-1) B[x][y]='L';
			else if (_y==y+1) B[x][y]='R';
			else assert(0);
			A[x][y]=1,A[_x][_y]=w-1;
		}
		else{
			if (x>1&&mp[x-1][y]<w) B[x][y]='U',A[x][y]=w-mp[x-1][y];
			else if (x<n&&mp[x+1][y]<w) B[x][y]='D',A[x][y]=w-mp[x+1][y];
			else if (y>1&&mp[x][y-1]<w) B[x][y]='L',A[x][y]=w-mp[x][y-1];
			else if (y<m&&mp[x][y+1]<w) B[x][y]='R',A[x][y]=w-mp[x][y+1];
			else assert(0);
		}
	}
	return 1;
}
void init(){
	for (int i=1;i<=n;i++){
		vector<int>().swap(mp[i]);
		vector<int>().swap(A[i]);
		vector<char>().swap(B[i]);
		vector<int>().swap(id[i]);
	}
//	...
}
void solve(){
	n=read(),m=read();
	rectop=0;
	for (int i=1;i<=n;i++){
		mp[i].resize(m+1);
		A[i].resize(m+1);
		B[i].resize(m+1);
		id[i].resize(m+1);
		for (int j=1;j<=m;j++){
			mp[i][j]=read();
			rec[++rectop]=(Rec){i,j,mp[i][j]};
		}
	}
	sort(rec+1,rec+rectop+1);
	bool flg=1;
	for (int i=1,j;flg&&i<=rectop;i=j+1){
		for (j=i;j<rectop&&rec[j+1].v==rec[j].v;j++);
		flg&=work(i,j,rec[i].v);
	}
	if (!flg) puts("NO");
	else{
		puts("YES");
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				printf("%d%c",A[i][j]," \n"[j==m]);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				printf("%c%c",B[i][j]," \n"[j==m]);
	}
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}