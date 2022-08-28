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
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf("%s",ss);(st)=ss;}
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
int t,n,m,i,j,k,a[1005][1005],ans[1005][1005],b[1005],c[1005],p[3],d[3],s[3],q[3];
string st;
void inc(int x)
{
	d[x]++;
}
void dec(int x)
{
	d[x]--;
}
void swp(int x,int y)
{
	swap(d[x],d[y]);
	int i,j;
	fz0k(i,3)if(p[i]==x)break;
	fz0k(j,3)if(p[j]==y)break;
	swap(p[i],p[j]);
}
void print()
{
	int i,j;
//	q[p[0]]=0;q[p[1]]=1;q[p[2]]=2;
	fz1(i,n)fz1(j,n){
		s[p[0]]=i;s[p[1]]=j;s[p[2]]=a[i][j];
		fz0k(k,3){
			s[k]+=d[k];
			s[k]%=n;
			while(s[k]<=0)s[k]+=n;
		}
		ans[s[0]][s[1]]=s[2];
	}
	fz1(i,n)fz1(j,n)printf("%d%c",ans[i][j],spln(j,n));
}
int main()
{
	read(t);
	while(t--)
	{
		read(n);read(m);fz1(i,n)fz1(j,n)read(a[i][j]);
		rdst(st,100005)
		fz0k(i,3){
			p[i]=i;
			d[i]=0;
		}
		fz0k(i,m){
			if(st[i]=='U'){
				dec(0);
			}
			if(st[i]=='D'){
				inc(0);
			}
			if(st[i]=='L'){
				dec(1);
			}
			if(st[i]=='R'){
				inc(1);
			}
			if(st[i]=='I'){
				swp(1,2);
			}
			if(st[i]=='C'){
				swp(0,2);
			}
//			print();
//			cerr<<endl;
		}
		print(); 
	}
	return 0;
}