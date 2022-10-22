#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
#define lowbit(x) ((x)&-(x))
const int N=1e5+100;
int n,m;
vector<int>Min(vector<int>&A,vector<int>&B){
	if(A.size()&&A[0]==-1)return B;
	if(B.size()&&B[0]==-1)return A;
	return A.size()<B.size()?A:B;
}
class solver{
	private:
	vector<pair<int,int>>e[N];
	int c[N];
	bool vis[N],flag[N];
	vector<int>pp;//
	void dfs(int u){
		vis[u]=1;
		pp.pb(u);
		int v,id;for(auto E:e[u]){
			tie(v,id)=E;
			if(vis[v])continue;
			if(c[id]^flag[u])flag[v]=1;
			dfs(v);
		}
	}
	public:
	void add(int u,int v,int col,int id){
		c[id]=col;
		e[u].pb(mp(v,id));
		e[v].pb(mp(u,id));
	}
	vector<int> solve(){
		vector<int>res;
		for(int i=1;i<=n;i++)if(!vis[i]){
			vector<int>ans1,ans2;
			{
				//ans1
				pp.clear();
				int v,id;
				dfs(i);
				for(auto u:pp)
					for(auto E:e[u]){
						tie(v,id)=E;
						if(flag[u]^c[id]^flag[v]){
							ans1.pb(-1);
							break;
						}
					}
				if(!ans1.size()){
					for(auto u:pp)if(flag[u])
						ans1.pb(u);
				}
				for(auto u:pp)
					vis[u]=flag[u]=0;
			}
			{
				pp.clear();
				int v,id;
				flag[i]=1;
				dfs(i);
				for(auto u:pp)
					for(auto E:e[u]){
						tie(v,id)=E;
						if(flag[u]^c[id]^flag[v]){
							ans2.pb(-1);
							break;
						}
					}
				if(!ans2.size()){
					for(auto u:pp)if(flag[u])
						ans2.pb(u);
				}
			}
			vector<int>tmp=Min(ans1,ans2);
			if(tmp.size()&&tmp[0]==-1)return tmp;
			for(auto x:tmp)res.pb(x);
		}
		return res;
	}
}A,B;
char get(){
	char c=getchar();
	while(!isalpha(c))c=getchar();
	return c;
}
signed main(){
	read(n,m);
	for(int i=1,u,v,c;i<=m;i++)
		read(u,v),c=(get()=='R'),A.add(u,v,c,i),B.add(u,v,c^1,i);
	vector<int>a=A.solve(),b=B.solve();
	a=Min(a,b);
	if(a.size()&&a[0]==-1)puts("-1");
	else{
		writeln(a.size());
		for(auto x:a)writeln(x);
	}
}