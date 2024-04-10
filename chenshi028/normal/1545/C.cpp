#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
const int o=1010,MOD=998244353;
int T,n,a[o][o],c[o][o],vis[o],ans;vector<int> vec[o][o];queue<pair<int,int> > q;
int main(){
	for(scanf("%d",&T);T--;putchar('\n'),queue<pair<int,int> >().swap(q)){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) c[i][j]=0,vec[i][j].clear();
		for(int i=ans=1;i<=n*2;vis[i++]=0) for(int j=1;j<=n;++j)
			scanf("%d",&a[i][j]),++c[j][a[i][j]],vec[j][a[i][j]].push_back(i);
		for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(c[i][j]==1) q.push(make_pair(i,j));
		for(int cnt=0,x,y;cnt<n;){
			if(!q.empty()){
				x=q.front().first;y=q.front().second;q.pop();
				if(c[x][y]^1) continue;
				for(int i=vec[x][y].size();i--;) if(!vis[vec[x][y][i]]){x=vec[x][y][i];break;}
			}
			else for(x=1,ans=ans*2%MOD;vis[x];++x);
			vis[x]=1;++cnt;
			for(int i=1;i<=n;++i){
				c[i][a[x][i]]=0;
				for(int j=vec[i][a[x][i]].size();j--;) if(!vis[y=vec[i][a[x][i]][j]]){
					vis[y]=2;
					for(int k=1;k<=n;++k) if(--c[k][a[y][k]]==1) q.push(make_pair(k,a[y][k]));
				}
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n*2;++i) if(vis[i]==1) printf("%d ",i);
	}
	return 0;
}