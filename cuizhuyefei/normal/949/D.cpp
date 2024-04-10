#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
inline void read(int &x){
	x=0;char c=getchar();while(!isdigit(c))c=getchar();
	while(isdigit(c)){x=10*x+c-'0';c=getchar();}
}
const int N = 233333;
int n,d,b,a[N],c[N];ll v[N];
inline void add(int p,ll val){while(p<=n)v[p]+=val,p+=p&-p;}
inline ll query(int p){ll res=0;while(p)res+=v[p],p-=p&-p;return res;}
inline bool ck(ll l, ll r){return query((int)min(r,n*1LL))-(l<=0?0:query(l-1))>=b;}
inline bool judge(int mid){
	rep(i,1,n)a[i]=c[i];memset(v,0,sizeof(v));
	rep(i,1,n)add(i,a[i]);int p=1,x1=(n+1)/2-mid,x2=n-(n+1)/2-mid;
	rep(i,1,n)if(ck(i-1LL*d*min(i,n-i+1),i+1LL*d*min(i,n-i+1))){
		if(i<=(n+1)/2&&x1<=0||i>(n+1)/2&&x2<=0)continue;
		int L=i-1LL*d*min(i,n-i+1),lst=b;
		while(p<=n&&p<L)p++;
		while(p<=n&&lst){
			int del=min(a[p],lst);add(p,-del);a[p]-=del;lst-=del;
			if(!a[p])p++;
		}
		if(i<=(n+1)/2)x1--;else x2--;
	}
	return !x1&&!x2;
}
int main(){
	read(n);read(d);read(b);rep(i,1,n)read(c[i]);
	int L=0,R=n/2+1,res=R;
	while(L<=R){
		int mid=(L+R)>>1;
		if(judge(mid))res=mid,R=mid-1;else L=mid+1;
	}
	printf("%d",res);
	return 0;
}