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
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
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
int n,m,i,j/*,c[1505][1505],px[1000005],py[1000005],cc*/;
void print(int x,int y)
{
//	c[x][y]=1;//!!!!!!!!!!
	printf("%d %d\n",x,y);
//	cc++;px[cc]=x;py[cc]=y;
}
int main()
{
	read(n);
	m=1;while((n-m)*2-1>m) m++;
	printf("%d\n",m);
	int t=0;//while((n-t-m)*m-1<=m) t++;
	if(m&1){
		print(1,1);
		fz1(i,m/2){
			print(i+1,i*2+1);
		}
		fz1(i,m/2){
			print(m/2+1+i,i*2);
		}
	}
	else{
		print(1,1);
		print(2,2);
		fz1(i,m/2-1){
			print(i+2,i*2+2);
		}
		fz1(i,m/2-1){
			print(m/2+1+i,i*2+1);
		}
	}
/*	assert(cc==m);
	fz1(i,n){
		fz1(j,n){
			cout<<c[i][j];
		}
		cout<<endl;
	}
	fz1(i,n){
		fz1(j,n){
			int k;
			fz1(k,m){
				if(px[k]==i||py[k]==j||px[k]-py[k]==i-j) break;
			}
			if(k>m) cerr<<i<<' '<<j,assert(0);
		}
	}*/
	return 0;
}