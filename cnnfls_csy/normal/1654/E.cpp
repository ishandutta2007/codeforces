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
const int blk=100;//50!!!!!!!!!!!!!!!!!!!!!
const long long big=190000000ll;
const int bse=15000;
int n,m,i,j,k,ans,a[100005],c[100005];
int b[100005],d[100005];
int main()
{
	read(n);fz1(i,n)read(a[i]);
	//fz1(i,n)a[i]=(rand()*5ll+rand())%100000+1;
	ans=min(2,n);
	fz1(i,n){
		fz(j,i+1,min(n,i+blk)){
			if((a[j]-a[i])%(j-i)!=0) continue;
			int cur=2;
			fz(k,j+1,min(n,i+blk)){
				if(1ll*(a[k]-a[i])*(j-i)==1ll*(a[j]-a[i])*(k-i)){
					cur++;
				}
			}
			ans=max(ans,cur);
		}
	}
	fz0g(i,100000){
		if(i==62){
			int a;
			a++;
		}
//		if(i%100==0) cerr<<i<<endl;
		if(i*(blk-2)>100000) break;
		fz1(j,n) b[j]=a[j]-1ll*i*j+big;
		fz0k(j,bse) c[j]=0;
		fz1(j,n) c[b[j]%bse]++;
		fz1(j,bse-1) c[j]+=c[j-1];
		fd1(j,n) d[c[b[j]%bse]--]=b[j];
		fz0k(j,bse) c[j]=0;
		fz1(j,n) c[d[j]/bse]++;
		fz1(j,bse-1) c[j]+=c[j-1];
		fd1(j,n) b[c[d[j]/bse]--]=d[j];
		int cur=0;
		fz1(j,n){
			if(j==1||b[j]==b[j-1]) cur++;
			else cur=1;
			ans=max(ans,cur);
		}
		fz1(j,n) b[j]=a[j]+1ll*i*j;
		fz0k(j,bse) c[j]=0;
		fz1(j,n) c[b[j]%bse]++;
		fz1(j,bse-1) c[j]+=c[j-1];
		fd1(j,n) d[c[b[j]%bse]--]=b[j];
		fz0k(j,bse) c[j]=0;
		fz1(j,n) c[d[j]/bse]++;
		fz1(j,bse-1) c[j]+=c[j-1];
		fd1(j,n) b[c[d[j]/bse]--]=d[j];
		cur=0;
		fz1(j,n){
			if(j==1||b[j]==b[j-1]) cur++;
			else cur=1;
			ans=max(ans,cur);
		}
	}
	printf("%d\n",n-ans);
	return 0;
}