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

const int N=1005;
int f[N],n,a,b;
vi e[N];

void dfs(int u,int fa){
	int las=0;
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs(v,u);
		if(f[v]) continue;
		if(las){
			cout<<"? "<<las<<" "<<v<<endl;
			int x; read(x);
			if(x==las||x==v){
				cout<<"! "<<x<<endl;
				exit(0);
			}
			las=0;
		}
		else las=v;
	}
	if(!las) return;
	int y=(fa?fa:u);
	cout<<"? "<<las<<" "<<y<<endl;
	int x; read(x);
	if(x==las||x==u){
		cout<<"! "<<x<<endl;
		exit(0);
	}
	f[u]=1;
}

int main(){
	read(n);
	rep(i,1,n-1){
		read(a),read(b);
		e[a].pb(b);
		e[b].pb(a);
	}
	if(n==2){
		cout<<"? 1 2"<<endl;
		int x; read(x);
		cout<<"! "<<x<<endl;
		return 0;
	}
	int rt=1;
	while(e[rt].size()>=2) rt++;
	dfs(rt,0);
	cout<<"! "<<rt<<endl;
	return 0;
}