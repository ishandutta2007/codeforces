#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#define eb emplace_back
#define pb push_back
#define pw(x) ((1LL)<<(x))
#define buli(x) (__builtin_popcountll(x))
typedef long long ll;
typedef double db;
const int inf=1e9;
const int md=1e9+7;
const int maxn=1e3+10;
const db eps=1e-6;
inline void rd(long long &x){
	int sign=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sign=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sign;
}
inline void rd(double&x){scanf("%lf",&x);}
inline void rd(int &x){ll y=0;rd(y);x=y;}
inline void upd(int &a,int b){a+=b;if(a>=md)a-=md;}
int n,m,T,x,y,z,nk,num,k,nq,ans;
const int moved[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
vector<tuple<int,int>> p[3000];
int v[maxn][maxn];
char s[maxn][maxn];
bool ok;
void dfs(int x,int y){
	v[x][y]=1;
	if(x==1 || y==1 || x==n|| y==m) ok=false;

	p[k].eb(x,y);
	num++;
	for(int i=0;i<4;i++){
		int x1=x+moved[i][0],y1=y+moved[i][1];
		if(x1>0 && x1<=n && y1>0 && y1<=m && !v[x1][y1] && s[x1][y1]=='.'){
			dfs(x1,y1);
		}
	}
}
int main(){
	#ifdef GJY
		freopen("t.in","r",stdin);
	#endif
	rd(n);rd(m);rd(nk);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	vector<tuple<int,int> > g;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) if(!v[i][j] && s[i][j]=='.') {
			num=0;k++;
			ok=true;
			dfs(i,j);
			if(ok)g.eb(num,k);
		}
	sort(g.begin(),g.end());
	int have=g.size();
	for(int i=0;i<g.size();i++){
		if(have==nk)break;
		int num,k;
		tie(num,k)=g[i];
		for(int j=0;j<p[k].size();j++){
			int x,y;
			tie(x,y)=p[k][j];
			s[x][y]='*';
		}
		ans+=num;
		have--;

	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)printf("%c",s[i][j]);
		printf("\n");
	}
	
}