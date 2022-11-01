#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4,inf=1e18;
int n,k,w,nl=1,nr,a[N],c[N],f[22][N],cur;
inline void adjust(int l,int r){
	while(nr<r){w+=c[a[++nr]];c[a[nr]]++;}
	while(nr>r){c[a[nr]]--;w-=c[a[nr--]];}
	while(nl<l){c[a[nl]]--;w-=c[a[nl++]];}
	while(nl>l){w+=c[a[--nl]];c[a[nl]]++;}
}
void solve(int l,int r,int al,int ar){
	if(l>r||al>ar)return;
	int mid=l+r>>1,p=0,mn=inf;
	for(int i=min(mid-1,ar);i>=al;i--){
		adjust(i+1,mid);
		if(f[cur-1][i]+w<mn){mn=f[cur-1][i]+w;p=i;}
	}
	f[cur][mid]=mn;
	solve(l,mid-1,al,p);solve(mid+1,r,p,ar);
}
signed main(){
	n=read();k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(cur=1;cur<=k;cur++)solve(1,n,0,n-1);
	cout<<f[k][n];
	return (0-0);
}