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
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,t,ta,tb,tc;
string a,b,c;
void solve(string s,string t,char c)
{
	int i=0,j=0,k;
	fz1(k,n){
		while(s[i]!=c){
			putchar(s[i]);
			i++;
		}
		while(t[j]!=c){
			putchar(t[j]);
			j++;
		}
		putchar(c);
		i++;j++;
	}
	while(i<n+n){
		putchar(s[i]);
		i++;
	}
	while(j<n+n){
		putchar(t[j]);
		j++;
	}
	puts("");
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		cin>>a>>b>>c;
		ta=tb=tc=0;
		fz0k(i,n+n) ta+=(a[i]=='1');
		fz0k(i,n+n) tb+=(b[i]=='1');
		fz0k(i,n+n) tc+=(c[i]=='1');
		ta=(ta>=n);
		tb=(tb>=n);
		tc=(tc>=n);
		if(ta&&tb){
			solve(a,b,'1');
			continue;
		}
		if(ta&&tc){
			solve(a,c,'1');
			continue;
		}
		if(tb&&tc){
			solve(b,c,'1');
			continue;
		}
		if(!ta&&!tb){
			solve(a,b,'0');
			continue;
		}
		if(!ta&&!tc){
			solve(a,c,'0');
			continue;
		}
		if(!tb&&!tc){
			solve(b,c,'0');
			continue;
		}
	}
	return 0;
}