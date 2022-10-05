#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
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

const int N=5e5+5,mod=1e9+7;
int pa[N],w[N],mark[N];
int n,m,K,u,v;
vi ans;

int gp(int x){
	if(x==pa[x]) return x;
	return pa[x]=gp(pa[x]);
}

void rmain(){
	read(m),read(n);
	rep(i,1,n){
		pa[i]=i,mark[i]=0;
	}
	ans.clear();
	rep(i,1,m){
		read(K);
		if(K==1){
			read(u);
			int x=gp(u);
			if(!mark[x]){
				mark[x]=1;
				ans.pb(i);
			}
		}
		else{
			read(u),read(v);
			int x=gp(u),y=gp(v);
			if(x==y) continue;
			if(mark[x]&&mark[y]) continue;
			pa[x]=y,mark[y]|=mark[x];
			ans.pb(i);
		}
	}
	int owo=1;
	rep(i,1,SZ(ans)){
		owo=2*owo%mod;
	}
	printf("%d %d\n",owo,SZ(ans));
	for(auto x:ans){
		printf("%d ",x);
	}
	puts("");
}

int main(){
	rmain();
	return 0;
	int T; read(T);
	for(;T;T--) rmain();
	return 0;
}