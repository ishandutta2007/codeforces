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
const int maxn=100005;
int a[maxn],n,mini;
int sum[20][maxn*10];
inline int querysum(int k,int l,int r){
	if(l<=r){
		if(l==0)return sum[k][r];
		else return sum[k][r]-sum[k][l-1];
	}else{
		int v=sum[k][r]+sum[k][(1<<k)-1]-(l?sum[k][l-1]:0);
		return v;
	}
}
int main(){
	read(n);
	rep(i,1,n)read(a[i]),mini=min(mini,a[i]);
	a[++n]=0;
	rep(i,1,n)a[i]-=mini;
	rep(j,0,19){
		int res=1<<j;
		rep(i,1,n)sum[j][a[i]%res]++;
		rep(i,1,res-1)sum[j][i]+=sum[j][i-1];
	}int ans=20;vector<int> op;
	rep(T,0,(1<<19)){
		int res=0;vector<int> cur;
		rep(j,1,19){
			int v=1<<j;
			int tmp=(T%v);
			int l=((1<<(j-1))-tmp+v)%v,r=(v-1-tmp+v)%v;
			if(querysum(j,l,r)){
				res++;
				cur.pb(1<<(j-1));
			}
		}
		for(int &v:cur){
			if((T-mini)&v)v=-v;
		}
		if(res<ans)ans=res,op=cur;
	}
	cout<<ans<<endl;
	for(int v:op){
		printf("%d ",v);
	}
	return 0;
}