/*
#include<cstdio>
using namespace std;
const int o=5e5+10;
int n,a[o],b[o],c[o];
inline int C(int x,int y){return (x&y)==y;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	for(int i=1;i<=n;++i) for(int k=i;k<=n;++k) if(C(k-1,k-i)) c[k]^=b[i];
	for(int i=1;i<=n;++i) for(int k=1;k<=n;++k) if(k+i-n-1>=0&&C(k-1,k+i-n-1)) a[i]^=c[k];
	for(int i=1;i<=n;++i) printf("%d ",a[i]);
	return 0;
}
*/
#include<cstdio>
#include<iostream>
using namespace std;
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
const int o=1<<19,E=o-1;
inline void FWT(int*a,int len=o)
{for(int md=1;md<len;md<<=1) for(int i=0;i<len;i+=md<<1) for(int j=0;j<md;++j) a[i+j+md]^=a[i+j];}
int n,a[o],b[o],c[o],f[20][o],g[20][o],h[20][o];
inline void mul(){
	for(int i=0;i<20;++i) FWT(f[i]);
	for(int i=0;i<20;++i) for(int j=0;i+j<20;++j) for(int k=0;k<o;++k) h[i+j][k]^=f[i][k]*g[j][k];
	for(int i=0;i<20;++i) FWT(h[i]);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>b[i],f[__builtin_popcount(i-1)][i-1]=b[i];
	for(int i=0;i<=n;++i) g[__builtin_popcount(i)][i]=1;
	for(int i=0;i<20;++i) FWT(g[i]);
	mul();
	for(int i=1;i<=n;++i) c[i]=h[__builtin_popcount(i-1)][i-1];
	for(int i=0;i<20;++i) for(int j=0;j<o;++j) f[i][j]=h[i][j]=0;
	for(int i=1;i<=n;++i) f[__builtin_popcount(E^(i-1))][E^(i-1)]=c[i];
	mul();
	for(int i=1;i<=n;++i) cout<<(a[i]=h[__builtin_popcount(E^(n-i))][E^(n-i)])<<" ";
	return 0;
}