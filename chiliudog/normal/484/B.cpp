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
const int maxn=200005;
int a[maxn],n;
int sum[maxn];
inline int erfen(int v){
	int l=1,r=n+1,ans=0;
	while(l<=r){
		int md=(l+r)>>1;
		if(a[md]>=v){
			ans=md;r=md-1;
		}else{
			l=md+1;
		}
	}return ans;
}
int main(){
    // judge();
	read(n);rep(i,1,n)read(a[i]);
	sort(a+1,a+1+n);a[n+1]=1<<29;
	int ans=0;
	rep(i,1,n){
		int j=i;
		while(j<n&&a[j+1]==a[i])j++;int lplace=i;
		for(int v=a[i];v<=1000000;v+=a[i]){
			// int lplace=erfen(v);
			int rplace=erfen(v+a[i]);
			if(lplace<rplace)ans=max(ans,a[rplace-1]%a[i]);
			lplace=rplace;
		}i=j;
	}cout<<ans;
	return 0;
}