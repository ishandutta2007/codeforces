#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=(1<<14)+10;
int n,m,a[2][MAXN],ans;
int vis[2][MAXN];
pi fa[2][MAXN],tmp[MAXN];
pi Find(int now,int x){
	if(mp(now,x)==fa[now][x])return fa[now][x];
	return fa[now][x]=Find(fa[now][x].fr,fa[now][x].se);
}
char c,s[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		int cnt=0,now=i&1,pre=(i-1)&1;
		scanf("%s",s+1);
		rep(j,1,m/4){
			c=s[j];
			int cc;if(c>='0' && c<='9')cc=c-'0';else cc=10+(c-'A');
			a[now][++cnt]=(cc>>3)&1;
			a[now][++cnt]=(cc>>2)&1;
			a[now][++cnt]=(cc>>1)&1;
			a[now][++cnt]=cc&1;
		}
		rep(j,1,m)fa[now][j]=mp(now,j);
		rep(j,1,m){
			if(!a[now][j])continue;
			ans++;
			//merge pre
			if(i>1 && a[pre][j]){
				ans--;
				pi ret=Find(now,j);
				fa[ret.fr][ret.se]=Find(pre,j);
			}
			//merge left
			if(j>1 && a[now][j-1]){
				if(Find(now,j-1)!=Find(now,j)){
					ans--;
					pi ret=Find(now,j);
					fa[ret.fr][ret.se]=Find(now,j-1);
				}
			}
		}
		//update father
		rep(j,1,m){
			tmp[j]=Find(now,j);
		}
		rep(j,1,m){
			if(!vis[tmp[j].fr][tmp[j].se])vis[tmp[j].fr][tmp[j].se]=j;
			fa[now][j]=mp(now,vis[tmp[j].fr][tmp[j].se]);
		}
		rep(j,1,m)vis[tmp[j].fr][tmp[j].se]=0;
	}
	printf("%d\n",ans);

	return 0;
}