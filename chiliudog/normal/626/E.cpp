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
const int maxn=200005;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int a[maxn],n;
int64 sum[maxn];
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
int ansplace,anslen;
inline long double calc(int place,int len){
	int64 res=sum[n]-sum[n-len]+sum[place]-sum[place-len-1];
	return (long double)res/((len<<1)+1);
}
int main(){
	read(n);rep(i,1,n)read(a[i]);
	sort(a+1,a+1+n);
	rep(i,1,n)sum[i]=sum[i-1]+a[i];
	long double ans=-1;
	rep(i,1,n){
		int l=0,r=i-1;
		while(l+3<r){
			int mid1=(l+r)>>1,mid2=(mid1+r)>>1;
			long double ans1=calc(i,mid1);
			long double ans2=calc(i,mid2);
			if(ans1>ans2)
				r=mid2;
			else 
				l=mid1;
		}
		rep(k,l,r){
			if(calc(i,k)-a[i]>ans){
				ans=calc(i,k)-a[i];ansplace=i;anslen=k;
			}
		}
	}
	printf("%d\n",anslen*2+1);
	rep(i,ansplace-anslen,ansplace)printf("%d ",a[i]);
	rep(i,n-anslen+1,n)printf("%d ",a[i]);
    return 0;
}