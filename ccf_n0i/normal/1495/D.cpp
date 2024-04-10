#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
const int mod1=998244353,mod2=19491001;
int d[405][405],vis[405],ans[405][405],f1[405],f2[405];
int n,m,i,j,k;
vector<int> g[405];
int main(){
	scanf("%d%d",&n,&m);
	memset(d,0x3f,sizeof(d));
	rep(i,n) d[i][i]=0;
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);g[y].push_back(x);
		d[x][y]=d[y][x]=1;
	}
	rep(k,n)rep(i,n)rep(j,n) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	rep(i,n){
		memset(f1,0,sizeof(f1));memset(f2,0,sizeof(f2));
		memset(vis,0,sizeof(vis));
		f1[i]=f2[i]=1;vis[i]=1;
		queue<int> q;q.push(i);
		while(!q.empty()){
			int x=q.front();q.pop();
			dzd(g[x],it){
				if(d[i][*it]==d[i][x]+1){
					if(!vis[*it]){
						vis[*it]=1;
						q.push(*it);
					}
					f1[*it]+=f1[x];if(f1[*it]>=mod1)f1[*it]-=mod1;
					f2[*it]+=f2[x];if(f2[*it]>=mod2)f2[*it]-=mod2;
				}
			}
		}
		rep(j,n)if(f1[j]==1&&f2[j]==1){
			ans[i][j]=1;
			rep(k,n)if(d[i][k]+d[k][j]!=d[i][j]){
				int c=0;
				dzd(g[k],it) if(d[i][*it]+1==d[i][k]&&d[j][*it]+1==d[j][k]){
					c++;
				}
				ans[i][j]=1ll*ans[i][j]*c%mod1;
			}
		}
	}
	rep(i,n){
		rep(j,n){
			cout<<ans[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}