#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=100005;
int vis[N],ans[N],len[3],n,m,a,b,con,num,flag;
vi e[N],l[3];

void dfs(int u,int fa){
	vis[u]=con;
	for(auto v:e[u]){
		if(!vis[v]) dfs(v,u);
		else if(v!=fa) flag=con;
	}
}

int find(int u,int fa,int k){
	if(e[u].size()==3) return u;
	len[k]++,vis[u]=num,l[k].pb(u);
	for(auto v:e[u]){
		if(v==fa) continue;
		int ret=find(v,u,k);
		if(ret) return ret;
	}	
	return 0;
}

void rmain(){
	read(n),read(m);
	rep(i,1,n){
		e[i].clear();
		vis[i]=0;
	}
	rep(i,1,m){
		read(a),read(b);
		e[a].pb(b),e[b].pb(a);
	}
	flag=con=0;
	rep(i,1,n){
		if(!vis[i]){
			++con,dfs(i,0);
		}
	}
	if(flag){
		puts("YES");
		rep(i,1,n) printf("%d ",(vis[i]==flag));
		puts("");
		return;
	}
	rep(u,1,n){
		if(e[u].size()>=4){
			for(auto v:e[u]) vis[v]=-1;
			puts("YES");
			rep(i,1,n) printf("%d ",(vis[i]==-1)+2*(i==u));
			puts("");
			return;
		}
	}
	rep(i,1,n) vis[i]=0;
	num=0;
	rep(u,1,n){
		if(e[u].size()==3&&!vis[u]){
			REP(k,3){
				++num,l[k].clear(),len[k]=0;
				int v=find(e[u][k],u,k);
				if(v){
					for(auto t:e[u]) if(vis[t]!=num) vis[t]=-1;
					for(auto t:e[v]) if(vis[t]!=num) vis[t]=-1;
					puts("YES");
					rep(i,1,n){
						printf("%d ",(i==u||i==v||vis[i]==num?2:
									(vis[i]==-1?1:0)));
					}
					puts("");
					return;
				}
			}
			if(len[0]>=2&&len[1]>=2&&len[2]>=2){
				fill(ans+1,ans+n+1,0);
				REP(k,3){
					int x=e[u][k];
					ans[e[x][0]]++,ans[e[x][1]]++,ans[x]=2;
				}
				puts("YES");
				rep(i,1,n) printf("%d ",ans[i]);
				puts("");
				return;
			}
			int r[3]={0,1,2};
			sort(r,r+3,[&](int a,int b){
				return len[a]<len[b];
			});
			if(len[r[1]]>=3&&len[r[2]]>=3){
				fill(ans+1,ans+n+1,0);
				ans[u]=4;
				ans[l[r[0]][0]]=2;
				ans[l[r[1]][0]]=3,ans[l[r[1]][1]]=2,ans[l[r[1]][2]]=1;
				ans[l[r[2]][0]]=3,ans[l[r[2]][1]]=2,ans[l[r[2]][2]]=1;
				puts("YES");
				rep(i,1,n) printf("%d ",ans[i]);
				puts("");
				return;
			}
			if(len[r[1]]>=2&&len[r[2]]>=5){
				fill(ans+1,ans+n+1,0);
				ans[u]=6;
				ans[l[r[0]][0]]=3;
				ans[l[r[1]][0]]=4,ans[l[r[1]][1]]=2;
				ans[l[r[2]][0]]=5,ans[l[r[2]][1]]=4,ans[l[r[2]][2]]=3;
				ans[l[r[2]][3]]=2,ans[l[r[2]][4]]=1;
				puts("YES");
				rep(i,1,n) printf("%d ",ans[i]);
				puts("");
				return;
			}
		}
	}
	puts("NO");
}

int main(){
	int T; read(T);
	while(T--) rmain();
	return 0;
}