//#include<cstdio>
//#include<algorithm>
//using namespace std;
//typedef long long ll;
//
//int n;
//struct Edge{
//	int to,nxt,val;
//}edge[400010];
//int cnt,last[200010];
//inline void addedge(int x,int y,int v)
//{
//	edge[++cnt]=(Edge){y,last[x],v},last[x]=cnt;
//	edge[++cnt]=(Edge){x,last[y],v},last[y]=cnt;
//}
//namespace N
//{
//	bool vis[200010];
//	int Rt,Siz,siz[200010],maxson[200010];
//	void getsiz(int cur,int fat)
//	{
//		siz[cur]=1; maxson[cur]=0;
//		for (int i=last[cur];i;i=edge[i].nxt)
//			if (!vis[edge[i].to]&&edge[i].to!=fat)
//				getsiz(edge[i].to,cur),siz[cur]+=siz[edge[i].to],maxson[cur]=max(maxson[cur],siz[edge[i].to]);
//	}
//	void getroot(int cur,int fat)
//	{
//		for (int i=last[cur];i;i=edge[i].nxt)
//			if (!vis[edge[i].to]&&edge[i].to!=fat)
//				getroot(edge[i].to,cur);
//		maxson[cur]=max(maxson[cur],Siz-siz[cur]);
//		if (Rt==-1||maxson[Rt]>maxson[cur]) Rt=cur;
//	}
//	int tot[4];
//	void dfs(int cur,int fat,int id)
//	{
//		tot[id]++;
//		for (int i=last[cur];i;i=edge[i].nxt)
//			if (!vis[edge[i].to]&&edge[i].to!=fat)
//			{
//				int nxt;
//				if (id==0&&edge[i].val==0) nxt=0;
//				else if (id==0&&edge[i].val==1) nxt=2;
//				else if (id==1&&edge[i].val==0) nxt=3;
//				else if (id==1&&edge[i].val==1) nxt=1;
//				else if (id==2&&edge[i].val==1) nxt=2;
//				else if (id==3&&edge[i].val==0) nxt=3;
//				else continue;
//				dfs(edge[i].to,cur,nxt);
//			}
//	}
//	void work(int cur)
//	{
//		int a=0,b=0,c=0,d=0; A=B=C=D=0;
//		for (int i=last[cur];i;i=edge[i].nxt)
//			if (!vis[edge[i].to])
//			{
//				dfs()
//			}
//	}
//	void solve(int cur)
//	{
//		vis[cur]=true;
//		
//	}
//}
//int main()
//{
//	
//}


#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int n;
struct Edge{
	int to,nxt,val;
}edge[400010];
int cnt,last[200010];
inline void addedge(int x,int y,int v)
{
	edge[++cnt]=(Edge){y,last[x],v},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y],v},last[y]=cnt;
}
int f[200010][4];
ll ans;
void dfs(int cur,int fat)
{
//	printf("ans1 %lld\n",ans);
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=fat)
		{
			dfs(edge[i].to,cur);
			if (edge[i].val==0)
			{
				f[edge[i].to][0]++;
				f[edge[i].to][2]+=f[edge[i].to][1];
				f[edge[i].to][1]=0;
				f[edge[i].to][3]=0;
			}
			else
			{
				f[edge[i].to][1]++;
				f[edge[i].to][3]+=f[edge[i].to][0];
				f[edge[i].to][0]=0;
				f[edge[i].to][2]=0;
			}
//			printf("meet %d and %d: %d %d %d %d  %d %d %d %d\n",cur,edge[i].to,f[cur][0],f[cur][1],f[cur][2],f[cur][3],f[edge[i].to][0],f[edge[i].to][1],f[edge[i].to][2],f[edge[i].to][3]);
			ans+=f[edge[i].to][0]*2+f[edge[i].to][1]*2+f[edge[i].to][2]+f[edge[i].to][3];
			ans+=(ll)f[cur][0]*f[edge[i].to][0]*2+(ll)f[cur][0]*f[edge[i].to][1]+(ll)f[cur][0]*f[edge[i].to][2]
				+(ll)f[cur][1]*f[edge[i].to][0]+(ll)f[cur][1]*f[edge[i].to][1]*2+(ll)f[cur][1]*f[edge[i].to][3]
				+(ll)f[cur][2]*f[edge[i].to][0]+(ll)f[cur][3]*f[edge[i].to][1];
			f[cur][0]+=f[edge[i].to][0];
			f[cur][1]+=f[edge[i].to][1];
			f[cur][2]+=f[edge[i].to][2];
			f[cur][3]+=f[edge[i].to][3];
		}
//	printf("f %d: %d %d %d %d\n",cur,f[cur][0],f[cur][1],f[cur][2],f[cur][3]);
//	printf("ans2 %lld\n",ans);
}
int main()
{
	scanf("%d",&n);
	for (int i=2,x,y,z;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);
	}
	dfs(1,0);
	printf("%I64d\n",ans);
	return 0;
}