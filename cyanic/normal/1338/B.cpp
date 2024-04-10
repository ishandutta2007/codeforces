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

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=100005;
int c[N],lea[N],n,a,b,rt,ans1=1,ans2;
vi e[N];

void dfs(int u,int fa,int col){
	c[u]=col;
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs(v,u,col^1);
	}
}

int main(){
	read(n);
	rep(i,1,n-1){
		read(a),read(b);
		e[a].pb(b),e[b].pb(a);
	}
	rep(i,1,n){
		lea[i]=(e[i].size()==1);
		if(lea[i]) rt=i;
	}
	dfs(rt,0,0);
	rep(i,1,n){
		if(lea[i]&&c[i]){
			ans1=3;
			break;
		}
	}
	ans2=n-1;
	rep(i,1,n){
		int cnt=0;
		for(auto v:e[i])
			if(lea[v]) cnt++;
		if(cnt) ans2-=cnt-1;
	}
	cout<<ans1<<" "<<ans2<<endl;

	return 0;
}