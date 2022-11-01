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
const int maxn=105;
i64 ans[maxn],p,k,a[maxn];
int main(){
	cin>>p>>k;
	int maxi=-1;
	while(p){
		a[++maxi]=p%k;
		p/=k;
	}
	rep(i,0,maxi){
		if((i&1)==0){
			ans[i]+=a[i];
		}else{
			ans[i]+=k-a[i];
			ans[i+1]+=1;
		}
	}
	rep(i,0,maxi){
		while(ans[i]<0){
			ans[i]+=k;
			ans[i+1]+=1;
		}
		while(ans[i]>=k){
			ans[i]-=k;
			ans[i+1]-=1;
		}
	}
	while(ans[maxi+1]){
		maxi++;
		int i=maxi;
		while(ans[i]<0){
			ans[i]+=k;
			// if(i==maxi)maxi++;
			ans[i+1]+=1;
		}
		while(ans[i]>=k){
			ans[i]-=k;
			// if(i==maxi)maxi++;
			ans[i+1]-=1;
		}
	}
	printf("%d\n",maxi+1);
	rep(i,0,maxi)printf("%d ",ans[i]);
	return 0;
}