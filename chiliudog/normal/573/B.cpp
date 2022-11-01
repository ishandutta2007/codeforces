#include<bits/stdc++.h>
#define fortodo(i,a,b) for(int i=(a);i<=(b);i++)
#define fordownto(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int maxn=100005;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int n,a[maxn],f[maxn],g[maxn];
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}

int main(){
 //   judge();
	read(n);fortodo(i,1,n) read(a[i]);f[1]=1;g[n]=1;
	fortodo(i,2,n) f[i]=min(f[i-1]+1,min(a[i],a[i-1]+1));
	fordownto(i,n-1,1) g[i]=min(g[i+1]+1,min(a[i],a[i+1]+1));
	int ans=0;
	fortodo(i,1,n) ans=max(ans,min(f[i],g[i]));
	cout<<ans;
    return 0;
}