#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b);
#define w1 first
#define w2 second
typedef pair<int,int> pin;
const int maxn=1025;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
int ans[maxn][maxn];
inline void get(int x){
	if(x==0){
		ans[1][1]=1;return;
	}
	get(x-1);
	int n=1<<(x-1);
	rep(i,1,n)rep(j,n+1,n<<1)ans[i][j]=ans[i][j-n];
	rep(i,n+1,n<<1)rep(j,1,n)ans[i][j]=ans[i-n][j];
	rep(i,n+1,n<<1)rep(j,n+1,n<<1)ans[i][j]=-ans[i][j-n];
}
int main(){
	int k;read(k);
	get(k);
	rep(i,1,(1<<k)){
		rep(j,1,(1<<k))
			if(ans[i][j]==1)
				putchar('+');
			else
				putchar('*');
		puts("");
	}
    return 0;
}