#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<cassert>
#include<queue>
#include<cmath>
#include<queue>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
const int maxn=1000005;
char s[10];
int n,op[maxn],v[maxn],change[maxn];
int son[maxn][2];
inline void dfs(int x){
	if(op[x]==4)return;
	if(op[x]==1){
		dfs(son[x][0]);dfs(son[x][1]);
		v[x]=v[son[x][0]] and v[son[x][1]];
	}
	if(op[x]==2){
		dfs(son[x][0]);dfs(son[x][1]);
		v[x]=v[son[x][0]] xor v[son[x][1]];
	}
	if(op[x]==3){
		dfs(son[x][0]);
		v[x]=not v[son[x][0]];
	}
	if(op[x]==5){
		dfs(son[x][0]);dfs(son[x][1]);
		v[x]=v[son[x][0]] or v[son[x][1]];
	}
}
inline void solve(int x){
	if(op[x]==4)return;
	change[son[x][1]]=change[son[x][0]]=change[x];
	if(op[x]==1){
		if(v[son[x][1]]==0)change[son[x][0]]=0;
		if(v[son[x][0]]==0)change[son[x][1]]=0;
		solve(son[x][0]);solve(son[x][1]);
	}
	if(op[x]==2){
		solve(son[x][0]);solve(son[x][1]);
	}
	if(op[x]==3){
		solve(son[x][0]);
	}
	if(op[x]==5){
		if(v[son[x][1]]==1)change[son[x][0]]=0;
		if(v[son[x][0]]==1)change[son[x][1]]=0;
		solve(son[x][0]);solve(son[x][1]);
	}
}
int main(){
	read(n);
	rep(i,1,n){
		scanf("%s",s+1);
		if(s[1]=='A'){
			op[i]=1;
			read(son[i][0]);read(son[i][1]);
		}
		if(s[1]=='X'){
			op[i]=2;
			read(son[i][0]);read(son[i][1]);
		}
		if(s[1]=='N'){
			op[i]=3;
			read(son[i][0]);
		}
		if(s[1]=='I'){
			op[i]=4;
			read(v[i]);
		}
		if(s[1]=='O'){
			op[i]=5;
			// read(v[i]);
			read(son[i][0]);read(son[i][1]);
		}
	}
	//assert(0);
	dfs(1);
	change[1]=1;
	solve(1);
	rep(i,1,n)if(op[i]==4){
		int ans=v[1];
		if(change[i])ans^=1;
		putchar(ans+'0');
	}
	return 0;
}