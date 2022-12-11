#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#define pb push_back
#define forall(x,i) for (int i=0;i<x.size();i++)
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
typedef long long ll;
void print(ll x){
	if (x>9) print(x/10); putchar((x%10)^48);
}
#undef G

int n,m;
struct Rec{
	char o; int x,y;
}rec[500010];
int f[1000010],g[1000010]; ll h[1000010];
int siz[1000010];
int idtot;  //init
int find(int x,int &G,ll &H){
	if (!f[x]) return x;
	f[x]=find(f[x],G,H);
	G=max(G,g[x]); H+=h[x];
	g[x]=G,h[x]=H;
	return f[x];
}
vector<int> bin[500010];
ll ans[500010];
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("A.out","w",stdout);

	n=read(),m=read(); idtot=n;
	for (int i=1;i<=m;i++){
		char &o=rec[i].o;
		int &x=rec[i].x,&y=rec[i].y;
		scanf("%c",&o);
		x=read(); if (o=='U'||o=='M') y=read();
	}
	for (int i=1;i<=m;i++){
		char o=rec[i].o;
		int x=rec[i].x,y=rec[i].y;
		if (o=='M'){
			int G=0; ll H=0;
			x=find(x,G,H);
			G=H=0;
			y=find(y,G,H);
			if (x==y) continue;
			++idtot;
			f[y]=f[x]=idtot;
			continue;
		}
		if (o=='Z'){
			int G=0; ll H=0;
			x=find(x,G,H);
			g[x]=i;
			continue;
		}
		if (o=='Q'){
			int G=0; ll H=0;
			x=find(x,G,H);
			G=max(G,g[x]);
			if (G) bin[G].pb(i);
			continue;
		}
	}
	for (int i=1;i<=idtot;i++) f[i]=0; idtot=n;
	for (int i=1;i<=n;i++) siz[i]=1;
	for (int i=1;i<=m;i++){
		char o=rec[i].o;
		int x=rec[i].x,y=rec[i].y;
		if (o=='U'){
			int G=0; ll H=0;
			x=find(x,G,H);
			G=H=0;
			y=find(y,G,H);
			if (x==y) continue;
			++idtot;
			f[y]=f[x]=idtot;
			siz[idtot]=siz[x]+siz[y];
			continue;
		}
		if (o=='A'){
			int G=0; ll H=0;
			x=find(x,G,H);
			h[x]+=siz[x];
			continue;
		}
		if (o=='Z'){
			forall(bin[i],j){
				int p=bin[i][j];
				x=rec[p].x;
				int G=0; ll H=0;
				y=find(x,G,H);
				H+=h[y];
				ans[p]-=H;
			}
			continue;
		}
		if (o=='Q'){
			int G=0; ll H=0;
			y=find(x,G,H);
			H+=h[y];
			print(ans[i]+H); putchar('\n');
			continue;
		}
	}
	return 0;
}