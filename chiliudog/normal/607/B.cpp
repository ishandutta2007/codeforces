#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef vector<int> vin;
typedef vector<i64> v64;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls(x) ((x)<<1)
#define rs(x) (((x)<<1)|1)
#define pb push_back
#define w1 first
#define w2 second
const int maxn=1005;
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
int f[maxn][maxn];
int a[maxn],n;
int main(){
	read(n);rep(i,1,n)read(a[i]);
	rep(len,1,n)rep(i,1,n-len+1){
		int j=i+len-1;
		f[i][j]=j-i+1;
		rep(k,i,j-1)f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
		if(a[i]==a[j])f[i][j]=min(f[i][j],max(1,f[i+1][j-1]));
	//	cerr<<i<<','<<j<<','<<f[i][j]<<endl;
	}cout<<f[1][n];
	return 0;
}