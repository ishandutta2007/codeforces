#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);++(i))
#define fd1(i,n) for ((i)=(n);(i)>=1;--(i))
#define fz0g(i,n) for ((i)=0;(i)<=(n);++(i))
#define fd0g(i,n) for ((i)=(n);(i)>=0;--(i))
#define fz0k(i,n) for ((i)=0;(i)<(n);++(i))
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;--(i))
#define fz(i,x,y) for ((i)=(x);(i)<=(y);++(i))
#define fd(i,y,x) for ((i)=(y);(i)>=(x);--(i))
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
int n,w1,w2,w3,w4,tot,m,i,j,k,a[7855][7855],id1[105][105],f[7855],cnt,mod=1e9+7;
void inc(int &x,int y)
{
	x+=y;if(x>=mod)x-=mod;
}
void dec(int &x,int y)
{
	x-=y;if(x<0)x+=mod;
}
int qp(int x,int y)
{
	int z=1;
	while(y){
		if(y&1)z=1ll*z*x%mod;
		x=1ll*x*x%mod;y/=2;
	}return z;
}
int id(int x,int y)
{
	if(x*x+y*y>n*n)return cnt;
	return id1[x+n][y+n];
}
int main()
{
	scanf("%d%d%d%d%d",&n,&w1,&w2,&w3,&w4);
	tot=(0ll+w1+w2+w3+w4)%mod;
	w1=1ll*qp(tot,mod-2)*w1%mod;
	w2=1ll*qp(tot,mod-2)*w2%mod;
	w3=1ll*qp(tot,mod-2)*w3%mod;
	w4=1ll*qp(tot,mod-2)*w4%mod;
	for(i=-n;i<=n;i++){
		for(j=-n;j<=n;j++)if(i*i+j*j<=n*n){
			id1[i+n][j+n]=++cnt;
		}
	}
	cnt++;
	for(i=-n;i<=n;i++){
		for(j=-n;j<=n;j++)if(i*i+j*j<=n*n){
			a[id(i,j)][id(i,j)]=a[id(i,j)][cnt+1]=1;
			dec(a[id(i,j)][id(i-1,j)],w1);
			dec(a[id(i,j)][id(i,j-1)],w2);
			dec(a[id(i,j)][id(i+1,j)],w3);
			dec(a[id(i,j)][id(i,j+1)],w4);
		}
	}
	a[cnt][cnt]=1;
	fz1(i,cnt){
		fz(j,i+1,cnt)if(a[j][i]){
			int t=1ll*(mod-a[j][i])*qp(a[i][i],mod-2)%mod;
			fz(k,i,min(cnt,i+n+n+2)){
				a[j][k]=(a[j][k]+1ll*t*a[i][k])%mod;
			}
			fz(k,cnt+1,cnt+1){
				a[j][k]=(a[j][k]+1ll*t*a[i][k])%mod;
			}
		}
	}
	fd1(i,cnt){
		fz(j,i+1,cnt){
			dec(a[i][cnt+1],1ll*f[j]*a[i][j]%mod);
		}
		f[i]=1ll*a[i][cnt+1]*qp(a[i][i],mod-2)%mod;
	}
	cout<<f[id(0,0)]<<endl;
	return 0;
}