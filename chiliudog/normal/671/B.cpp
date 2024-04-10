#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b)
#define w1 first
#define w2 second
typedef pair<int,int> pin;
const int maxn=500005;
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
int n,k;
int a[maxn];
typedef long long i64;
i64 tot=0,sum=0;
int main(){
    read(n);read(k);
    rep(i,1,n)read(a[i]),sum+=a[i];
    if(sum%n==0){
    	i64 v=sum/n;
    	rep(i,1,n)tot+=abs(a[i]-v);
    	tot/=2;
    	if(tot<=k){
    		puts("0");
    		return 0;
    	}
    }else{
    	i64 v=sum/n;
    	rep(i,1,n)if(a[i]<v)tot+=v-a[i];
    	i64 tot2=0;
    	rep(i,1,n)if(a[i]>v+1)tot2+=a[i]-v-1;
    	if(tot<=k&&tot2<=k){
    		puts("1");
    		return 0;
    	}
    }
    int l=0,r=1e9,ansmax=0,ansmin=0;
    while(l<=r){
    	int mid=(l+r)>>1;
    	i64 cnt=0;
    	rep(i,1,n)if(a[i]>=mid)cnt+=a[i]-mid+1;
    	if(cnt>k){
    		ansmax=mid;l=mid+1;
    	}else r=mid-1;
    }
    l=0;r=1e9;
    while(l<=r){
    	int mid=(l+r)>>1;
    	i64 cnt=0;
    	rep(i,1,n)if(a[i]<=mid)cnt+=mid-a[i]+1;
    	if(cnt>k){
    		ansmin=mid;r=mid-1;
    	}else l=mid+1;
    }
    cout<<ansmax-ansmin;
    return 0;
}