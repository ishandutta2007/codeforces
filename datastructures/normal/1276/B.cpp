#include <iostream> 
#include <cstdio>
using namespace std;
int u[1000005],v[1000005],nxt[1000005],first[1000005];
int t,n,m,a,b,s1,s2,book[1000005];
inline int dfs(int now){
	if (book[now]==1)return 0;
	book[now]=1;
	int s=1;
	for (int i=first[now];i;i=nxt[i])
		s+=dfs(v[i]);
	return s;
}
signed main(){
	cin>>t;
	while(t--){
		scanf("%d%d%d%d",&n,&m,&a,&b);
		for (int i=0;i<=2*m+5;i++)u[i]=v[i]=first[i]=nxt[i]=0;
		for (int i=1;i<=m;i++){
			scanf("%d%d",&u[i],&v[i]);
			nxt[i]=first[u[i]],first[u[i]]=i;
			u[i+m]=v[i],v[i+m]=u[i];
			nxt[i+m]=first[u[i+m]],first[u[i+m]]=i+m;
		}
		s1=s2=0;
		for (int i=0;i<=n+5;i++)book[i]=0;
		book[a]=1;
		for (int i=first[a];i;i=nxt[i]){
			if (book[v[i]]!=0)continue;
			int x=dfs(v[i]);
			if (book[b]!=0){
				book[b]=0;
				continue;
			}
			s1+=x;
		}
		for (int i=0;i<=n+5;i++)book[i]=0;
		book[b]=1;
		for (int i=first[b];i;i=nxt[i]){
			if (book[v[i]]!=0)continue;
			int x=dfs(v[i]);
			if (book[a]!=0){
				book[a]=0;
				continue;
			}
			s2+=x;
		}
		cout<<1ll*s1*s2<<endl;
	}
	return 0;
}