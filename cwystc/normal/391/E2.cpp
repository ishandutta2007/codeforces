#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef pair<int,int> pa;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
int n[4],x,y,dep[4][100010],siz[4][100010];
LL d[4][100010],s[4],F[4][100010],G[4][100010],f[4][100010],D[4][100010],ANS,ans;
vector<int> v[4][100010];
void dfs(int h,int x,int l){
	siz[h][x]=1;
	d[h][x]=0ll;
	dep[h][x]=dep[h][l]+1;
	for (int i=0;i<v[h][x].size();++i){
		int y=v[h][x][i];
		if (y==l) continue;
		dfs(h,y,x);
		siz[h][x]+=siz[h][y];
		d[h][x]+=d[h][y]+siz[h][y];
	}
}
void DFS(int h,int x,int l){
	for (int i=0;i<v[h][x].size();++i){
		int y=v[h][x][i];
		if (y==l) continue;
		D[h][y]=d[h][x]-d[h][y]-siz[h][y]+D[h][x]+n[h]-siz[h][y];
		DFS(h,y,x);
	}
}
void dfs1(int h,int x,int l,int na,int nc){
	LL F1=f[h][x]*na+1ll*dep[h][x]*na*nc;
	LL G1=f[h][x]*nc+1ll*dep[h][x]*na*nc;
	ANS=max(ANS,F1+G1-1ll*dep[h][x]*na*nc*2);
	for (int i=0;i<v[h][x].size();++i){
		int y=v[h][x][i];
		if (y==l) continue;
		dfs1(h,y,x,na,nc);
		ANS=max(ANS,F[h][y]+G1-1ll*dep[h][x]*na*nc*2);
		ANS=max(ANS,G[h][y]+F1-1ll*dep[h][x]*na*nc*2);
		F1=max(F1,F[h][y]);
		G1=max(G1,G[h][y]);
	}
	F[h][x]=F1,G[h][x]=G1;
}
void doit(int A,int B,int C){
	LL a=0,c=0;
	FOR(i,1,n[A]) a=max(a,f[A][i]);
	FOR(i,1,n[C]) c=max(c,f[C][i]);
	LL tmp=s[A]+s[C]+s[B];
	tmp+=a*(n[B]+n[C])+c*(n[A]+n[B]);
	tmp+=1ll*n[A]*(n[B]+n[C])+1ll*(n[A]+n[B])*n[C];
	ANS=0;
	dfs1(B,1,0,n[A],n[C]);
	tmp+=ANS;
	ans=max(ans,tmp);
}
int main(){
	cin>>n[1]>>n[2]>>n[3];
	FOR(i,2,n[1]){
		getint(x),getint(y);
		v[1][x].pb(y);
		v[1][y].pb(x);
	}
	FOR(i,2,n[2]){
		getint(x),getint(y);
		v[2][x].pb(y);
		v[2][y].pb(x);
	}
	FOR(i,2,n[3]){
		getint(x),getint(y);
		v[3][x].pb(y);
		v[3][y].pb(x);
	}
	dfs(1,1,0);
	dfs(2,1,0);
	dfs(3,1,0);
	DFS(1,1,0);
	DFS(2,1,0);
	DFS(3,1,0);
	FOR(rp,1,3){
		s[rp]=0;
		FOR(i,1,n[rp]){
			f[rp][i]=d[rp][i]+D[rp][i];
			s[rp]+=f[rp][i];
		}
		s[rp]/=2;
	}
	doit(2,1,3);
	doit(1,2,3);
	doit(1,3,2);
	cout<<ans<<endl;
	return 0;
}