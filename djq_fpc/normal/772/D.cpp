#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
using namespace std;
int n,m,i,j,a[1000005],b[1000005],c[1000005],f[1000005],pw[1000005],mod=1e9+7;
long long ans;
int main()
{
	scanf("%d",&n);
	pw[0]=1;
	fz1(i,n){
		pw[i]=2ll*pw[i-1]%mod;
	}
	while(n--){
		int x;
		scanf("%d",&x);
		a[x]++;
		b[x]=(b[x]+x)%mod;
		c[x]=(c[x]+1ll*x*x)%mod;
	}
	for(i=1;i<1000000;i*=10){
		for(j=999999;j>=0;j--){
			if(j%(i*10)/i!=0){
				(a[j-i]+=a[j])%=mod;
				(b[j-i]+=b[j])%=mod;
				(c[j-i]+=c[j])%=mod;
			}
		}
	}
	for(i=0;i<1000000;i++){
		if(a[i]==0) continue;
		if(a[i]==1){
			f[i]=c[i];
			continue;
		}
		f[i]=1ll*pw[a[i]-2]*((1ll*b[i]*b[i]+c[i])%mod)%mod;
	}
	for(i=1;i<1000000;i*=10){
		for(j=0;j<1000000;j++){
			if(j%(i*10)/i!=0){
				(f[j-i]+=mod-f[j])%=mod;
			}
		}
	}
	for(i=1;i<1000000;i++){
		ans^=1ll*i*f[i];
	}
	cout<<ans<<endl;
	return 0;
}