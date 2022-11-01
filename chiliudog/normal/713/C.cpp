#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
#define dg(...) fprintf(stderr,__VA_ARGS__);
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
/*******************************head*******************************/
const int maxn=3005;
int a[maxn],n,h[maxn],trans[maxn];
i64 f[maxn][maxn],mini[maxn][maxn];
map<int,int> zball;
int main(){
	read(n);
	rep(i,1,n)read(a[i]);
	rep(i,1,n)a[i]-=i;
	rep(i,1,n)h[i]=a[i];
	sort(h+1,h+1+n);int cnt=0;
	rep(i,1,n){
		int j=i;
		while(j<n&&h[j+1]==h[j])j++;
		zball[h[i]]=++cnt;trans[cnt]=h[i];i=j;
	}rep(i,1,n)a[i]=zball[a[i]];
	rep(i,1,n){
		mini[i-1][1]=f[i-1][1];
		rep(j,2,cnt)mini[i-1][j]=min(mini[i-1][j-1],f[i-1][j]);
		rep(j,1,cnt){
			f[i][j]=mini[i-1][j]+abs(trans[a[i]]-trans[j]);
		}
	}
	i64 ans=1ll<<60;
	rep(i,1,cnt)ans=min(ans,f[n][i]);
	cout<<ans;
	return 0;
}