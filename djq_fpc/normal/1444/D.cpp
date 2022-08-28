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
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
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
int t,n,m,i,j,a[1005],b[1005],sa,sb,sx[1005],sy[1005];
bitset<1000005> f[1005];
vector<int>a1,a2,b1,b2; 
int main()
{
	read(t);
	while(t--)
	{
		sa=sb=0;a1.clear();a2.clear();b1.clear();b2.clear();
		read(n);fz1(i,n){read(a[i]);sa+=a[i];}
		read(m);fz1(i,m){read(b[i]);sb+=b[i];}
		if(n!=m||sa%2==1||sb%2==1){
			puts("No");continue;
		}
		
		fz0g(i,n) f[i].reset();
		f[0].set(0);
		fz1(i,n){
			f[i]=(f[i-1]|(f[i-1]<<a[i]));
		}
		if(!f[n][sa/2]){
			puts("No");continue;
		}
		int t=sa/2;
		fd1(i,n){
			if(f[i-1][t]){
				a1.push_back(a[i]);
			}
			else{
				a2.push_back(a[i]);
				t-=a[i];
			}
		}
		
		fz0g(i,m) f[i].reset();
		f[0].set(0);
		fz1(i,m){
			f[i]=(f[i-1]|(f[i-1]<<b[i]));
		}
		if(!f[m][sb/2]){
			puts("No");continue;
		}
		t=sb/2;
		fd1(i,m){
			if(f[i-1][t]){
				b1.push_back(b[i]);
			}
			else{
				b2.push_back(b[i]);
				t-=b[i];
			}
		}
		
		sort(a1.begin(),a1.end(),greater<int>());
		sort(a2.begin(),a2.end(),greater<int>());
		sort(b1.begin(),b1.end(),greater<int>());
		sort(b2.begin(),b2.end(),greater<int>());
		if(a1.size()>a2.size()) swap(a1,a2);
		if(b1.size()>b2.size()) swap(b1,b2);
		
		if(a1.size()<=b1.size()){
			sort(b1.begin(),b1.end());
			sort(b2.begin(),b2.end());
		}
		else{
			sort(a1.begin(),a1.end());
			sort(a2.begin(),a2.end());
		}
		t=0;
		ff(a1,it){
			t++;sx[t]=sx[t-1]+*it;
		}
		ff(a2,it){
			t++;sx[t]=sx[t-1]-*it;
		}
		t=0;
		ff(b1,it){
			t++;sy[t]=sy[t-1]+*it;
		}
		ff(b2,it){
			t++;sy[t]=sy[t-1]-*it;
		}
		
		puts("Yes");
		if(a1.size()<=b1.size()){
			fz1(i,n){
				printf("%d %d\n",sx[i-1],sy[i-1]);
				printf("%d %d\n",sx[i],sy[i-1]);
			}
		}
		else{
			fz1(i,n){
				printf("%d %d\n",sx[i-1],sy[i-1]);
				printf("%d %d\n",sx[i-1],sy[i]);
			}
		}
	}
	return 0;
}