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
#include<bitset>
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
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define rdst(st,len){static char ss[len];scanf("%s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,a[1000005],b[1000005],c[1000005],f[1000005],blk,k,d;
string st,ans;
void print()
{
	int i;
	fz1(i,n){
		ans[i-1]=st[f[i]-1];
	}
	st=ans;
	puts(ans.c_str());
}
void fence(int *a,int s,int k,int d)
{
	int i,j,cnt=0;
	fz0k(i,d){
		for(j=s+i;j<s+k;j+=d){
			c[cnt++]=a[j];
		}
	}
	fz0k(i,cnt) a[s+i]=c[i];
}
void change(int *a,int *b,int s,int len)
{
	int i;
	fz1(i,len){
		c[i]=a[b[i]+s-1];
	}
	fz1(i,len){
		a[i+s-1]=c[i];
	}
}
void solve()
{
	int i,j;blk=sqrt(n)+1;
	fz1(i,n) a[i]=i;
	fz1(i,n) b[i]=i;
	fz1(i,n) f[i]=i;
	fence(b,1,k,d);
	memcpy(a,b,sizeof(a[0])*(n+1));
	int t=n-k+1,lst=1;
	for(i=0;(1<<i)<=t;i++){
		if((t>>i)&1){
			change(f,b,lst,(1<<i)+k-1);
			lst+=(1<<i);
		}
		if((1<<(i+1))<=t){
			change(a,b,(1<<i)+1,(1<<i)+k-1);
			memcpy(b,a,sizeof(a[0])*(n+1));
		}
	}
	print();
}
int main()
{
	rdst(st,1000005)
	ans=st;n=st.size();
	read(m);
	while(m--){
		read(k);read(d);
		solve();
	}
	return 0;
}