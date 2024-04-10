#include<bits/stdc++.h>
#define fortodo(i,a,b) for(int i=(a);i<=(b);i++)
#define fordownto(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int maxn=305;
const int inf=1<<29;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int a[maxn],n,t;
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
int f[maxn*105];
int sum[maxn];
inline int lowbit(int x){
	return x&(-x);
}
inline void add(int x,int v){
	while(x<=301){
		sum[x]=max(sum[x],v);
		x+=lowbit(x);
	}
}
inline int getans(int x){
	int ans=-inf;
	while(x){
		ans=max(ans,sum[x]);
		x-=lowbit(x);
	}
	return ans;
}
int counter[305],tot[305];
int main(){
 //   judge();
	read(n);read(t);
	fortodo(i,1,n)read(a[i]);
	fortodo(i,1,n)counter[a[i]]++;
	int ans=-inf;
	fortodo(i,1,n*300){
		if (i>n*t)break;
		f[i]=getans(a[(i-1)%n+1])+1;
		add(a[(i-1)%n+1],f[i]);
		int step=-inf;
		int place=(i-1)%n+1;int times=t-(i-1)/n-1;
		fortodo(j,1,300)tot[j]=0;
//		fortodo(j,place+1,n)tot[a[j]]++;
		fortodo(j,1,300){
			tot[j]+=counter[j]*times;
			step=max(step,tot[j]);
		}
		ans=max(f[i]+step,ans);
	}
	printf("%d\n",ans);
    return 0;
}