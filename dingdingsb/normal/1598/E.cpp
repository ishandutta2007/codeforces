// Problem: E. Staircases
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.ml/contest/1598/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=1e3+100;
int n,m,q;bool flag[N][N];
int f1[N][N],f2[N][N];int ans;int cnt;
void upd1(int x,int y){
	if(x<1||x>n||y<1||y>m)return;
	ans-=f1[x][y];
	f1[x][y]=0;
	if(!flag[x][y] && !flag[x][y+1]){
		f1[x][y]=1;
		if(!flag[x+1][y+1])f1[x][y]++;
		f1[x][y]+=f1[x+1][y+1];
	}
	ans+=f1[x][y];
}
void upd2(int x,int y){
	if(x<1||x>n||y<1||y>m)return;
	ans-=f2[x][y];
	f2[x][y]=0;
	if(!flag[x][y] && !flag[x+1][y]){
		f2[x][y]=1;
		if(!flag[x+1][y+1])f2[x][y]++;
		f2[x][y]+=f2[x+1][y+1];
	}
	ans+=f2[x][y];
}
signed main(){
	read(n,m,q);
	for(int i=0;i<=n+1;i++)flag[i][0]=flag[i][m+1]=1;
	for(int i=0;i<=m+1;i++)flag[0][i]=flag[n+1][i]=1;
	for(int i=n;i;i--)
		for(int j=m;j;j--)
			upd1(i,j),upd2(i,j);
	while(q--){
		int x,y;read(x,y);
		int xx,yy;
		cnt-=flag[x][y];
		flag[x][y]^=1;
		cnt+=flag[x][y];
		xx=x,yy=y;
		while(xx+1>=1&&yy+1>=1){
			upd1(xx+1,yy);upd2(xx+1,yy);
			upd1(xx,yy);upd2(xx,yy);
			upd1(xx-1,yy);upd2(xx-1,yy);
			xx--,yy--;
		}
		write(ans+n*m-cnt);putchar('\n');
	}
}