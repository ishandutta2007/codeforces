#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se seoncd
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

const int N=300005;
int pa[N],s[N][2],w[N],mark[N],x[N],y[N];
int n,K,a,b,c,ans;
char st[N];

int getpa(int x){
	if(pa[x]==x) return x;
	int p=pa[x];
	pa[x]=getpa(pa[x]);
	w[x]^=w[p];
	return pa[x];
}

void add(int x,int op){
//	printf("## %d %d %d %d\n",x,mark[x],s[x][0],s[x][1]);
	if(mark[x]!=-1) ans+=op*s[x][mark[x]];
	else ans+=op*min(s[x][0],s[x][1]);
}

void make(int a,int v){
	int x=getpa(a);
	add(x,-1);
	mark[x]=w[a]^v;
	add(x,1);
}

void link(int a,int b,int v){
	int x=getpa(a),y=getpa(b);
	if(x==y) return;
	add(x,-1),add(y,-1);
	w[x]=w[a]^w[b]^v;
	s[y][0]+=s[x][w[x]];
	s[y][1]+=s[x][w[x]^1];
	if(mark[x]!=-1) mark[y]=mark[x]^w[x];
	pa[x]=y;
	add(y,1);
}

int main(){
	read(n),read(K);
	scanf("%s",st+1);
	rep(i,1,K){
		read(c);
		rep(j,1,c){
			read(a);
			if(!x[a]) x[a]=i;
			else y[a]=i;
		}
	}
	rep(i,1,K){
		pa[i]=i,s[i][1]=1,mark[i]=-1;
	}
	rep(i,1,n){
		if(!y[i]) make(x[i],st[i]=='1'?0:1);
		else link(x[i],y[i],st[i]=='1'?0:1);
		printf("%d\n",ans);
	}	
	return 0;
}