#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b)
#define w1 first
#define w2 second
typedef pair<int,int> pin;
const int maxn=505,maxm=505*505;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int du[maxn],n,m,num,head[maxn],t[maxm<<1],ne[maxm<<1];
char ans[maxn];
bool a[maxn][maxn];
int c[maxn],cnt,Queue[maxn],front,finish;
inline void addedge(int x,int y){
	ne[++num]=head[x];head[x]=num;t[num]=y;
	ne[++num]=head[y];head[y]=num;t[num]=x;
}
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}

int main(){
 //   judge();
	read(n);read(m);rep(i,1,n)head[i]=-1;
	rep(i,1,m){
		int x,y;read(x);read(y);a[x][y]=1;a[y][x]=1;addedge(x,y);du[x]++;du[y]++;
	}
	rep(i,1,n){
		if(du[i]==n-1){
			ans[i]='b';continue;
		}
		c[++cnt]=i;
	}
	if(cnt==0){
		puts("Yes");
		puts(ans+1);return 0;
	}
	int x=c[1];ans[x]='a';
	rep(i,1,n)if(i!=x){
		if(du[i]==n-1)continue;
		if(a[x][i])ans[i]='a';else ans[i]='c';
	}
	rep(i,1,n)rep(j,1,n)if(i!=j){
		if(a[i][j]){
			if(abs(ans[i]-ans[j])<=1)continue;
			puts("No");return 0;
		}
		if(abs(ans[i]-ans[j])<=1){
			puts("No");return 0;
		}
	}
	puts("Yes");puts(ans+1);
    return 0;
}