#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
typedef long long ll;
int Mod;
inline int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%Mod)
		if (y&1) res=1LL*res*x%Mod;
	return res;
}
inline int upd(int x){return x+(x>>31&Mod);}

int n,m,K,ans; char mp[110][110];
int gethash(int x,int y){return (x-1)*m+y;}
int f[11000]; int find(int x){return f[x]?f[x]=find(f[x]):x;}
void merge(int x,int y){
	x=find(x),y=find(y);
	if (x^y) f[y]=x;
}
int a[210][210]; int id[11000],idtot;
int gauss(int n){
	int res=1;
	for (int i=1;i<=n;i++){
		int pos=-1;
		for (int j=i;j<=n;j++) if (a[j][i]){pos=j;break;}
		if (!~pos) return 0;
		if (i^pos){res=upd(-res); for (int j=i;j<=n;j++) swap(a[i][j],a[pos][j]);}
		int t=qpow(a[i][i],Mod-2);
		for (int j=i+1;j<=n;j++){
			if (!a[j][i]) continue;
			int s=1LL*a[j][i]*t%Mod;
			for (int u=i;u<=n;u++) a[j][u]=upd((a[j][u]-1LL*a[i][u]*s)%Mod);
		}
	}
	for (int i=1;i<=n;i++) res=1LL*res*a[i][i]%Mod;
	return res;
}
int main()
{
	n=read()+1,m=read()+1,Mod=read();
	for (int i=1;i<n;i++) scanf("%s",mp[i]+1);
	for (int i=1;i<n;i++)
		for (int j=1;j<m;j++){
			if (mp[i][j]=='/') merge(gethash(i+1,j),gethash(i,j+1));
			else if (mp[i][j]=='\\') merge(gethash(i,j),gethash(i+1,j+1));
			else K++;
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			int x=gethash(i,j);
			if ((i+j)%2==0&&find(x)==x){
				id[x]=++idtot;
			}
		}
	if (idtot-1<=K){
		for (int i=1;i<n;i++)
			for (int j=1;j<m;j++)
				if (mp[i][j]=='*'){
					int x,y;
					if ((i+j)%2==0) x=find(gethash(i,j)),y=find(gethash(i+1,j+1));
					else x=find(gethash(i+1,j)),y=find(gethash(i,j+1));
					x=id[x],y=id[y];
					a[x][y]=upd(a[x][y]-1); a[y][x]=upd(a[y][x]-1);
					a[x][x]=upd(a[x][x]+1-Mod); a[y][y]=upd(a[y][y]+1-Mod);
				}
		ans=gauss(idtot-1);
	}
	memset(a,0,sizeof a); idtot=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			int x=gethash(i,j);
			if ((i+j)%2==1&&find(x)==x){
				id[x]=++idtot;
			}
		}
	if (idtot-1<=K){
		for (int i=1;i<n;i++)
			for (int j=1;j<m;j++){
				if (mp[i][j]=='*'){
					int x,y;
					if ((i+j)%2==1) x=find(gethash(i,j)),y=find(gethash(i+1,j+1));
					else x=find(gethash(i+1,j)),y=find(gethash(i,j+1));
					x=id[x],y=id[y];
					a[x][y]=upd(a[x][y]-1); a[y][x]=upd(a[y][x]-1);
					a[x][x]=upd(a[x][x]+1-Mod); a[y][y]=upd(a[y][y]+1-Mod);
				}
			}
		ans=upd(ans+gauss(idtot-1)-Mod);
	}
	printf("%d\n",ans);
	return 0;
}