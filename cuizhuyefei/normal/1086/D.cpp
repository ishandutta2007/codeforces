#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 233333;
int n,q,a[N];
set<int>Set[3];int v[3][N];
int getid(char c){
	if(c=='P')return 2;
	if(c=='R')return 1;
	if(c=='S')return 0;
}
void add(int *v, int p, int x){while(p<=n)v[p]+=x,p+=p&-p;}
int query(int *v, int p){int r=0;while(p)r+=v[p],p-=p&-p;return r;}
int query(int i, int l, int r){
	if(l>r)return 0;
	return query(v[i],r)-query(v[i],l-1);
}
void ins(int x, int y, int tp){
	if(tp<0)Set[y].erase(x);else Set[y].insert(x);
	add(v[y],x,tp);
}
int query(){
	int S=0;rep(i,0,2)if(SZ(Set[i]))S|=1<<i;
		int res=0;
		if(S==7){
			res=n;
			rep(i,0,2){
				int a=(i+1)%3,b=(i-1+3)%3;
				res-=query(i,*Set[a].begin(),*Set[b].begin())+query(i,*Set[b].rbegin(),*Set[a].rbegin());
			}
		}
		else if(S==3){//0 1
			res=n-SZ(Set[0]);
		}
		else if(S==5){//0 2
			res=n-SZ(Set[2]);
		}
		else if(S==6){//1 2
			res=n-SZ(Set[1]);
		}
		else res=n;
		return res;
}
int main() {
	read(n);read(q);static char t[N];
	scanf("%s",t+1);rep(i,1,n)a[i]=getid(t[i]);
	rep(i,1,n)ins(i,a[i],1);
	printf("%d\n",query());
	while(q--){
		int x;read(x);scanf("%s",t);int y=getid(t[0]);
		ins(x,a[x],-1);a[x]=y;ins(x,y,1);
		printf("%d\n",query());
		
	}
	return 0;
}