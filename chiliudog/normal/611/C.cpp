#include<bits/stdc++.h>
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;
const int maxn=505;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
inline void read(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
int sum[maxn][maxn],n,m;
char s[maxn][maxn];
#define lowbit(x) (x&(-x))
inline void add(int x,int y,int c){
	while(x<=n){
		int k=y;
		while(k<=m){
			sum[x][k]+=c;k+=lowbit(k);
		}x+=lowbit(x);
	}
}
inline int query(int x,int y){
	int ans=0;
	while(x){
		int k=y;
		while(k){
			ans+=sum[x][k];
			k-=lowbit(k);
		}x-=lowbit(x);
	}return ans;
}
int up[maxn][maxn],down[maxn][maxn],l[maxn][maxn],r[maxn][maxn];
int main(){
	read(n);read(m);
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,n)rep(j,1,m){
		if(s[i][j]=='#')continue;int counter=0;
		rep(k,0,3){
			int xx=i+dx[k],yy=j+dy[k];
			if(s[xx][yy]=='.'){
				counter++;
				if(k==0)r[i][j]=1;
				if(k==1)l[i][j]=1;
				if(k==2)down[i][j]=1;
				if(k==3)up[i][j]=1;
			}
		}add(i,j,counter);
	}
	rep(i,1,n)rep(j,1,m){
		r[i][j]+=r[i-1][j];
		l[i][j]+=l[i-1][j];
		down[i][j]+=down[i][j-1];
		up[i][j]+=up[i][j-1];
	}
	int q;read(q);
	while(q--){
		int xl,xr,yl,yr;
		read(xl);read(yl);read(xr);read(yr); 
		int ans=query(xr,yr)-query(xl-1,yr)-query(xr,yl-1)+query(xl-1,yl-1);
		ans-=up[xl][yr]-up[xl][yl-1];
		ans-=down[xr][yr]-down[xr][yl-1];
		ans-=l[xr][yl]-l[xl-1][yl];
		ans-=r[xr][yr]-r[xl-1][yr];
		ans/=2;
		printf("%d\n",ans);
	}
	return 0;
}