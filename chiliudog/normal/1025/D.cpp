#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<cassert>
#include<queue>
#include<cmath>
#include<queue>
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
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
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
inline int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
const int maxn=705;
int n,a[maxn],pr[maxn][maxn];
bool Left[maxn][maxn],Right[maxn][maxn];
int main(){
	read(n);rep(i,1,n)read(a[i]);
	rep(i,1,n)rep(j,1,n)pr[i][j]=gcd(a[i],a[j]);
	rep(i,1,n)Left[i][i]=Right[i][i]=1;
	bool ans=0;
	rep(len,1,n){
		rep(l,1,n-len+1){
			int r=l+len-1;
			rep(x,l,r){
				bool flag=Left[l][x]&&Right[x][r];
				if(!flag)continue;
				if(l==1&&r==n)ans=1;
				if(pr[x][r+1]>1)Left[l][r+1]=1;
				if(pr[x][l-1]>1)Right[l-1][r]=1;
			}
		}
	}
	puts(ans?"Yes":"No");
	return 0;
}