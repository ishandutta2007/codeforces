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
const int MAXN=1e5+10,MAXM=12,MAXK=350;
int n,m,q,x,y,lim;
int num[MAXN],st[MAXN],ed[MAXN],tot;
int vis[MAXN][MAXM];
ppi nxt[MAXN][MAXM];
char s[MAXN][MAXM],op,ch;
void dfs(int r,int c){
	vis[r][c]=2;
	int rr=r,cc=c;
	if(s[r][c]=='<')cc--;
	else if(s[r][c]=='>')cc++;
	else rr--;
	if(num[rr]!=num[r] || cc<1 || cc>m){
		nxt[r][c]=mp(1,mp(r,c));
		vis[r][c]=1;
		return;
	}
	if(vis[rr][cc]==0){
		dfs(rr,cc);
		nxt[r][c]=nxt[rr][cc];
		vis[r][c]=1;
		return;
	}
	if(vis[rr][cc]==1){
		nxt[r][c]=nxt[rr][cc];
		vis[r][c]=1;
		return;
	}
	nxt[r][c]=mp(2,mp(r,c));
	vis[r][c]=1;
	return;
}
void pre(){
	rep(i,1,n){num[i]=(i-1)/lim+1;}
	rep(i,1,n){
		if(num[i-1]!=num[i])st[num[i]]=i;
		if(num[i+1]!=num[i])ed[num[i]]=i;
	}
	tot=num[n];
	rep(i,1,tot){
		rep(r,st[i],ed[i]){
			rep(c,1,m){
				if(!vis[r][c]){
					dfs(r,c);
				}
			}
		}
	}
}
void update(){
	s[x][y]=ch;
	int d=num[x];
	rep(r,st[d],ed[d]){
		rep(c,1,m){
			vis[r][c]=0;
		}
	}
	rep(r,st[d],ed[d]){
		rep(c,1,m){
			if(!vis[r][c]){
				dfs(r,c);
			}
		}
	}
}
void query(){
	int r=x,c=y;
	while(1){
		if(nxt[r][c].fr==2){
			r=c=-1;break;
		}
		int rr=nxt[r][c].se.fr,cc=nxt[r][c].se.se;
		r=rr,c=cc;
		if(s[r][c]=='<')cc--;
		else if(s[r][c]=='>')cc++;
		else rr--;
		r=rr;c=cc;
		if(rr<1 || cc<1 || cc>m)break;
	}
	printf("%d %d\n",r,c);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	lim=sqrt(n)+1;
	rep(i,1,n)rep(j,1,m)scanf(" %c",&s[i][j]);
	pre();
	rep(i,1,q){
		scanf(" %c%d%d",&op,&x,&y);
		if(op=='C'){
			scanf(" %c",&ch);
			update();
		}else{
			query();
		}
	}
	return 0;
}